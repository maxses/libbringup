#ifndef BRINGUP_TESTS_BIWAK_GDISPLAY_HPP
#define BRINGUP_TESTS_BIWAK_GDISPLAY_HPP
/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for graphical display
 * 
 * Draw stuff
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


class CTestGraphicDisplay: public CSubject
{
      CGraphicDisplay &m_display;
      const TRgb* m_colors[9]{
         &white, &black, &blue,
         &green, &red, &lightGreen,
         &magenta, &darkBlue, &grey
      };
      //const TRgb& colors[6]{white, black, blue, green, red, lightGreen};
      int m_color=0;

      struct SFunc
      {
         CFunctorMethod<void, CTestGraphicDisplay, int, int, int, int> functor;
         const char* name;
      };

   public:
      CTestGraphicDisplay( CGraphicDisplay &display )
         : CSubject("Graphic display")
         , m_display(display)
      { };
      virtual int run() override;
      void test_hline(int x1, int y1, int x2, int y2);
      void test_vline(int x1, int y1, int x2, int y2);
      void test_circle(int x1, int y1, int x2, int y2);
      void test_circle_filled(int x1, int y1, int x2, int y2);
      void test_bar(int x1, int y1, int x2, int y2);
      void test_line(int x1, int y1, int x2, int y2);
      void test_line2(int x1, int y1, int x2, int y2);
      void test_text(int x1, int y1, int x2, int y2);
      void test_text_bgr(int x1, int y1, int x2, int y2);

      const TRgb& getColor()
      {
         int color=m_color;
         m_color++;
         m_color%=arraySize(m_colors);
         return( *m_colors[color] );
      }
      int r()
      {
         return(14);
      }
      int h()
      {
         return(28);
      }
      int dist()
      {
         return(4);
      }
};


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_TESTS_BIWAK_GDISPLAY_HPP
