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


#include <bringup/tests/biwak/flashSpi.hpp>
#include <biwak/flash_spi.hpp>


/*--- Implementation -------------------------------------------------------*/


void CTestSpiFlash::run( )
{
   printf( "Id: 0x%X\n", m_flash.readId() );
   printf( "Jedec-Id: 0x%X\n", m_flash.readJedecId() );
   printf( "Size: %d Bytes\n", m_flash.size() );

   testAssert( "Vendor", ( m_flash.vendor() > 0 ) && ( m_flash.vendor() < 0x40000000 ), m_flash.vendor() );
   testAssert( "Id", ( m_flash.readId() > 0 ) && ( m_flash.readId() < 0x40000000 ), m_flash.readId() );
   testInfo( "Jedec-Id", m_flash.readJedecId() );
   testAssert( "Size", ( m_flash.size() > 0 ) && ( m_flash.size() < 0x40000000 ), m_flash.size() );
   testInfo( "Size (Bytes)", m_flash.size() );

   return;
}


/*--- Fin ------------------------------------------------------------------*/
