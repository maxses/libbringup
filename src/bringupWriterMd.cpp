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
#include <stdio.h>         // printf



/*--- Implementation -------------------------------------------------------*/


void CBringupWriterMd::printHeader(const char *text) const
{
   printf( "\n# %s\n" , text);

   return;
};


void CBringupWriterMd::tableHeader(const char *desc, const char *value) const
{
   printf("<br>\n"
          "\n|%s |%s |\n"
          "|:-- |:-- |\n", desc, value);
   return;
}


void CBringupWriterMd::tableRow(const char *desc, const char *value) const
{
   printf( "| %s | %s", desc, value);
   printf( "|\n");

   return;
}


void CBringupWriterMd::tableRow(const char *desc, int value) const
{
   printf( "| %s | %d |\n", desc, value);
   return;
}


/*--- Fin ------------------------------------------------------------------*/
