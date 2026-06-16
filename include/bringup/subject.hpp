#ifndef BRINGUP_SUBJECT_HPP
#define BRINGUP_SUBJECT_HPP
/**---------------------------------------------------------------------------
 *
 * @brief  The subject to be testes
 * 
 * Like "LED"
 * Holds a list of results
 *
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <lepto/list.hpp>
#include <bringup/result.hpp>


/*--- Declaration ----------------------------------------------------------*/


class CSubject
{
   private:
      const char *m_topic;
      CList <CResult>* m_pResults = nullptr;

   public:
      CSubject(const char *topic);
      virtual void run() = 0;
      const char *getTopic() const
         {return(m_topic);};
      const CList <CResult> &results() const
         { return( *m_pResults ); };
      void testAssert(const char *test, bool assertion, EResult eResult=EResult::failed);
      void testAssertZero(const char *test, int value);
      void testAssertSilent(const char *test, bool assertion );
      void testInfo( const char *test );
      void testFatal( const char *test );
      void hintAffirmed( const char* text );
      void setResultList( CList <CResult>* results )
      {
         m_pResults=results;
      }
};


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_SUBJECT_HPP
