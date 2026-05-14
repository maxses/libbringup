/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for button
 *
 * Let tester press the button
 *
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/tests/biwak/button.hpp>
#include <biwak/button.hpp>


/*--- Implementation -------------------------------------------------------*/


bool CTestButton::getValue() const
{
   return m_button.getValue();
};


void CTestButton::run( )
{
   //int sta=0;
   bool finished=false;
   lrtimer_t timer;
   enum
   {
      eStart, eWaitLow, eGoWaitPressed, eWaitPressed,
      eWaitHigh, eEnd
   } eState = eStart;

   #if defined ( BIWAK_USE_INPUT_SIGNAL )
   m_input.interruptSignal.connect( this, &CTestButton::slotInputPressed );
   #else
   #endif

   while(!finished)
   {
      biwakEventLoop();

      switch(eState)
      {
         case(eStart):
            printf("Be patient, monitoring input\n");
            eState=eWaitLow;
            timer=lrNow();
            break;
         case (eWaitLow):
            if( lrElapsedSeconds( &timer, 2) )
            {
               eState=eGoWaitPressed;
            }
            testAssertSilent("Value stays low", getValue() == false, getValue());
            if( !( getValue() == false ) )
            {
               eState=eEnd;
            }
            break;
         case (eGoWaitPressed):
            testAssert("Value is low in idle", getValue() == false, getValue());
            printf("Now press the button/input %s\n",
                   (m_mode==EMode::eButton) ? "and hold it good." : "and release it."
                                              );
            eState=eWaitPressed;
            break;
         case (eWaitPressed):
            if( lrElapsedSeconds( &timer, 10) )
            {
               testAssert("Value did not get high", false, getValue());
               eState=eEnd;
            }
            else if ( getValue() )
            {
               timer=lrNow();
               testAssert("Value did get high", getValue() == true, getValue());
               printf("Good job! %s\n",
                      ( m_mode==EMode::eButton ) ? "Hold it pressed." : "");
               eState=eWaitHigh;
            }
            break;
         case(eWaitHigh):
            if( m_mode == EMode::eInterruptShot)
            {
               eState=eEnd;
               break;
            }
            if( lrElapsedSeconds( &timer, 2) )
            {
               printf("Done. Value stays high\n");
               eState=eEnd;
            }
            else
            {
               testAssertSilent("Value stays high", getValue()==true, getValue());
               if( !( getValue()==true ) )
               {
                  printf("Done. Value did not stay high\n");
                  eState=eEnd;
               }
            }
            break;
         case(eEnd):
            finished=true;
            break;
         default:
            testAssert("Invalid State", 0, eState);
            break;
      }
   }

   return;
}


/*--- Fin ------------------------------------------------------------------*/
