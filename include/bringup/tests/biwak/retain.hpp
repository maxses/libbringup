#ifndef BRINGUP_TESTS_RETAIN_HPP
#define BRINGUP_TESTS_RETAIN_HPP
/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for retain variables
 * 
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#define CONFIG_VAGUS_HWINFO_V6

#include <bringup/bringup.hpp>
#include <biwak/flash_i2c.hpp>


/*--- Declaration ----------------------------------------------------------*/


class CRetain;

class CTestRetain: public CSubject
{
      CFlashI2c &m_pI2cFlash;
      CRetain *m_pRetain1, *m_pRetain2;

   public:

      CTestRetain( CFlashI2c &i2c )
         : CSubject("Retain")
         ,m_pI2cFlash( i2c )
      { };
      virtual int run() override;
};


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_TESTS_RETAIN_HPP
