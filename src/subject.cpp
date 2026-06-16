/**---------------------------------------------------------------------------
 *
 * @brief  Bringup issue
 * 
 * An issue is an test that has to be executed.
 * 
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/bringup.hpp>
#include <stdio.h>


/*--- Implementation -------------------------------------------------------*/


const char *errorStr="\033[91mError\e[39m\n";
const char *okStr="\e[92mOk\e[39m\n";


CSubject::CSubject( const char *topic )
   :m_topic(topic)
{
   printf("Current issue tested: %s\n", topic);
   return;
}


void CSubject::testAssert(const char *test, bool assertion, EResult eResult /*=EResult::failed*/ )
{
   m_pResults->push_back( CResult(this, test, ( assertion ? EResult::ok : eResult) ) );
   return;
}


void CSubject::testAssertZero(const char *test, int value)
{
   testAssert(test, value==0);
   return;
}


void CSubject::testAssertSilent(const char *test, bool assertion )
{
   if(!assertion)
   {
      testAssert( test, assertion );
   }
   return;
}


void CSubject::testInfo(const char *test )
{
   m_pResults->push_back( CResult( this, test, EResult::info ) );

   return;
}


void CSubject::testFatal( const char *test )
{
   m_pResults->push_back( CResult(this, test, EResult::failed ) );
   return;
}


void CSubject::hintAffirmed(const char* text)
{
   int c;
   
   printf("%s\n", text);
   printf("Press any key to continue.\n");
   
   while( ( c = getc(stdin) ) < 0 )
   {
      
   }
   return;
}


/*--- Fin ------------------------------------------------------------------*/
