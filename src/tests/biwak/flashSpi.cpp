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


int CTestSpiFlash::run( )
{
   int sta=0;

   printf( "Id: 0x%X\n", m_flash.readId() );
   printf( "Jedec-Id: 0x%X\n", m_flash.readJedecId() );
   printf( "Size: %d Bytes\n", m_flash.size() );

   sta=testAssert( "Vendor", ( m_flash.vendor() > 0 ) && ( m_flash.vendor() < 0x40000000 ), m_flash.vendor() );
   sta=testAssert( "Id", ( m_flash.readId() > 0 ) && ( m_flash.readId() < 0x40000000 ), m_flash.readId() );
   sta=testInfo( "Jedec-Id", m_flash.readJedecId() );
   sta=testAssert( "Size", ( m_flash.size() > 0 ) && ( m_flash.size() < 0x40000000 ), m_flash.size() );
   sta=testInfo( "Size (Bytes)", m_flash.size() );

   return(sta);
}


/*--- Fin ------------------------------------------------------------------*/
