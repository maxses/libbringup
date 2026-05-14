#ifndef BRINGUP_TESTS_CRC_HPP
#define BRINGUP_TESTS_CRC_HPP
/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for checkng CRC functionality
 * 
 * The crc functions from liblepto are used. But those functions may
 * be overloaded by libbiwak. So on target the CRC hardware unit is
 * used
 * 
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/bringup.hpp>


/*--- Declaration ----------------------------------------------------------*/


class CTestCrc: public CSubject
{
   public:

      CTestCrc(  )
         : CSubject("Crc")
      {
      };
      virtual void run() override;
};


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_TESTS_CRC_HPP
