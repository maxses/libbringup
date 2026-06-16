/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for external RTC
 * 
 * Set some time and expect it to be read back correctly.
 * 
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/tests/biwak/rtcI2c.hpp>
#include <biwak/i2c_rtc.h>
#include <lepto/units.h>


/*--- Implementation -------------------------------------------------------*/


void CTestI2cRtc::run( )
{
   CI2cRtc i2cRtc( m_i2c );
   int hour, min, sec;
   int year, month, day;
   int stamp1, stamp2, diff;

   i2cRtc.enable();

   // Can the date actually be set or does it get lost
   i2cRtc.setDate( 2022, 5, 26 );
   i2cRtc.getDate( year, month, day );
   testAssert( "I2C RTC Year", ( year == 2022 ) && ( month == 5 ) && ( day == 26 ) );

   // Just wait some seconds and check the time diff in the RTC to be plausible
   i2cRtc.getTime( hour, min, sec );
   stamp1=sec + ( min * SEC_PER_MIN) + (hour * SEC_PER_HOUR);
   msleep( 2500 );
   i2cRtc.getTime( hour, min, sec );
   stamp2=sec + ( min * SEC_PER_MIN) + (hour * SEC_PER_HOUR);

   diff=stamp2-stamp1;
   testAssert("diff", (diff>=2) && (diff<=3) );

   return;
}


/*--- Fin ------------------------------------------------------------------*/
