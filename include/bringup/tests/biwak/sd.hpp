#ifndef BRINGUP_TESTS_SD_HPP
#define BRINGUP_TESTS_SD_HPP
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


#include <bringup/bringup.hpp>
#include <biwak/sd.hpp>


/*--- Declaration ----------------------------------------------------------*/


class CTestSd: public CSubject
{
      CSd &m_sd;

   public:

      CTestSd( CSd &sd )
         : CSubject("SD")
         ,m_sd( sd )
      { };
      virtual void run() override;
};


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_TESTS_SD_HPP
