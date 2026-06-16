#ifndef BRINGUP_RESULT_HPP
#define BRINGUP_RESULT_HPP
/**---------------------------------------------------------------------------
 *
 * @brief  Single result of an test
 * 
 * Holds an description of an test and the result.
 * 
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Declaration ----------------------------------------------------------*/


enum class EResult
{
   unknown=0,
   ok,
   warning,
   failed,
   info,
   dummy,
   end
};

class CSubject;

class CResult
{
private:

   const char *m_testString;
   EResult m_eResult;
   const CSubject* m_pSubject;

public:
   CResult(  )
      :m_testString(nullptr)
      ,m_pSubject( 0 )
   {
   };
   CResult(const CSubject* subject, const char *testString, EResult eResult)
      :m_testString( testString )
      ,m_eResult( eResult )
      ,m_pSubject( subject )
   {};
   const char *getTestString() const
   {
      return( m_testString );
   }
   EResult getResult() const
   {
      return( m_eResult );
   }
   bool belongsTo(const CSubject* subject) const
   {
      return( m_pSubject==subject );
   }
};


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_RESULT_HPP
