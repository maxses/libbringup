/**---------------------------------------------------------------------------
 *
 * @brief  Bringup
 * 
 * Class for handling tests for checking hardware functionality and
 * to perform an bringup.
 * 
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/bringup.hpp>
#include "git_version.h"


/*--- Implementation -------------------------------------------------------*/


#if IS_ENABLED( CONFIG_LEPTO_LOG_USE_PRETTY_PRINT )
static const char *resultStrings[]
{
   [(int)EResult::ok] = "\e[92mOk\e[39m",
   [(int)EResult::warning] = "\033[91mWarning\e[39m",
   [(int)EResult::failed] = "\033[91mFailed\e[39m",
   [(int)EResult::info] = "\033[92mInfo\e[39m",
   [(int)EResult::dummy] = "---",
};
#else
static const char *resultStrings[]
{
   [(int)EResult::unknown] = "UK",
   [(int)EResult::ok] = "Ok",
   [(int)EResult::warning] = "Warning",
   [(int)EResult::failed] = "Failed",
   [(int)EResult::info] = "Info",
   [(int)EResult::dummy] = "---",
};
#endif

#define INFO(submodule) GIT_REV ## submodule

void CBringupWriter::printSoftwareInfo() const
{
   #if IS_ENABLED( CONFIG_LEPTO_LOG_DOWNSIZE )
      printHeader("SW info");
      tableHeader("Revs","");
   #else
      printHeader("Software info");
      tableHeader("Revisions","");
   #endif

   tableRow("Bringup", INFO( ));

   #if defined GIT_REV_libbringup
      tableRow("libbringup", INFO(_libbringup) );
   #endif
   
   #if defined GIT_REV_libbiwak
      tableRow("libbiwak", INFO(_libbiwak) );
   #endif

   #if defined GIT_REV_libarena
      tableRow("libarena", INFO(_libarena) );
   #endif

   tableRow("liblepto", INFO(_liblepto) );

   #if defined GIT_REV_libHALWrapper
      tableRow("libHALWrapper", INFO(_libHALWrapper) );
   #endif

   return;
}

void CBringupWriter::printProtocoll() const
{
   int counter[(int)EResult::end]{0};

   printHeader("Test protocol");
   //const CList <const CSubject *> tests=m_bringup.tests();

   for(const CSubject *issue: m_bringup.tests() )
   {
     tableHeader(issue->getTopic(), "" );
     for(const CResult &result: issue->results() )
     {
        if( result.belongsTo( issue ) )
        {
           if(result.getResult()==EResult::info)
           {
              char buf[10];
              snprintf( buf, 10, "%d", result.value() );
              tableRow( result.getTestString(), buf, 0 );
           }
           else
           {
               tableRow(result.getTestString(), resultStrings[ (int)result.getResult() ]
                 , (int)result.value()
                 );
           }
           counter[ (int)result.getResult() ]++;
        }
     }
   }

   #if IS_ENABLED( CONFIG_LEPTO_LOG_DOWNSIZE )
      printHeader("Sum.");
      tableHeader("Tests", "");
      tableRow( "Tot. ok", counter[ (int)EResult::ok ]);
      tableRow( "Tot. warnings", counter[ (int)EResult::warning ]);
      tableRow( "Tot. failes", counter[ (int)EResult::failed ]);
      tableRow( "Subj.", m_bringup.tests().count() );
      tableRow( "Res.", m_bringup.results().count() );
   #else
      printHeader("Summary");
      tableHeader("Tests", "");
      tableRow( "Total ok", counter[ (int)EResult::ok ]);
      tableRow( "Total warnings", counter[ (int)EResult::warning ]);
      tableRow( "Total failes", counter[ (int)EResult::failed ]);
      tableRow( "tests", m_bringup.tests().count() );
   #endif

   return;
}


/*--- Fin ------------------------------------------------------------------*/
