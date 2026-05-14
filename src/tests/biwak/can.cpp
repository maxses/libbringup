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


/*--- Implementation -------------------------------------------------------*/


void CTestCan::run()
{
   int sta=0;

   #if defined ( USE_CAN )
   SCanMessage message;
   // canId can be 0 and 0x7FF for standard id. To be TDT compatible, use
   // function code "0xf" which is reserved for such tests and should be ignored
   // by other participants.
   canId_t canId=0x7EF;
   int canLen=0x5;
   lrtimer_t startTime;
   SCanMessage *pMessage;

   message.setId(canId);
   message.setData(canLen, (const unsigned char *)"Hello");

   hintAffirmed("Start CANPong on PC. CANPong is in 'libcampo' repository. It is available in this build directory.");
   startTime=lrNow();

   sta=m_can.transmit(message);
   testAssert("Transmit CAN message", sta==0 , 0);
   sta=2;

   do{
      lDebug("Loop");
      pMessage=m_can.m_rxBuffer.bottomEntry();
      if(pMessage)
      {
         lDebug("Message in: ID=0x%X, len=%d", pMessage->getId()
                        , pMessage->getLen());
         if( pMessage->getId() == canId + 0x10)
         {
            sta=testAssert("CAN size from CANPong", pMessage->getLen() == canLen, pMessage->getLen());
            sta=testAssert("CAN mirrored message from CANPong"
                           , memcmp(pMessage->getData(), "olleH", 5)==0
                           , pMessage->getId());
            lDebug("   Data: %s", pMessage->getData());
         }
         m_can.m_rxBuffer.dropEntry();
      }

      if(sta)
      {
         msleep(1000);
      }
      biwakEventLoop();
   }while( sta && ( lrElapsedMSeconds(startTime) < MSEC_PER_SEC * 1 ) );

   sta = testAssert("Received CAN message", sta == 0 , 0);
   #endif

   return;
}


/*--- Fin ------------------------------------------------------------------*/
#endif // ? ! STM32L0
