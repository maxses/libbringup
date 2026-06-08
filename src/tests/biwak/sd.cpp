/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for SD-Card
 *
 * Write som patterns and read them back.
 *
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/tests/biwak/sd.hpp>
#include <biwak/sd.hpp>


/*--- Declaration ----------------------------------------------------------*/


#if !defined (STM32F0) && !defined (STM32F3)

void CTestSd::run()
{
   typedef uint8_t sector[0x200];
   uint8_t masks[]={ 0xAA, 0x55, 0x12, 0x34, 0x56, 0x00, 0xff, 0x89, 0xab
                              , 0xcd, 0xef, 0x11, 0x77, 0x88};
   sector w[ sizeof(masks) ];
   sector r[ sizeof(masks) ];
   sector d;
   int err=0;
   int loops=0x40;

   logEventLoop();

   // Problems can start with loop 40
   for(int i2=0; i2<loops; i2++)
   {
      fputs("-", stdout);
   }
   fputs("\r", stdout);

   for(int i2=0; i2<loops; i2++)
   {
      int off=i2*sizeof(masks);
      for(int i1=0; i1< (int) sizeof(masks); i1++ )
      {
         memset( w[i1], masks[i1], 0x200);
         memset( r[i1], 0, 0x200);
      }
      for(int i1=sizeof(masks)-1; i1>=0; i1-- )
      {
         m_sd.write( w[i1], off + i1, 1);
         logEventLoop();
      }
      for(int i1=0; i1< (int) sizeof(masks); i1++ ) { m_sd.read(r[i1], off+i1, 1);logEventLoop(); }
      for(int i1=0; i1< (int) sizeof(masks); i1++ )
      {
         if( memcmp(w[i1], r[i1], 0x200) != 0 )
         {
            lWarning("Sector %d does not match; loop %d", i1, i2);
            err++;
         }
         logEventLoop();
      }

      for(int i1=0; i1< (int) sizeof(masks); i1++ ) { m_sd.erase( off+i1 );logEventLoop(); }
      for(int i1=0; i1< (int) sizeof(masks); i1++ ) { m_sd.read(r[i1], off+i1, 1);logEventLoop(); }
      for(int i1=0; i1< (int) sizeof(masks); i1++ )
      {
         if( memcmp(w[5], r[i1], 0x200) != 0 )
         {
            lWarning("Sector %d was not erased", i1);
            err++;
         }
         logEventLoop();
      }
      memset( d, i2, 0x200);
      m_sd.write(d, off, 1);
      memset( d, 0, 0x200);
      m_sd.read(r[0], off, 1);
      memset( d, i2, 0x200);
      if( memcmp(d, r[0], 0x200) != 0 )
      {
         lWarning("Sector %d was not write/read", off);
         err++;
      }
      logEventLoop();
      fputs(".", stdout);
   }
   fputs("\n", stdout);

   testAssert( "SD write/read/erase", err == 0, err );


   /* When speed is too high, words might get swapped around when reading.
    * This does not trigger the test above because words are all the same.
    */
   loops=0x40;
   for( int i1=0; i1<loops; i1++)
   {
      w[0][i1]=i1;
      fputs("-", stdout);
   }
   fputs("\r", stdout);
   m_sd.write( w[0], 1, 1);
   for( int i1=0; i1<loops; i1++)
   {
      memset(r[0], 0, 0x200);
      m_sd.read( r[0], 1, 1);
      if( memcmp ( w[0], r[0], 0x200) )
      {
         err++;
         lWarning("read loop mismatch %d; %d errors", i1, err);
      }
      logEventLoop();
      fputs(".", stdout);
   }
   fputs("\n", stdout);


   testAssert( "SD read loop", err == 0, err );

   return;
}

#endif


/*--- Fin ------------------------------------------------------------------*/
