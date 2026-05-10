#ifndef BRINGUP_TESTS_STACK_HPP
#define BRINGUP_TESTS_STACK_HPP
/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for checking stack
 * 
 * This tests counts the continuous '0x77' from the lower side of the
 * stack. The idea was probably to detect previously stack overflows.
 * But libbiwak does check this anyways.
 * 
 * This test can be rempoved.
 * 
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/bringup.hpp>


/*--- Declaration ----------------------------------------------------------*/


extern char _user_stack;

class CTestStack: public CSubject
{
   public:

      CTestStack(  )
         : CSubject("Stack")
      {
         #if defined STM32
         char *bp=&_user_stack;
         register uint32_t sp asm("sp");
         while( (address_t)bp < sp)
         {
            *bp=0x77;
            bp++;
         }
         #endif
      };
      virtual int run() override;
};


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_TESTS_STACK_HPP
