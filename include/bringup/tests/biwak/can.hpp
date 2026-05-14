#ifndef BRINGUP_TESTS_BIWAK_CAN_HPP
#define BRINGUP_TESTS_BIWAK_CAN_HPP
/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for CAN
 *
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/bringup.hpp>
#include <biwak/can.hpp>


/*--- Declaration ----------------------------------------------------------*/


class CTestCan: public CSubject
{
      CCan &m_can;

   public:

      CTestCan( CCan &can  )
         : CSubject("CAN")
         ,m_can( can )
      { };
      virtual void run() override;
};


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_TESTS_BIWAK_CAN_HPP
