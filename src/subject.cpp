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

int CSubject::testAssert(const char *test, bool assertion, int value, EResult eResult /*=EResult::failed*/ )
{
   m_pResults->push_back( CResult(this, test, ( assertion ? EResult::ok : eResult), value  ) );
   return( assertion ? 0 : -1 );
}

int CSubject::testAssertZero(const char *test, int value)
{
   return( testAssert(test, value==0, value) );
}

int CSubject::testAssertSilent(const char *test, bool assertion, int value)
{
   if(!assertion)
   {
      return( testAssert( test, assertion, value) );
   }
   return(0);
}

int CSubject::testInfo(const char *test, int value)
{
   m_pResults->push_back( CResult( this, test, EResult::info, value  ) );

   return( 0 );
}


/*--- Fin ------------------------------------------------------------------*/
