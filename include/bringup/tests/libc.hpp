#ifndef BRINGUP_TESTS_LIBC_HPP
#define BRINGUP_TESTS_LIBC_HPP
/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for checkng libc functionality
 * 
 * Runs strtol() and malloc()
 * 
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/bringup.hpp>


/*--- Declaration ----------------------------------------------------------*/


class CTestLibc: public CSubject
{
   public:
      CTestLibc(): CSubject("Libc")
      { };
      virtual int run() override;
};


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_TESTS_LIBC_HPP
