/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for checkng CRC functionality
 * 
 * The crc functions from liblepto are used. But those functions may
 * be overloaded by libbiwak. So on target the CRC hardware unit is
 * used
 * 
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/tests/crc.hpp>
#include <lepto/crc32.h>
#include <arena_app.h>


/*--- Implementation -------------------------------------------------------*/


void CTestCrc::run()
{
   // Can be checked on https://crccalc.com/

   const char *data1="Hell";
   const char *data2="o Wo";
   const char *data3="rld!";
   const char *data4="12345678";

   //---------------------------------
   // Check accumulating 2 blocks

   crc32_t crc;
   #if 1
   crc=crc32Init();
   crc=crc32Update(crc, data1, strlen(data1));
   crc=crc32Update(crc, data2, strlen(data2));
   crc=crc32Update(crc, data3, strlen(data3));
   crc=crc32Finalize(crc);
   lInfo("CRC=0x%X", crc);

   #if defined ( STM32 )
      // The lepto functions are tested because thats what used in e.g. retain.
      // The functions should be mapped to the biwak corespondens.
      #if ! ARENA_USE_CRC
         // Hardware-CRC is not used on this board
         printf("Error: Hardware CRC is not used\n");
         testAssert( "CRC32 HW", 1 == 2, crc );
         return;
      #endif
   #endif // ? STM32

   // "https://crccalc.com/?crc=HelloWorld!&method=CRC-32&datatype=ascii&outtype=hex"

   #if defined STM32F1
      testAssert( "CRC32 v1", crc == 0x94E58351 );
   #else
      testAssert( "CRC32 v1", crc == 0x1C291CA3 );
   #endif

   #endif

   //---------------------------------
   // Check new calculation

   /* "Default" CRC32 for '12345678'
    * echo -n "12345678" > test.dat
    * crc32 test.dat
    * 9ae0daaf
    */
   crc=calcCrc32(data4, 8);
   #if defined STM32F1
      testAssert( "CRC32 v2", crc == 0x49E3C2FB );
   #else
      testAssert( "CRC32 v2", crc == 0x9ae0daaf );
   #endif

   //---------------------------------
   // Larger data
   // https://crccalc.com/?crc=0x4d,0x90,0x00,0x90,0x01,0x00,0x50,0x01,0x00,0x00,0x00,0xe7,0x07,0x0b,0x0c,0x41,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0x52,0x05,0x00,0x06,0x32,0x00,0x00,0x00&method=CRC-32&datatype=hex&outtype=hex
   static const uint8_t data5[] {
      0x4d, 0x90, 0x00, 0x90, 0x01, 0x00, 0x50, 0x01, 0x00, 0x00, 0x00, 0xe7,
      0x07, 0x0b, 0x0c, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0xff, 0xff, 0x52, 0x05, 0x00, 0x06, 0x32, 0x00, 0x00, 0x00
   };

   crc=calcCrc32(data5, sizeof(data5) );
   #if defined STM32F1
      testAssert( "CRC32 v3", crc == 0xECB85B93 );
   #else
      testAssert( "CRC32 v3", crc == 0x90DEC74A );
   #endif

   return;
}


/*--- Fin ------------------------------------------------------------------*/
