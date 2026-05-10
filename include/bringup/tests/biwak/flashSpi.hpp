#ifndef BRINGUP_TESTS_BIWAK_FLASH_SPI_HPP
#define BRINGUP_TESTS_BIWAK_FLASH_SPI_HPP
/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for flash connected via SPI
 * 
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/bringup.hpp>


/*--- Declaration ----------------------------------------------------------*/


class CFlashSpi;

class CTestSpiFlash: public CSubject
{
      CFlashSpi &m_flash;

   public:

      CTestSpiFlash( CFlashSpi &flash  )
         : CSubject("SPI-Flash")
         ,m_flash( flash )
      { };
      virtual int run() override;
};


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_TESTS_BIWAK_FLASH_SPI_HPP
