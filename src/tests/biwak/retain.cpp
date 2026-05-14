/**---------------------------------------------------------------------------
 *
 * @brief  Retain data
 * 
 * Warning: The test destroys existing data
 * 
 * Write retain data and expect it to be restored.
 * 
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/tests/biwak/retain.hpp>
#include <biwak/sd.hpp>
#include <hwinfo/hwinfo.h>


/*--- Implementation -------------------------------------------------------*/


void CTestRetain::run( )
{
   int sta=0, container;
   static char data[0x80];

   struct SEepromHwData
   {
      SEepromBoardInfo boardInfo;
      char reserved[ 0x40 - 0xC - sizeof(SEepromBoardInfo) ];
   } __attribute ((packed));

   struct SEepromConfig
   {
      char reserved[ 0x20 - 0xC ];
   } __attribute ((packed));

   static SEepromHwData data1;
   static SEepromConfig data2;

   // Destroy exyisting retain data in order not to fool myself
   memset(&data, 0x0, 0x40);
   sta=m_pI2cFlash.writeData(0x40, &data, 0x40);
   testAssert("write", sta==0, sta);

   /*
   memset(&data, 0xEE, 0x80);
   sta=m_pI2cFlash.readData(0x0, &data, 0x80);
   testAssert("read", sta==0, sta);
   hexDump( &data, 0x80);
   */

   m_pRetain1=new CRetain( m_pI2cFlash, 0, 1);
   m_pRetain2=new CRetain( m_pI2cFlash, 0, 2);
   m_pRetain1->setData( &data1, sizeof(data1), 3, 4);
   m_pRetain2->setData( &data2, sizeof(data2), 5, 6);

   // First container may contain production data: try not to destruct that
   //container = m_pRetain1->store();

   //SEepromHwData *hwData=(SEepromHwData *)m_data;
   data2.reserved[0]=0xAA;
   container = m_pRetain2->store();
   //lInfo("Data size store: %d", m_pRetain2->getSize() );

   testAssert( "Store", container >= 0, container );

#if 0
#if ! defined( NDEBUG )
   sta=m_pI2cFlash.readData(0x0, &data, 0x80);
   sta2=testAssert( "Read", sta == 0, sta );
   printf("Dump after storing retain:\n");
   hexDump( &data, 0x80);
#endif
#endif

#if 1
   data2.reserved[0]=0xEE;
   container = m_pRetain2->restore();
   testAssert( "Restore", container >= 0, container );
   printf("Res Cont: 0x%X", container);

   biwakEventLoop();
   //lInfo("Data size restore: %d", m_pRetain2->getSize() );

   testAssert( "Data", data2.reserved[0]==0xAA, data2.reserved[0] );

   #if 0
   hexDump( &data2, sizeof(data2));
   #endif

#endif

   return;
}


/*--- Fin ------------------------------------------------------------------*/
