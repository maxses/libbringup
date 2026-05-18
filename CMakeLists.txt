#------------------------------------------------------------------------------
#
# \brief	CMakeLists.txt file for "libbringup"
#
#------------------------------------------------------------------------------


cmake_minimum_required(VERSION 3.11)

project( bringup )

find_package( Lepto REQUIRED )
# Is shipped by liblepto
find_package( GitVersion REQUIRED )

set(
   SOURCES
      src/bringup.cpp
      src/bringupWriter.cpp
      src/bringupWriterMd.cpp
      src/bringupWriterText.cpp
      src/subject.cpp
      src/tests/libc.cpp
      src/tests/crc.cpp
      ${GIT_VERSION_HEADER}
)

set(
   HEADERS
      include/bringup/bringup.hpp
      include/bringup/tests/crc.hpp
      include/bringup/tests/libc.hpp
)

if( USE_BIWAK )

   set(
      SOURCES
         ${SOURCES}
         include/bringup/tests/biwak.hpp
         include/bringup/tests/biwak/all.hpp
         include/bringup/tests/biwak/button.hpp
         include/bringup/tests/biwak/eeprom.hpp
         include/bringup/tests/biwak/output.hpp
         include/bringup/tests/biwak/pwm.hpp
         include/bringup/tests/biwak/uart.hpp
         include/bringup/tests/biwak/optionBytes.hpp
         include/bringup/tests/biwak/stack.hpp
         include/bringup/tests/biwak/retain.hpp
         include/bringup/tests/biwak/adcLine.hpp
         include/bringup/tests/biwak/flashIntern.hpp
         include/bringup/tests/biwak/touch.hpp
         include/bringup/tests/biwak/input.hpp
         include/bringup/tests/biwak/rtcI2c.hpp
         include/bringup/tests/biwak/rtc.hpp
         include/bringup/tests/biwak/flashQspi.hpp
         include/bringup/tests/biwak/flashSpi.hpp
         include/bringup/tests/biwak/usb.hpp
         include/bringup/tests/biwak/can.hpp
         include/bringup/tests/biwak/gdisplay.hpp
         include/bringup/tests/biwak/pwm_light.hpp
         include/bringup/tests/biwak/sd.hpp
         src/tests/biwak/output.cpp
         src/tests/biwak/uart.cpp
         src/tests/biwak/button.cpp
         src/tests/biwak/pwm.cpp
         src/tests/biwak/eeprom.cpp
         src/tests/biwak/optionBytes.cpp
         src/tests/biwak/stack.cpp
         src/tests/biwak/retain.cpp
         src/tests/biwak/adcLine.cpp
         src/tests/biwak/flashIntern.cpp
         src/tests/biwak/touch.cpp
         src/tests/biwak/rtcI2c.cpp
         src/tests/biwak/rtc.cpp
         src/tests/biwak/flashQspi.cpp
         src/tests/biwak/flashSpi.cpp
         src/tests/biwak/usb.cpp
         src/tests/biwak/can.cpp
         src/tests/biwak/gdisplay.cpp
         src/tests/biwak/pwm_light.cpp
         src/tests/biwak/sd.cpp
         src/tests/biwak/input.cpp
   )

   if( USE_HWINFO )

      set(
         SOURCES
            ${SOURCES}
            include/bringup/tests/biwak/hwdata.hpp
            src/tests/biwak/hwdata.cpp
      )

   endif( USE_HWINFO )

endif( USE_BIWAK )


add_library( 
   ${PROJECT_NAME} 
   STATIC
      ${SOURCES}
      ${HEADERS}
)

target_link_libraries(
   ${PROJECT_NAME}
   lepto
)

if( USE_BIWAK )
   target_link_libraries(
      ${PROJECT_NAME}
      biwak
   )
endif( USE_BIWAK )

if( USE_HWINFO )
   target_link_libraries(
      ${PROJECT_NAME}
      hwinfo
   )
endif( USE_BIWAK )

target_include_directories(
   ${PROJECT_NAME} 
   INTERFACE
      "${CMAKE_CURRENT_SOURCE_DIR}/include"
   PRIVATE
      "${CMAKE_CURRENT_SOURCE_DIR}/include"
)


#------------------------------------------------------------------------------
