#ifndef BRINGUP_TESTS_BIWAK_FLASH_INTERN_HPP
#define BRINGUP_TESTS_BIWAK_FLASH_INTERN_HPP
/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for internal flash
 * 
 * Write patterns and expect correct read back.
 * 
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/bringup.hpp>


/*--- Declaration ----------------------------------------------------------*/


class CTestFlashIntern: public CSubject
{
   public:

      CTestFlashIntern( )
         : CSubject("Intern flash")
      { };
      virtual void run() override;
};


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_TESTS_BIWAK_FLASH_INTERN_HPP
