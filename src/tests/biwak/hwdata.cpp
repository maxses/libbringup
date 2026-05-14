/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for hwdata
 * 
 * Just checks if retain block could be restored.
 * Not very complete / usefull.
 * 
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/tests/biwak/hwdata.hpp>
#include <biwak/uart.hpp>
#include <hwinfo/hwinfo.h>


/*--- Implementation -------------------------------------------------------*/


void CTestHwData::run( )
{
   int sta=0;
   struct SEepromHwData
   {
      SEepromBoardInfo boardInfo;
      char reserved[ 0x20 ];
   } __attribute ((packed));

   //SEepromHwData *hwData=(SEepromHwData *)m_data;
   sta = m_pRetain->restore();
   testAssert( "Restore", sta >= 0, sta );
   return;
}


/*--- Fin ------------------------------------------------------------------*/
