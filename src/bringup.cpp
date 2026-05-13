/**---------------------------------------------------------------------------
 *
 * @brief  Bringup
 * 
 * Class for handling tests for checking hardware functionality and
 * to perform an bringup.
 * 
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/


/*--- Includes -------------------------------------------------------------*/


#include <bringup/bringup.hpp>
#include <biwak/flash_spi.hpp>
#include <biwak/led.hpp>
#if defined(STM32G4)
   #include <biwak/fdcan.hpp>
   #define USE_CAN
   #define CCan CFDCan
#else
   #if ( ! defined ( STM32L0 ) ) && ( ! defined ( STM32L1 ) )
      #include <biwak/can.hpp>
      #define USE_CAN
   #endif
#endif
#include <biwak/rtc.hpp>
//#include <stm/stm32_cortex.h>    // reset
#include <biwak/flash_i2c.hpp>
#include <biwak/uart.hpp>
#include <biwak/pwm.hpp>
//#include <lepto/time.hpp>
#include <biwak/input.hpp>
#include <biwak/adc.hpp>
#include <biwak/adc_line.hpp>
#include <biwak/gdisplay.h>
#if defined (USE_USB)
   #include <biwak/usb.hpp>
   #include <biwak/usb_class.h>
   #include <biwak/usb_device.h>
#endif
#include <biwak/sysTimer.hpp>

#if defined ( HOST )  || ! defined( STM32 )
   #include <termios.h>       // tcgetattr
   #include <errno.h>         // errno
   #include <fcntl.h>         // fcntl
#endif


/*--- Implementation -------------------------------------------------------*/


CBringup::CBringup( int tests /*=18*/, int results /*=24*/ )
   :m_tests( tests )
   ,m_results( results )
{
   // Disable ECHO on Linux systems
   #if ! defined( STM32 )
   struct termios term, term_orig;

   if(tcgetattr(0, &term_orig))
   {
      printf("tcgetattr failed (%d)\n", errno);
      return;
    }

    term = term_orig;
    term.c_lflag &= ~( ICANON | ECHO );

    if (tcsetattr(0, TCSANOW, &term))
    {
      printf("tcsetattr failed\n");
      exit(-1);
    }

    int flags = fcntl(stdin->_fileno, F_GETFL, 0);
    fcntl(stdin->_fileno, F_SETFL, flags | O_NONBLOCK); // non blocking

   #endif
}

int CBringup::addTest( CSubject *issue)
{
   m_tests << issue;
   issue->setResultList( &m_results );
   return( issue->run() );
}

#if 0
void CBringup::printProtocoll()
{
  const char *currentGroup;
  printf( "Test protocol:\n"
          "==============\n\n");
  for(CResult &result: m_results)
  {
     if( currentGroup != result.getGroup() )
     {
         currentGroup = result.getGroup();
         printf( "Group %s:\n", currentGroup);
         currentGroup = result.getGroup();
     }
     printf( "Test %s:\n", result.getTestString() );
  }
}
#endif

CBringupUserInput::CBringupUserInput(int target, int timeout )
   :m_target(target)
   ,m_timeout(timeout)
   ,m_result(-1)
{
   m_timer=lrNow();
}

bool CBringupUserInput::loop()
{
   int c;

   biwakEventLoop();

   if( lrElapsedSeconds(&m_timer, m_timeout))
   {
      m_result=2;
      return(false);
   }

   if( ( c = getc(stdin) ) >= 0 )
   {
      m_result= ( c == m_target ) ? 0 : 1;
      return(false);
   };

   return(true);
};

int CBringupUserInput::result() const
{
   return(m_result);
}

int CSubject::hintAffirmed(const char* text)
{
   int c;
   
   printf("%s\n", text);
   printf("Press any key to continue.\n");
   
   while( ( c = getc(stdin) ) < 0 )
   {
      
   }
   return(0);
}


/*--- Fin ------------------------------------------------------------------*/
