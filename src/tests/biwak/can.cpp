#if ! defined STM32L0
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


#include <bringup/tests/biwak/can.hpp>
#include <biwak/can.hpp>
#include <lepto/units.h>


/*--- Implementation -------------------------------------------------------*/


void CTestCan::run()
{
   int sta=0;

   #if defined ( USE_CAN ) || 1
   SCanMessage message;
   // canId can be 0 and 0x7FF for standard id. To be TDT compatible, use
   // function code "0xf" which is reserved for such tests and should be ignored
   // by other participants.
   canId_t canId=0x7EF;
   int canLen=0x5;
   lrtimer_t startTime;
   SCanMessage *pMessage;
   bool finished=false;

   message.setId(canId);
   message.setData(canLen, (const unsigned char *)"Hello");

   hintAffirmed("Start CANPong on PC. CANPong is in 'libcampo' repository. It is available in this build directory.");
   startTime=lrNow();

   sta=m_can.transmit(message);
   testAssert("Transmit CAN message", sta==0 );
   sta=2;

   do{
      lDebug("Loop");
      pMessage=m_can.m_rxBuffer.frontEntry();
      if(pMessage)
      {
         printf( "[0x%X]\n", (int)pMessage->getId() );
         lDebug("Message in: ID=0x%X, len=%d", pMessage->getId()
                        , pMessage->getLen());
         if( pMessage->getId() == canId + 0x10)
         {
            testAssert("CAN size from CANPong", pMessage->getLen() == canLen );
            finished=memcmp(pMessage->getData(), "olleH", 5)==0;
            testAssert("CAN mirrored message from CANPong"
                           , finished );
            lDebug("   Data: %s", pMessage->getData());
         }
         else
         {
            printf("X\n");
         }
         m_can.m_rxBuffer.dropFront();
      }

      if( ! finished )
      {
         msleep(1);
      }
      biwakEventLoop();
   }while( ( !finished ) && ( lrElapsedMSeconds(startTime) < (int)MSEC_PER_SEC * 1 ) );

   testAssert("Received CAN message", finished == true );
   #endif

   return;
}


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! STM32L0
