/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for EEPROM
 *
 * As long the test runs successfully, the test is non-destructive and
 * will restore origin flash content. It tries to work on area after
 * the campos hwData-structures.
 * The hwData-structures can still be destroyed when adress width does
 * not match to the device.
 *
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/

#define LEPTO_LOG_DEBUG 1

#include <bringup/tests/biwak/eeprom.hpp>
#include <biwak/flash.h>
#include <lepto/print.h>


/*--- Implementation -------------------------------------------------------*/


int CTestI2cEeprom::run( )
{
   int sta=0;
   int startAddress = m_eeprom.getStartAddress() + 0x40; // Try not to destroy HwData
   constexpr int testAreaSize = 0x40;
   uint8_t origin[ testAreaSize ];
   static const uint8_t _new[]{
   /* 0x00 */   0x1d, 0xda, 0xb8, 0xf4, 0xcc, 0x3d, 0x60, 0x1f,  0xc5, 0xc8, 0xfb, 0x02, 0x11, 0x2a, 0x8a, 0x5a,
   /* 0x10 */   0x3f, 0xe6, 0x35, 0xf2, 0xea, 0x08, 0x9d, 0x64,  0x49, 0xe8, 0xe7, 0x87, 0xb5, 0xd9, 0x94, 0xe6,
   /* 0x20 */   0x3c, 0xfc, 0xed, 0xad, 0x2a, 0xd1, 0xc2, 0x77,  0x87, 0x0f, 0x8e, 0x54, 0x85, 0xc7, 0x42, 0x9b,
   /* 0x30 */   0x09, 0x66, 0xf7, 0x91, 0x23, 0x65, 0xa9, 0x5f,  0x1e, 0xd1, 0x5b, 0x74, 0x81, 0x33, 0xc1, 0xf9,
   };
   uint8_t readback[ testAreaSize ];
   //int crossSum=0;
   int comp;

   int pageSize=m_eeprom.writePageSize();

   if( pageSize <=1 )
   {
      // No write page size; assuming 8
      pageSize=8;
   }

   if( pageSize >=0x20 )
   {
      printf("Page size too high; not implemented\n");
      return( -1 );
   }

   if( testAreaSize > sizeof(_new) )
   {
      printf("Random data too small\n");
      return( -1 );
   }

   // Read original data to restore it
   sta=m_eeprom.readData( startAddress, &origin, testAreaSize);
   testAssert("read", sta==0, sta);
   
   // Dont sleep; its not our job, CI2Flash has to take care about this

   // Write some dummy pattern, so following tests will not accidently succeed
   //
   sta=0;
   m_eeprom.erasePage(0, testAreaSize);
   for(int i1=0; i1<testAreaSize; i1++)
   {
      char dataOut=~i1;
      char dataIn=0;
      int lsta;
      if( ( lsta=m_eeprom.writeData( startAddress + i1, &dataOut, 1) ) )
      {
         lCritical("Write: 0x%X", lsta);
         sta++;
      }
      if( ( lsta=m_eeprom.readData( startAddress + i1, &dataIn, 1) ) )
      {
         lCritical("Read: 0x%X", lsta);
         sta++;
      }
      
      if( dataIn != dataOut )
      {
         lDebug("BU:In 0x%X vs. 0x%X", dataIn, dataOut);
         logEventLoop();
         sta++;
      }
   }
   testAssert("zero ", sta==0, sta);

   /* Testing writing blocks crossing page boundaries. This has to be catched.
    *
    *    [   Page n     ] [   Page n+1   ] [   Page n+2   ]
    *    [ Write 1 ][ Write 0 ][ Write 2 ]
    */
   m_eeprom.erasePage( startAddress, testAreaSize );
   sta=m_eeprom.writeData( startAddress + (pageSize/2)
                               , &_new[(pageSize/2)], pageSize );

   sta+=m_eeprom.writeData( startAddress
                               , &_new[0], pageSize/2);

   sta+=m_eeprom.writeData( startAddress + (pageSize/2) + pageSize
                               , &_new[(pageSize/2)+ pageSize], pageSize/2);
   sta=testAssert("write", (sta==0), sta);

   sta=m_eeprom.readData( startAddress, &readback, sizeof(readback));
   sta=testAssert("read 1", (sta==0), sta);

   // Not all "testAreaSize" may be written.
   comp=memcmp(_new, readback, pageSize * 2 );
   if( ( sta=testAssert("comp", (comp==0), comp) ) )
   {
      printf( "Written:\n" );
      hexDump(_new, pageSize * 2);
      printf( "Readback:\n" );
      hexDump(readback, pageSize * 2);
   }

   sta=m_eeprom.writeData( startAddress, &origin, testAreaSize );
   sta=testAssert("write 2", (sta==0), sta);
   
   // Data at 0x0 is not the same as on 0x80; only valid test for
   // 128Byte EEPROMs

   //sta=testAssert("rw (value@0)", (readBack2!=_new), readBack2, EResult::warning);

   return(sta);
}


/*--- Fin ------------------------------------------------------------------*/
