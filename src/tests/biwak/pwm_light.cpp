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


#include <bringup/tests/biwak/pwm_light.hpp>
#include <biwak/pwm.hpp>


/*--- Implementation -------------------------------------------------------*/


void CTestPwmLight::run( )
{
   CBringupUserInput input( 'y', 20);
   static constexpr CBarrelOrgan::SSlope fadeOut [] =
       { { 1000, 0, MSEC_PER_SEC / 4 },
         { 0, 1000, MSEC_PER_SEC / 4 },
         { CBarrelOrgan::restart, 0, 0 } };

   #if defined ( BIWAK_PWM_BARREL_ORGAN )
   #else
      CBarrelOrganFade fader( &m_pwmLine );
      fader.setFadeMode( /* Barrel::Fade::standby */ fadeOut );
      printf("Watch the light fading. Press 'y' if OK.\n");
      while( input.loop() )
      {
          fader.eventLoop();
      }
      fader.setFadeMode( nullptr );
      testAssertZero( "confirmation", input.result() );
   #endif

   return;
}


/*--- Fin ------------------------------------------------------------------*/
