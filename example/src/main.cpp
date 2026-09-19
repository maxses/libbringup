/**---------------------------------------------------------------------------
 *
 * @file       main.cpp
 * @brief      Example for integration of libfosh
 *
 *  \date      20260706
 *  \author    Maximilian Seesslen <src@seesslen.net>
 *  \copyright SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/bringup.hpp>
#include <lepto/crc32.h>


/*--- Implementation -------------------------------------------------------*/


class CSubjectCrc: public CSubject
{
   public:
      CSubjectCrc(): CSubject( "CRC32")
       {
          
       }
      virtual void run() override final
      {
         testAssert( "Hello World!", calcCrc32("Hello World!", 12) == 0x1C291CA3 );
      }
};


int main( int argc, const char* argv[] )
{
   CBringup bringup;
   
   bringup.addTest( new CSubjectCrc() );
   
   CBringupWriterMd writer(bringup);
   
   writer.printSoftwareInfo();
   writer.printProtocoll();

   return( 0 );
}


/*--- Fin ------------------------------------------------------------------*/
