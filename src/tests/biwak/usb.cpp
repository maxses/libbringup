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


#include <bringup/tests/biwak/usb.hpp>
#include <biwak/usb.hpp>


/*--- Implementation -------------------------------------------------------*/


void CTestUsb::run( )
{
   #if defined(USE_USB)
   CUsbDevice *usbDevice;
   CUsbClass *hid;

   usbDevice=new CUsbDevice( m_usb );
   //hid=new CUsbClassHid( m_usb, *usbDevice);
   hid=new CUsbClass( m_usb, *usbDevice, usbClassHid);
   usbDevice->registerClass( hid );
   m_usb.start(usbDevice);

   // Need a while to connect with host
   msleep(2500 * USECS_PER_MSEC);

   // Codes:
   // https://controllerstech.com/wp-content/uploads/2020/09/KEYBOARD_HELPER.pdf
   uint8_t key1[8]={0,0,24,0,0,0,0,0};    // 'u'
   uint8_t key2[8]={0,0,22,0,0,0,0,0};    // 's'
   uint8_t key3[8]={0,0,5,0,0,0,0,0};     // 'b'
   uint8_t key4[8]={0,0,40,0,0,0,0,0};    // <return>
   uint8_t key5[8]={0,0,0,0,0,0,0,0};
   m_usb.transmit(CDC_OUT_EP, key1, 8); msleep(10);
   m_usb.transmit(CDC_OUT_EP, key2, 8); msleep(10);
   m_usb.transmit(CDC_OUT_EP, key3, 8); msleep(10);
   m_usb.transmit(CDC_OUT_EP, key4, 8); msleep(10);
   m_usb.transmit(CDC_OUT_EP, key5, 8); msleep(10);

   printf("Receiving string. Press <enter> if nothing happens.\n");
   char buf[0x10];
   memset(buf, 0, 0x10);
   fgets(buf, 0x10, stdin);
   for(int i1=0; (i1<0x10) && buf[i1]; i1++)
   {
      if( (buf[i1]=='\n') || (buf[i1]=='\r') )
         buf[i1]=0;
   }
   printf("String: %s / %d\n", buf, strlen(buf));
   testAssert("Virtual Keyboard", !strcmp(buf, "usb"), strlen(buf));
   #endif

   return;
}


/*--- Fin ------------------------------------------------------------------*/
