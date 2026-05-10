#ifndef BRINGUP_TESTS_HWDATA_HPP
#define BRINGUP_TESTS_HWDATA_HPP
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


#define CONFIG_VAGUS_HWINFO_V6
#include <bringup/bringup.hpp>
#include <biwak/retain.h>


/*--- Declaration ----------------------------------------------------------*/


class CTestHwData: public CSubject
{
      CRetain *m_pRetain;
      void *m_data;
      int m_major;
      int m_minor;

   public:

      CTestHwData(CRetain *retain, void *data, int major, int minor )
         : CSubject("HwData")
         ,m_pRetain( retain )
         ,m_data(data)
         ,m_major(major)
         ,m_minor(minor)
      { };
      virtual int run() override;
};



/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_TESTS_HWDATA_HPP
