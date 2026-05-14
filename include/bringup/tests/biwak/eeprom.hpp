#ifndef BRINGUP_TESTS_BIWAK_EEPROM_HPP
#define BRINGUP_TESTS_BIWAK_EEPROM_HPP
/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for EEPROM
 *
 * As long the test runs successfully, the test is non-destructive and
 * will restore origin flash content. It tries to work on area after
 * the campos hwData-structures.
 * The hwData-structures can still be destroyed when adress width does
 * not match to the device.
 *
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/bringup.hpp>
#include <biwak/flash.h>


/*--- Declaration ----------------------------------------------------------*/


class CTestI2cEeprom: public CSubject
{
      CFlash &m_eeprom;

   public:

      CTestI2cEeprom( CFlash &flashI2c  )
         : CSubject( "I2C-EEPROM" )
         ,m_eeprom( flashI2c )
      { };
      virtual void run() override;
};


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_TESTS_BIWAK_EEPROM_HPP
