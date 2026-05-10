#ifndef BRINGUP_TESTS_ALL_HPP
#define BRINGUP_TESTS_ALL_HPP
/**---------------------------------------------------------------------------
 *
 * @brief  Header including all test headers
 * 
 * No test declared here. Keep main file clean.
 * 
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/tests/libc.hpp>
#include <bringup/tests/crc.hpp>

#if defined USE_BIWAK
#include <bringup/tests/biwak/all.hpp>
#endif


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_TESTS_ALL_HPP
