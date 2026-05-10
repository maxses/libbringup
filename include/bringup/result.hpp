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
   ok,
   warning,
   failed,
   info,
   dummy,
   end
};


class CResult
{
private:

   const char *m_testString;
   EResult m_eResult;
   int m_value;

public:
   CResult()
      :m_testString(nullptr)
      ,m_eResult( EResult::failed )
      ,m_value( 0 )
   {
   };
   CResult(const char *testString, EResult eResult, int value)
      :m_testString( testString )
      ,m_eResult( eResult )
      ,m_value( value )
   {};
   const char *getTestString() const
   {
      return( m_testString );
   }
   const EResult getResult() const
   {
      return( m_eResult );
   }
   int value() const
   {
      return (m_value);
   }
};


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_RESULT_HPP
