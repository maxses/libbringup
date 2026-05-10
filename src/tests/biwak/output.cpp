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


#include <bringup/tests/biwak/output.hpp>
#include <lepto/units.h>
#include <biwak/output.hpp>


/*--- Implementation -------------------------------------------------------*/


int CTestOutputs::run ( )
{
   int sta=0;
   CBringupUserInput input( 'y', 60 );

   for (int i1=0; i1<m_outputCount; i1++)
   {
      if(i1)
         m_outputsString+=",";
      m_outputsString+=m_outputs[i1].desc;
   }

   printf("\nOutputs: %s\n\n", m_outputsString.data());
   // testAssert( outputsString.data(), true, (int)EResult::dummy );

   printf("Outputs are toggled circular.\n");
   printf("Press 'y' when OK or any if not.\n");

   while( input.loop() )
   {
      if( lrElapsedMSeconds( &m_outTimer, MSEC_PER_SEC/2) )
      {
         if(m_outputCount)
         {
            m_outputs[m_outputPos].o.switchOff();

            m_outputPos++;
            m_outputPos%=m_outputCount;

            m_outputs[m_outputPos].o.switchOn();
         }
      }
   }

   m_outputs[m_outputPos].o.switchOff();

   m_outputsString += ":Conf.";
   sta=testAssertZero( m_outputsString.data(), input.result() );

   return(sta);
}


/*--- Fin ------------------------------------------------------------------*/
