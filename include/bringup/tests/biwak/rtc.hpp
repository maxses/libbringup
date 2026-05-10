#ifndef BRINGUP_TESTS_RTC_HPP
#define BRINGUP_TESTS_RTC_HPP
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


#include <bringup/bringup.hpp>


/*--- Declaration ----------------------------------------------------------*/


class CRtc;

class CTestRtc: public CSubject
{
      CRtc &m_rtc;

   public:

      CTestRtc( CRtc &rtc  )
         : CSubject("RTC")
         ,m_rtc( rtc )
      { };
      virtual int run() override;
};


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_TESTS_RTC_HPP
