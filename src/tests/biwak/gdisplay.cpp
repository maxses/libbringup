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


#include <bringup/tests/biwak/gdisplay.hpp>
#include <biwak/gdisplay.h>


/*--- Implementation -------------------------------------------------------*/


void CTestGraphicDisplay::test_hline(int x1, int y1, int x2, int y2)
{
   for(int i1=y1+1; i1<y2; i1+=2)
   {
      m_display.drawHLine(x1+1, i1, x2-1, getColor() );
   }
};

void CTestGraphicDisplay::test_vline(int x1, int y1, int x2, int y2)
{
   for(int i1=x1+1; i1<x2; i1+=2)
   {
      m_display.drawVLine(i1, y1+1, y2-1, getColor() );
   }
};

void CTestGraphicDisplay::test_circle(int x1, int y1, int x2, int y2)
{
   (void)y2;
   for(int i1=x1+1+r(); i1<x2-r(); i1+=2+(r()*2))
   {
      m_display.drawCircle(i1, y1+r(), r()-2, false, getColor() );
   }
};

void CTestGraphicDisplay::test_circle_filled(int x1, int y1, int x2, int y2)
{
   (void)y2;
   for(int i1=x1+1+r(); i1<x2-r(); i1+=2+(r()*2))
   {
      m_display.drawCircle(i1, y1+r(), r()-2, true, getColor() );
   }
};

void CTestGraphicDisplay::test_bar(int x1, int y1, int x2, int y2)
{
   m_display.drawBar(x1+1, y1+1, x2-1, y2-1, getColor(), getColor() );
};

void CTestGraphicDisplay::test_line(int x1, int y1, int x2, int y2)
{
   m_display.drawLine(x1+1, y1+1, x2-1, y2-1, getColor() );
   m_display.drawLine(x1+1, y2-1, x2-1, y1+1, getColor() );
};

void CTestGraphicDisplay::test_line2(int x1, int y1, int x2, int y2)
{
   TRgb col{};
   int c=0;
   for(int i1=x1+1; i1<x2; i1+=1)
   {
      m_display.drawLine( (x1+x2)/2, y1+1, i1, y2-1, col );
      col.red=( ( 0xff * c ) / ( x2-x1 ) );
      col.green=col.red;
      col.blue=col.red;
      c++;
   }
};

void CTestGraphicDisplay::test_text(int x1, int y1, int x2, int y2)
{
   m_display.setFont( getFont16() );
   m_display.setFg( red );
   m_display.drawText( (x1+x2)/2, (y1+y2)/2, "HELLO W!", eTextFlagsHCenter | eTextFlagsVCenter );
   m_display.setFont( getFont8() );
};

void CTestGraphicDisplay::test_text_bgr(int x1, int y1, int x2, int y2)
{
   m_display.setFont( getFont16() );
   m_display.setFg( red );
   m_display.setDrawBackground( true );
   m_display.drawBar( x1+1, y1+1, x2-1, y2-1, darkBlue );
   m_display.drawText( (x1+x2)/2, (y1+y2)/2, "HELLO W!", eTextFlagsHCenter | eTextFlagsVCenter );
   m_display.setFont( getFont8() );
};


int CTestGraphicDisplay::run ( )
{
   int sta=0;
   CBringupUserInput input( 'y', 20);

   SFunc functions[]{
       { .functor{ this, &CTestGraphicDisplay::test_hline }, .name { "H-LINE" } },
       { .functor{ this, &CTestGraphicDisplay::test_vline }, .name { "V-LINE" } },
       { .functor{ this, &CTestGraphicDisplay::test_circle }, .name="CIRCLE" },
       { .functor{ this, &CTestGraphicDisplay::test_circle_filled }, .name="CIRCLE F." },
       { .functor{ this, &CTestGraphicDisplay::test_bar }, .name="BAR GRAD." },
       { .functor{ this, &CTestGraphicDisplay::test_line }, .name="LINE" },
       { .functor{ this, &CTestGraphicDisplay::test_line2 }, .name="LINE 2" },
       { .functor{ this, &CTestGraphicDisplay::test_text }, .name="TEXT CNT." },
       { .functor{ this, &CTestGraphicDisplay::test_text_bgr }, .name="TEXT BCK" },
   };

   m_display.clear( cyan );
   m_display.setBg( cyan );
   m_display.setFont( getFont16() );
   m_display.setFg( red );
   m_display.setDrawBackground(false);
   m_display.setFont( getFont8() );

   m_display.drawCircle(120, 160, 100, false, green );
   m_display.drawCircle(120, 160, 98, true, lightBlue );

   int x1=80, x2=240-16;
   int y1=16, y2=y1+h();
   for(int i1=0; i1 < arraySize(functions); i1++)
   {
      m_display.drawText(4, y1+((h()-8)/2), functions[i1].name);
      m_display.drawRect(x1, y1, x2, y2, blue);
      functions[i1].functor.emitSignal(x1, y1, x2, y2);
      y1+= h()+dist();
      y2+= h()+dist();
   }

   printf("Watch the display output. Press 'y' if it works.\n");
   while( input.loop() )
   {}
   testAssertZero( "confirmation", input.result() );

   return(sta);
}


/*--- Fin ------------------------------------------------------------------*/
