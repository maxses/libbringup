#ifndef BRINGUP_TESTS_OUTPUT_HPP
#define BRINGUP_TESTS_OUTPUT_HPP
/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for simple outputs
 * 
 * Circles over a list of ouputs and toggles each for 1/2 second.
 * 
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/bringup.hpp>
#include <lepto/string.hpp>


/*--- Declaration ----------------------------------------------------------*/


class CTestOutputs: public CSubject
{
   public:
      typedef struct {COutput &o; const char *desc;}SOutput;

   private:
      const SOutput *m_outputs;
      unsigned int m_outputCount=0;
      int m_outputPos=0;
      lrtimer_t m_outTimer=lrNow();
      CString m_outputsString;

   public:

      CTestOutputs( const SOutput *outputs, int count  )
         : CSubject("Outputs", count)
         , m_outputs(outputs)
         , m_outputCount(count)
         //, m_outputsString(10)
      { };
      virtual int run() override;
};


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_TESTS_OUTPUT_HPP
