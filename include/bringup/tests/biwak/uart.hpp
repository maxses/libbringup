#ifndef BRINGUP_TESTS_UART_HPP
#define BRINGUP_TESTS_UART_HPP
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


#include <bringup/bringup.hpp>


/*--- Declaration ----------------------------------------------------------*/


class CTestUart: public CSubject
{
      CUart &m_uart;

   public:

      CTestUart( CUart &uart  )
         : CSubject( "UART" )
         ,m_uart( uart )
      { };
      virtual int run() override;
};


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_TESTS_UART_HPP
