/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for RTC
 * 
 * Set some random date/time and check if the rtc is still valid after
 * an reboot.
 * 
 * Warning: Bringup tests may run multiple times due to reboots
 * 
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/tests/biwak/rtc.hpp>
#include <biwak/rtc.hpp>
#include <biwak/power.h>
#include <lepto/units.h>
#include <biwak/linker_script.h>


/*--- Implementation -------------------------------------------------------*/


void CTestRtc::run( )
{
   int year, month, day;
   int hour, minute, second;
   int secs1, secs2, diff;
   //int sta=0;

   // Catch the word right before the stack. Biwak will overwrite the lower end
   // of the stack for overflow detection.

   // If the rtc is not already valid, set some date and reboot. if the date is still not valid then, something is wrong.
   // Check if the date still is in some valid reange.
#if 0
   if(!m_rtc.isValid())
   {
      printf("Date not valid. Seting date/time and reseting.\n");
      m_rtc.setDate(2022, 5, 26);
      m_rtc.setTime(11, 00, 00);
      #if defined(STM32)
         if ( __reset_command == 0x12345678 )
         {
            __reset_command=0xFEFEFEFE;
            printf("Date still valid. Serious problem.\n");
            testAssert( "set RTC", false );
            return;
         }
         __reset_command=0x12345678;
         systemReset();
      #endif
   }
#endif

   m_rtc.getDate( year, month, day );
   testAssert( "RTC Year", (year >= 2017) && (year <= 2040) );

   m_rtc.getTime(hour, minute, second);
   secs1= second + ( ( minute + ( hour * 60 ) ) *60);
   msleep( 3 * MSEC_PER_SEC );
   m_rtc.getTime(hour, minute, second);
   secs2= second + ( ( minute + ( hour * 60 ) ) *60);
   diff = secs2 - secs1;

   testAssert( "RTC diff", (abs(diff)>=2) );

   return;
}


/*--- Fin ------------------------------------------------------------------*/
