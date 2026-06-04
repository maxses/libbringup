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


void CBringupWriterText::printHeader(const char *text) const
{
   printf( "\n"
           "%s:\n"
           "==============\n", text);

   return;
};

void CBringupWriterText::tableHeader(const char *desc, const char *value) const
{
   printf("\n"
          "%s %s\n", desc, value);
   printf("----------------\n");

   return;
}

void CBringupWriterText::tableRow(const char *desc, const char *value) const
{
      printf("   %s:", desc);
      for(unsigned int i1=0; i1 < (40-strlen(desc)); i1++)
      {
         fputc('.', stdout);
      }
      printf("%s\n", value);

      return;
}

void CBringupWriterText::tableRow(const char *desc, int value) const
{
      printf("   %s:", desc);
      for(unsigned int i1=0; i1 < (40-strlen(desc)); i1++)
      {
         fputc('.', stdout);
      }
      printf("%d\n", value);

      return;
}


/*--- Fin ------------------------------------------------------------------*/
