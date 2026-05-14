/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for input pin
 * 
 * Same as test for button at the moment.
 * 
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/tests/biwak/uart.hpp>
#include <biwak/uart.hpp>


/*--- Declaration ----------------------------------------------------------*/


void CTestUart::run( )
{
   const char* text="Test UART.\n\rPress 't'\n\r";
   m_uart.write( text, strlen(text) );
   CBringupUserInput input( 't', 20);

   #if ! defined STM32
      // Pseudo-UART output is not seen on host
      printf(text);
   #endif

   while( input.loop() )
   {
   };

   testAssertZero("Uart read", input.result());

   return;
}


/*--- Fin ------------------------------------------------------------------*/
