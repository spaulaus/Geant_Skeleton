cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(Geant_Skeleton)

#if user does not specify prefix we assign it to the exec directory
if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
	message(STATUS "Install Prefix not specified.")
	file(MAKE_DIRECTORY exec)
	get_filename_component(INSTALL_DIR ${CMAKE_SOURCE_DIR}/exec REALPATH)
	set(CMAKE_INSTALL_PREFIX ${INSTALL_DIR} CACHE PATH "Install Prefix" FORCE)
endif ()
message(STATUS "Installing to ${CMAKE_INSTALL_PREFIX}")

#Define the default build type
IF(NOT CMAKE_BUILD_TYPE)
	SET(CMAKE_BUILD_TYPE Release CACHE STRING "Build type, options are: None Debug Release RelWithDebInfo MinSizeRel."
		FORCE)
	message(STATUS "Build type not defined, using default.")
ENDIF(NOT CMAKE_BUILD_TYPE)
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

#Use C++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#Use nice color output
if (CMAKE_COMPILER_IS_GNUCXX)
	if (${CMAKE_CXX_COMPILER_VERSION} VERSION_GREATER "4.9")
		#Make compiler messages nice with colored tags.
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color=auto")
	endif(${CMAKE_CXX_COMPILER_VERSION} VERSION_GREATER "4.9")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic")
endif(CMAKE_COMPILER_IS_GNUCXX)

#----------------------------------------------------------------------------
# Find Geant4 package, activating all available UI and Vis drivers by 
# default. You can set WITH_GEANT4_UIVIS to OFF via the command line or ccmake/cmake-gui to build a batch mode only executable.
#
option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()

#--------------------------------------------------------------------------
# Setup Geant4 include directories and compile definitions
# Setup include directory for this project
#
include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)

install(DIRECTORY share DESTINATION ${CMAKE_INSTALL_PREFIX})

add_subdirectory(src)
