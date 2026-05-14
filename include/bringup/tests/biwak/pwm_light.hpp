#ifndef BRINGUP_TESTS_BIWAK_PWM_LIGHT_HPP
#define BRINGUP_TESTS_BIWAK_PWM_LIGHT_HPP
/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for PWM/light
 * 
 * Set different dimming levels and let confirm by user
 * 
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/bringup.hpp>
#include <biwak/pwm.hpp>
#include <biwak/barrel_organ.h>


/*--- Declaration ----------------------------------------------------------*/


class CTestPwmLight: public CSubject
{
      CPwmLine &m_pwmLine;
   public:
      CTestPwmLight( CPwmLine &pwmLine )
         : CSubject("PWM (light)")
         , m_pwmLine( pwmLine )
      { };
      virtual void run() override;
};


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_TESTS_BIWAK_PWM_LIGHT_HPP
