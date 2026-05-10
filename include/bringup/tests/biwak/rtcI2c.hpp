#ifndef BRINGUP_TESTS_RTC_I2C_HPP
#define BRINGUP_TESTS_RTC_I2C_HPP
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


#include <bringup/bringup.hpp>
#include <biwak/i2c.hpp>


/*--- Declaration ----------------------------------------------------------*/


class CTestI2cRtc: public CSubject
{
      CI2c &m_i2c;

   public:

      CTestI2cRtc( CI2c &i2c  )
         : CSubject("I2C-RTC")
         ,m_i2c( i2c )
      { };
      virtual int run() override;
};


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_TESTS_RTC_I2C_HPP
