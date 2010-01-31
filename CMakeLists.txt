##############################################################################
# Basic version setup
set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS TRUE)

IF(WIN32)
    CMAKE_MINIMUM_REQUIRED(VERSION 2.4.6 FATAL_ERROR)
ELSE(WIN32)
    IF(APPLE)
        CMAKE_MINIMUM_REQUIRED(VERSION 2.6.0 FATAL_ERROR)
    ELSE(APPLE)
        CMAKE_MINIMUM_REQUIRED(VERSION 2.4.4 FATAL_ERROR)
    ENDIF(APPLE)
ENDIF(WIN32)
##############################################################################
if(COMMAND cmake_policy)
    # Works around warnings libraries linked against that don't
    # have absolute paths (e.g. -lpthreads)
    cmake_policy(SET CMP0003 NEW)

    # Works around warnings about escaped quotes in ADD_DEFINITIONS
    # statements.
    cmake_policy(SET CMP0005 NEW)

    # cmake-2.6.1 introduces policy cmp0008 decide how to treat full path libraries that do not appear to be valid library file names
    # quote from cvslog "Such libraries worked by accident in the VS IDE and Xcode generators in CMake 2.4 and below."
    if(${CMAKE_MAJOR_VERSION} EQUAL 2 AND ${CMAKE_MINOR_VERSION} GREATER 4 AND ${CMAKE_PATCH_VERSION} GREATER 0)
        cmake_policy(SET CMP0008 OLD)
    endif()
endif()
##############################################################################
cmake_minimum_required (VERSION 2.6) 
##############################################################################
project (Sentinel)

# Options
OPTION(BUILD_TESTS "Enable to build test programs." OFF)
# this could probably be auto adapted in some way be checking for current build architecture
OPTION(USE_SPECIAL_SNOW_LEOPARD_32_BIT_THINGS "sets some flags needed for using 32 bit stuff on SL" OFF)
OPTION(USE_DOUBLE_AS_REAL "Use double precsions as real datatype. Off means float" ON)
OPTION(BUILD_DEBUG "Build with debug macros enabled" OFF)

if(APPLE)
  FIND_LIBRARY(GLUT_LIB GLUT)
  FIND_LIBRARY(OPENGL_LIB OpenGL)
  FIND_LIBRARY(COCOA_LIB Cocoa)
  SET(GLUT_AND_DEPENDENCIES ${GLUT_LIB} ${OPENGL_LIB} ${COCOA_LIB})
  
endif(APPLE)

add_definitions(-std=c99)

if(BUILD_DEBUG)
  ADD_DEFINITIONS(-DFW_DEBUG)
endif(BUILD_DEBUG)

if(USE_DOUBLE_AS_REAL)
  ADD_DEFINITIONS(-DFW_REAL_IS_DOUBLE)
endif(USE_DOUBLE_AS_REAL)

if(USE_SPECIAL_SNOW_LEOPARD_32_BIT_THINGS)
	ADD_DEFINITIONS(-m32)
	SET (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -arch i386")
endif(USE_SPECIAL_SNOW_LEOPARD_32_BIT_THINGS)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})


include_directories (${Sentinel_SOURCE_DIR}/include/ ${Sentinel_SOURCE_DIR}/src/app /usr/local/include) 

# Build Libs 
ADD_SUBDIRECTORY(src/fw)

# Build test apps
ADD_SUBDIRECTORY(src/app)

##############################################################################
# post build copy of data, only works on *nix platforms?
execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink ${Sentinel_SOURCE_DIR}/data ${CMAKE_BINARY_DIR}/data)
##############################################################################
