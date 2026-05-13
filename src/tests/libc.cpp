/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for checkng libc functionality
 * 
 * Runs strtol() and malloc()
 * 
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/tests/libc.hpp>


/*--- Implementation -------------------------------------------------------*/


int CTestLibc::run( )
{
   int sta=0;
   int value;

   value=strtol("15956", nullptr, 10);
   sta=testAssert("Libc strtol 15956", value == 15956, value);

   int size=0x4;
   void *ptr=nullptr;

   sta=testAssert( "malloc <size>", (ptr=malloc(size))  != 0, 0 );
   if(ptr)
   {
      #if ! CONFIG_NO_FREE
      free(ptr);
      #endif
   }

   return(sta);
}


/*--- Fin ------------------------------------------------------------------*/
