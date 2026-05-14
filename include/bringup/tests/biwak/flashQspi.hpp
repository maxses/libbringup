#ifndef BRINGUP_TESTS_BIWAK_FLASH_QSPI_HPP
#define BRINGUP_TESTS_BIWAK_FLASH_QSPI_HPP
/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for flash connected via QSPI
 * 
 * Any difference to regular SPI-FLash?
 * 
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/bringup.hpp>


/*--- Declaration ----------------------------------------------------------*/


class CQSpi;

class CTestQSpiFlash: public CSubject
{
      CQSpi &m_qspi;

   public:

      CTestQSpiFlash( CQSpi &qspi  )
         : CSubject("SPI-Flash")
         ,m_qspi( qspi )
      { };
      virtual void run() override;
};


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_TESTS_BIWAK_FLASH_QSPI_HPP
