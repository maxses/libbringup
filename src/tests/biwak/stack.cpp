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


#include <bringup/tests/biwak/stack.hpp>
#include <biwak/sd.hpp>


/*--- Implementation -------------------------------------------------------*/


void CTestStack::run()
{
   #if defined STM32
   int cnt=0;
   char *bp=&_user_stack;

   while( *bp == 0x77 )
   {
      cnt++;
      bp++;
   }

   testAssert( "Stack clean", cnt > 8, cnt );
   #endif

   return;
}


/*--- Fin ------------------------------------------------------------------*/
