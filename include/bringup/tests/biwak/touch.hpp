#ifndef BRINGUP_TESTS_TOUCH_HPP
#define BRINGUP_TESTS_TOUCH_HPP
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


#include <bringup/bringup.hpp>
#include <biwak/gdisplay.h>
#include <biwak/touch.h>


/*--- Declaration ----------------------------------------------------------*/


class CTouchTsc2007;
class CTestTouch: public CSubject
{
   private:
      CTouchTsc2007 &m_touch;
      CGraphicDisplay &m_display;
      bool m_rectPressed;
      int m_x0, m_y0, m_x1, m_y1;

   public:

      CTestTouch( CTouchTsc2007 &touch, CGraphicDisplay &display )
         : CSubject("Touch")
         ,m_touch( touch )
         ,m_display( display )
      { };
      virtual void run() override;
      void slotEvent( const CTouch::SEvent& );
};


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_TESTS_TOUCH_HPP
