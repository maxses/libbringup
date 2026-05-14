/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for option bytes of STM32
 * 
 * Write some patterns to the option bytes and see if they are stored
 * correctly.
 * 
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/tests/biwak/optionBytes.hpp>


/*--- Implementation -------------------------------------------------------*/


void CTestOptionBytes::run()
{
   int sta=0;
   uint8_t byte0;
   uint8_t byte1;

   // Bad idea to write random values
#if 1
   ( sta = m_optionBytes.writeByte(0, 0x77 ) ) ||
   ( sta = m_optionBytes.writeByte(1, 0xAA ) );
   testAssert( "Status", sta == 0x0, sta );

   byte0=m_optionBytes.readByte(0);
   byte1=m_optionBytes.readByte(1);

   testAssert( "Byte0 L0", byte0 == (uint8_t)0x77, byte0 );
   testAssert( "Byte1 L0", byte1 == (uint8_t)0xAA, byte1 );

   ( sta = m_optionBytes.writeByte(0, 0xCD ) ) ||
   ( sta = m_optionBytes.writeByte(1, 0xEF ) );
   testAssert( "Status", sta == 0x0, sta );

   byte0=m_optionBytes.readByte(0);
   byte1=m_optionBytes.readByte(1);

   testAssert( "Byte0 L0", byte0 == (uint8_t)0xCD, byte0 );
   testAssert( "Byte1 L0", byte1 == (uint8_t)0xEF, byte1 );
#endif

   return;
}


/*--- Fin ------------------------------------------------------------------*/
