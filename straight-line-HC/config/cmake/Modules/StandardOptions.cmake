# minus/config/cmake/MINUSStandardOptions.cmake
#
# This CMake module is included by minus/CMakeLists.txt.  It adds
# several minus-standard testing and build options to the project:
#
#  MINUS_BUILD_SHARED_LIBS
#  BUILD_TESTING
#  BUILD_EXAMPLES
#  WARN_DEPRECATED
#  WARN_DEPRECATED_ONCE
#  WARN_DEPRECATED_ABORT
#
# These options may be introduced into client projects with this line:
#
#  include(${MINUS_CMAKE_DIR}/MINUSStandardOptions.cmake)
#
# This module may be automatically included by UseMINUS.cmake.
# See minus/config/cmake/UseMINUS.cmake for details.
#

# Everything here should be valid for both the minus source and for
# client projects.

include(CTest)

if( WIN32 )
  option( BUILD_SHARED_LIBS "Build shared libraries." OFF)
  if (BUILD_SHARED_LIBS)
    # On windows, we need to export symbols for shared builds
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS "TRUE")
  endif()
else()
  option( BUILD_SHARED_LIBS "Build shared libraries." OFF)
endif()
set( MINUS_BUILD_SHARED_LIBS ${BUILD_SHARED_LIBS} )
mark_as_advanced(BUILD_SHARED_LIBS)

option( WARN_DEPRECATED "Enable runtime warnings for deprecated functions?" ON )
option( WARN_DEPRECATED_ONCE "Only warn once per function (if runtime warnings are enabled)?" ON )
option( WARN_DEPRECATED_ABORT "Abort on executing a deprecated function (if runtime warnings are enabled)?" OFF )

mark_as_advanced( WARN_DEPRECATED WARN_DEPRECATED_ONCE WARN_DEPRECATED_ABORT )

if(WARN_DEPRECATED)
  add_definitions( -DMINUS_WARN_DEPRECATED )
  if(WARN_DEPRECATED_ONCE)
    add_definitions( -DMINUS_WARN_DEPRECATED_ONCE )
  endif()
  if(WARN_DEPRECATED_ABORT)
    add_definitions( -DMINUS_WARN_DEPRECATED_ABORT )
  endif()
endif()


# Taken from ITK build environment
# On Visual Studio 8 MS deprecated C. This removes many security warnings
if(WIN32)
       if(NOT MINGW)
         if(NOT MINUS_ENABLE_VISUAL_STUDIO_DEPRECATED_C_WARNINGS)
           add_definitions(
             -D_CRT_FAR_MAPPINGS_NO_DEPRECATE
             -D_CRT_IS_WCTYPE_NO_DEPRECATE
             -D_CRT_MANAGED_FP_NO_DEPRECATE
             -D_CRT_NONSTDC_NO_DEPRECATE
             -D_CRT_SECURE_NO_DEPRECATE
             -D_CRT_SECURE_NO_DEPRECATE_GLOBALS
             -D_CRT_SETERRORMODE_BEEP_SLEEP_NO_DEPRECATE
             -D_CRT_TIME_FUNCTIONS_NO_DEPRECATE
             -D_CRT_VCCLRIT_NO_DEPRECATE
             -D_SCL_SECURE_NO_DEPRECATE
             )
         endif()
         # With MS compilers on Win64, we need the /bigobj switch, else generated
         # code results in objects with number of sections exceeding object file
         # format.
         # see http://msdn.microsoft.com/en-us/library/ms173499.aspx
         if(MSVC_VERSION GREATER 1310)
           set(MINUS_REQUIRED_CXX_FLAGS "${MINUS_REQUIRED_CXX_FLAGS} /bigobj")
         endif()
       endif()
endif()
