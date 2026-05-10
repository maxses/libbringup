#ifndef BRINGUP_TESTS_PWM_HPP
#define BRINGUP_TESTS_PWM_HPP
/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for PWM/buzzer
 * 
 * Just play a tone and let confirm by user
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


class CTestPwmBuzzer: public CSubject
{
      CPwmLine &m_pwmLine;
      #if ! IS_ENABLED( CONFIG_BIWAK_PWM_BARREL_ORGAN )
         CBarrelOrganBeep m_bo;
      #endif

   public:
      CTestPwmBuzzer( CPwmLine &pwmLine )
         : CSubject("PWM (buzzer)", 1)
         , m_pwmLine( pwmLine )
      #if ! IS_ENABLED( CONFIG_BIWAK_PWM_BARREL_ORGAN )
         , m_bo( &pwmLine )
      #endif
      { };
      virtual int run() override;
};


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_TESTS_PWM_HPP
