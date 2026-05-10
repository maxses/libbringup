#ifndef BRINGUP_TESTS_BIWAK_FLASH_USB_HPP
#define BRINGUP_TESTS_BIWAK_FLASH_USB_HPP
/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for USB
 * 
 * Writes strings to USB keyboard andd expects them to be received via
 * stdin. This requires an running terminal on host which shoud be the
 * case
 * 
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/bringup.hpp>


/*--- Declaration ----------------------------------------------------------*/


class CUsb;

class CTestUsb: public CSubject
{
      CUsb &m_usb;

   public:

      CTestUsb( CUsb &usb  )
         : CSubject("USB")
         ,m_usb( usb )
      { };
      virtual int run() override;
};


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! BRINGUP_TESTS_BIWAK_FLASH_USB_HPP
