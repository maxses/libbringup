#ifndef CAMPO_BRINGUP_TESTS_H
#define CAMPO_BRINGUP_TESTS_H
/**---------------------------------------------------------------------------
 *
 * @brief  Test funcktions to check periphery and MCU configuration
 * 
 * See implementation for further information.
 * 
 * @date    20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#error Don't include this file

#include <bringup/bringup.hpp>
#include <lepto/string.hpp>
#include <lepto/lepto.h>
#include <biwak/touch_tsc2007.h>
#include <biwak/barrel_organ.h>
#include <biwak/gdisplay.h>
#include <biwak/option_bytes.hpp>


/*--- Declaration ----------------------------------------------------------*/


class CTestPwmLight: public CSubject
{
      CPwmLine &m_pwmLine;
   public:
      CTestPwmLight( CPwmLine &pwmLine )
         : CSubject("PWM (light)")
         , m_pwmLine( pwmLine )
      { };
      virtual int run() override;
};



/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! CAMPO_BRINGUP_TESTS_H
