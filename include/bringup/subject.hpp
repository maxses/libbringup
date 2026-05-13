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
      CList <CResult> m_results;

   public:
      CSubject(const char *topic, int results = 0);
      virtual int run() = 0;
      const char *getTopic() const
         {return(m_topic);};
      const CList <CResult> &results() const
         {return(m_results);};
      int testAssert(const char *test, bool assertion, int value, EResult eResult=EResult::failed);
      int testAssertZero(const char *test, int value);
      int testAssertSilent(const char *test, bool assertion, int value);
      int testInfo(const char *test, int value);
      int hintAffirmed(const char* text);
};


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_SUBJECT_HPP
