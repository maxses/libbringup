/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for UART
 * 
 * Just let person confirm working UART by pressing a key in terminal
 * 
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/tests/biwak/uart.hpp>
#include <biwak/uart.hpp>


/*--- Implementation -------------------------------------------------------*/


void CTestUart::run( )
{
   const char* text="Test UART.\n\rPress 't'\n\r";
   m_uart.write( text, strlen(text) );
   CBringupUserInput input( 't', 20);

   #if ! defined STM32
      // Pseudo-UART output is not seen on host
      fputs(text, stdout);
   #endif

   while( input.loop() )
   {
   };

   testAssertZero("Uart read", input.result());

   return;
}


/*--- Fin ------------------------------------------------------------------*/
