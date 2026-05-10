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


#include <bringup/tests/biwak/pwm.hpp>
#include <biwak/pwm.hpp>


/*--- Implementation -------------------------------------------------------*/


int CTestPwmBuzzer::run( )
{
   CBringupUserInput input( 'y', 20);

   #if IS_ENABLED( CONFIG_BIWAK_PWM_BARREL_ORGAN )
      printf("Hear the pwm buzzer. Press 'y' if it works.\n");
      m_pwmLine.setBeepMode( Barrel::Beep::sireneFast );
      while( input.loop() )
      {
         m_pwmLine.eventLoop();
      }
      m_pwmLine.setBeepMode( nullptr );
      testAssertZero( confirmation, input.result() );
   #else
      printf("Hear the pwm buzzer. Press 'y' if it works.\n");
      m_bo.setBeepMode( Barrel::Beep::sireneFast );
      while( input.loop() )
      {
         biwakEventLoop();
         m_bo.eventLoop();
      }
      m_bo.setBeepMode( nullptr );
      testAssertZero( "Confirmation", input.result() );

      printf("Done.\n");
   #endif

   return(0);
}


/*--- Fin ------------------------------------------------------------------*/
