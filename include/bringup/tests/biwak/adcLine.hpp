#ifndef BRINGUP_TESTS_ADC_LINE_HPP
#define BRINGUP_TESTS_ADC_LINE_HPP
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


#include <bringup/bringup.hpp>
#include <biwak/adc_line.hpp>


/*--- Declaration ----------------------------------------------------------*/


class CTestAdcLine: public CSubject
{
      CAdcLine &m_adcLine;
      int m_min;
      int m_max;

   public:

      CTestAdcLine(CAdcLine &adcLine, int min, int max  )
         : CSubject("ADC")
         ,m_adcLine( adcLine )
         ,m_min(min)
         ,m_max(max)
      { };
      virtual int run() override;
};


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_TESTS_ADC_LINE_HPP
