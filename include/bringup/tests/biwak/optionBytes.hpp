#ifndef BRINGUP_TESTS_BIWAK_OPTION_BYTES_HPP
#define BRINGUP_TESTS_BIWAK_OPTION_BYTES_HPP
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


#include <bringup/bringup.hpp>
#include <biwak/option_bytes.hpp>


/*--- Declaration ----------------------------------------------------------*/


class CTestOptionBytes: public CSubject
{
   private:
      COptionBytes& m_optionBytes;

   public:
      CTestOptionBytes( COptionBytes& optionBytes )
          : CSubject("Option Bytes")
          , m_optionBytes( optionBytes )
      {
      };
      virtual int run() override;
};


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_TESTS_BIWAK_OPTION_BYTES_HPP
