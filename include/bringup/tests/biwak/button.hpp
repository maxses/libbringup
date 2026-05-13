#ifndef BRINGUP_TESTS_BUTTON_HPP
#define BRINGUP_TESTS_BUTTON_HPP
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


#include <bringup/bringup.hpp>
#include <biwak/button.hpp>


/*--- Declaration ----------------------------------------------------------*/


class CTestButton: public CSubject
{
   public:
      enum EMode{eButton, eInterruptShot};

   private:
      CButton &m_button;
      EMode m_mode;

   public:

      CTestButton( CButton &button, EMode mode=eButton, const char *name="None" )
         : CSubject( "Button" )
         ,m_button( button )
         ,m_mode(mode)
      {
         printf("\nButton: %s\n", name);
      };
      virtual int run() override;
      bool getValue() const;
};


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_TESTS_BUTTON_HPP
