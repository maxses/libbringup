#ifndef BRINGUP_TESTS_INPUT_HPP
#define BRINGUP_TESTS_INPUT_HPP
/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for input pin
 * 
 * Same as test for button at the moment.
 * 
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/bringup.hpp>


/*--- Declaration ----------------------------------------------------------*/


class CTestInput: public CSubject
{
   public:
      enum EMode{eButton, eInterruptShot};

   private:
      CInput &m_input;
      EMode m_mode;
      bool m_value=false;

   public:

      CTestInput( CInput &input, EMode mode=eButton, const char *name="None" )
         : CSubject("Input")
         ,m_input( input )
         ,m_mode(mode)
      {
         printf("\nInput: %s\n", name);
      };
      virtual int run() override;
      void slotInputPressed(bool value)
      {
         m_value=value;
      }
      bool getValue() const
      {
         return m_value;
      };
};


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_TESTS_INPUT_HPP
