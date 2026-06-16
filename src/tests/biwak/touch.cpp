/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for touch display
 * 
 * Let user touch some points.
 * 
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/tests/biwak/touch.hpp>
#include <biwak/uart.hpp>
#include <biwak/touch_calibration.h>
#include <biwak/touch_tsc2007.h>


/*--- Implementation -------------------------------------------------------*/


void CTestTouch::run( )
{
   m_x0=32;
   m_y0=320-32-64;
   m_x1=32+64;
   m_y1=320-32;
   m_display.drawRect(32,320-32-64, 32+64, 320-32, white);
   int border=CTouchCalibration::getCalibrationBorder();
   m_display.drawRect(border-2, border-2, border+2, border+2, white);
   m_display.drawRect( m_display.width()-border-2, border-2,
                       m_display.width()-border+2, border+2, white);
   m_display.drawRect( m_display.width()-border-2, m_display.height()-border-2,
                       m_display.width()-border+2, m_display.height()-border+2, white);
   m_display.drawRect( border-2, m_display.height()-border-2,
                       border+2, m_display.height()-border+2, white);
   m_touch.signalEvent().connect(this, &CTestTouch::slotEvent );
   CBringupUserInput input( '\1', 20);

   printf("Pres the bigger rectangle on the display. Press 'a' on the keyboard to abort the test.\n");
   m_rectPressed=false;

   while( input.loop() && (! m_rectPressed ) )
   {
      m_touch.eventLoop();
   }
   testAssert( "Touch pressed in correct position", m_rectPressed == true );
   m_display.clear();
   
   return;
}


void CTestTouch::slotEvent( const CTouch::SEvent& event )
{
   if(event.type==CTouch::EEventType::pressed)
   {
      m_display.drawCircle(event.x, event.y, 3, true, blue);
      if( ( event.x >= m_x0 ) && ( event.x <= m_x1 )
       && ( event.y >= m_y0 ) && ( event.y <= m_y1 ) )
      {
         m_rectPressed=true;
      }
   }
}


/*--- Fin ------------------------------------------------------------------*/
