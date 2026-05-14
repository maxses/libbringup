/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for ADC_LINE
 *
 * Tests if an ADC input is in expected range.
 *
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/tests/biwak/adcLine.hpp>
#include <biwak/uart.hpp>


/*--- Implementation -------------------------------------------------------*/


void CTestAdcLine::run( )
{

   int value=m_adcLine.getAdcValue();
   printf("ADC-Value: %d; / %d mV\n", value, ( value * 3000 ) / 4095 );

   testAssert("ADC value range", ( value >= m_min ) && ( value <= m_max ), value );

   return;
}


/*--- Fin ------------------------------------------------------------------*/
