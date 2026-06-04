#ifndef BIWAK_TESTER_H
#define BIWAK_TESTER_H
/**---------------------------------------------------------------------------
 *
 * @brief  Test funcktions to check periphery and MCU configuration
 * 
 * See implementation for further information.
 * 
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <lepto/list.hpp>
#include <bringup/subject.hpp>
#include <biwak/sysTimer.hpp>


/*--- Declaration ----------------------------------------------------------*/


class CBringup
{
   private:
      CList<const CSubject*> m_tests;
      CList <CResult> m_results;

   public:
      CBringup( int tests = 18, int results = 24 );
      void addTest( CSubject *issue);
      const CList<const CSubject *> &tests() const {return(m_tests);};
      const CList<CResult> &results() const {return(m_results);};
};


class CBringupWriter
{
      const CBringup &m_bringup;
   public:
      CBringupWriter(const CBringup &bringup)
         :m_bringup(bringup)
      {}
      void printProtocoll() const;
      void printSoftwareInfo() const;
      virtual void printHeader(const char *text) const =0;
      virtual void tableHeader(const char *desc, const char *value) const =0;
      virtual void tableRow(const char *desc, const char *value) const =0;
      virtual void tableRow(const char *desc, int value) const =0;
};


class CBringupWriterText: public CBringupWriter
{
   public:
      CBringupWriterText(const CBringup &bringup)
         :CBringupWriter(bringup)
      {}
      virtual void printHeader(const char *text) const override;
      virtual void tableHeader(const char *desc, const char *value) const override;
      virtual void tableRow(const char *desc, const char *value) const override;
      virtual void tableRow(const char *desc, int value) const override;
};


class CBringupWriterMd: public CBringupWriter
{
   public:
      CBringupWriterMd(const CBringup &bringup)
         :CBringupWriter(bringup)
      {}
      virtual void printHeader(const char *text) const override;
      virtual void tableHeader(const char *desc, const char *value) const override;
      virtual void tableRow(const char *desc, const char *value) const override;
      virtual void tableRow(const char *desc, int value) const override;
};


class CBringupUserInput
{
      int m_target;
      int m_timeout;
      int m_result;
      lrtimer_t m_timer;

public:
      CBringupUserInput( int target, int timeout );
      bool loop();
      int result() const;
};


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BIWAK_TESTER_H
