/**---------------------------------------------------------------------------
 *
 * @brief  Bringup tests for internal flash
 * 
 * Write patterns and expect correct read back.
 * 
 * @date   20220525
 * @author Maximilian Seesslen <src@seesslen.net>
 * @copyright  SPDX-License-Identifier: Apache-2.0
 *
 *--------------------------------------------------------------------------*/



/*--- Includes -------------------------------------------------------------*/


#include <bringup/tests/biwak/flashIntern.hpp>
#include <biwak/flash_intern.hpp>


/*--- Implementation -------------------------------------------------------*/


void CTestFlashIntern::run( )
{
   int sta=0;
   uint32_t patterns[]
       {  0xDEADBEEF, 0xF0F0F0F0, 0x55555555, 0xAAAAAAAA };

   CFlashIntern flash;

   uint32_t *start = (uint32_t *)flash.userStart();
   uint32_t *end = (uint32_t *)(flash.flashEnd() - 4);
   (void)end;

   int pageCount=0;

   printf( "Start: 0x%p\n", (void*)flash.flashStart() );
   printf( "End: 0x%p\n", (void*)flash.flashEnd() );
   printf( "Size: 0x%x\n", flash.totalSize() );

   #if 0
      printf( "User start: 0x%p\n", (void*)flash.userStart() );
      printf( "User size: 0x%x\n", (int)flash.userSize() );

      flash.erasePage( flash.userStart(), 1);
      flash.writeData( flash.userStart(), (char*)&value1, 4 );
      sta=testAssert( "Start", *start == 0xDEADBEEF, *start );
      // can write 0xFFFF0000 , result will be 0xDEAD0000

      // Write only 2 bytes
      flash.erasePage( flash.flashEnd()-4, 1);
      flash.writeData( flash.flashEnd()-4, &value2, 2 );
      sta=testAssert( "End", *end == 0xFFFF5678, *end );

      flash.writeData( flash.userStart()+4, &s.value, 4 );
   #endif

   // The real flash size of STM32 controllers is usually bigger as sold.
   // But like with missing address lines the apllications flash will be
   // overwritten at some point.
   do
   {
      printf("Address: %p (0x%X) : ", (void*)start,
               (unsigned int)flash.eraseBlockSize());
      for(int pattern=0; ( pattern < (int)sizeof(patterns) / (int)sizeof(patterns[0]) ) && ! sta; pattern++)
      {
         printf("#");
         flash.erasePage( (address_t)start, 1);
         for(int i2=0; i2<flash.eraseBlockSize() / (int)sizeof(start[0]); i2++)
         {
            uint32_t p=patterns[pattern] + pattern + pageCount + i2;
            (void)p;
            #if defined FLASH_32BIT_ACCESS
               flash.writeData32( (address_t)&start[i2], (char*)&p, 4 );
            #else
               abort();
            #endif
         }
         for(int i2=0; i2<flash.eraseBlockSize() / (int)sizeof(start[0]); i2++)
         {
            uint32_t p=patterns[pattern] + pattern + pageCount + i2;
            if( ! ( start[i2] == p ) )
            {
               sta=33;
               break;
            }
         }
      }
      pageCount++;
      printf("\n");
      if( ! sta )
      {
         start+= ( flash.eraseBlockSize() / sizeof( start[0] ) );
      }
   }while( ( sta==0 ) && ( (address_t)start < 0x8008000 ) );

   if(sta)
   {
      printf("Error in page at: %p\n", start);
      
      #if defined STM32
         testFatal( "Err" );
      #else
         testFatal( "Err" );
      #endif
   }

   //flash.writeData( flash.flashEnd()-2, &zero, 2 );
   //sta=testAssert( "End", *end == 0x12345678, *end );

   return;
}


/*--- Fin ------------------------------------------------------------------*/
