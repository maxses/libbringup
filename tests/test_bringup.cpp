//----------------------------------------------------------------------------
//
// \brief   Test for libbringup
///
/// \date   20260919
/// \author Maximilian Seesslen <src@seesslen.net>
///
//----------------------------------------------------------------------------


//---Includes-----------------------------------------------------------------


#if defined ( CATCH_V3 )
   #include <catch2/catch_test_macros.hpp>
#elif defined ( CATCH_V2 )
   #include <catch2/catch.hpp>
#elif defined ( CATCH_V1 )
   #include <catch/catch.hpp>
#else
   #error "Either 'catch' or 'catch2' has to be installed"
#endif

#include <bringup/bringup.hpp>


//---Implementation-----------------------------------------------------------


// No tests so far...

TEST_CASE( "Bringup", "[default]" )
{
   SECTION( "Bringup" )
   {
      REQUIRE ( 1 != -1 );
   }
}; // TEST_CASE


//---fin----------------------------------------------------------------------
