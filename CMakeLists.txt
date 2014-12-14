cmake_minimum_required(VERSION 2.8.12.1)

###########################################################################
## Project Settings                                                      ##
## ----------------                                                      ##
## Can be changed across projects                                        ##
###########################################################################
set(PROJECT_NAME "Pong_Clone")
set(IS_LIBRARY false)
set(HAS_TESTS true)
set(HAS_LIBS true)
set(HAS_RESOURCES true) # will copy the resources/ folder to the installation directory
set(SDL2_PROJECT true)
set(SDL2_EXTENSIONS ttf image gfx)
set(BOOST_PROJECT true)
set(BOOST_COMPONENTS system chrono date_time thread)
include(CMake/user_defined_settings.cmake)


###########################################################################
## Project build                                                         ##
## -------------                                                         ##
## Should probably not be changed across projects.                       ##
###########################################################################
project(${PROJECT_NAME})

###### Compiler flags ######
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -pedantic -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-Og -ggdb -DDEBUG")

###### Library inclusion #######
if (${SDL2_PROJECT})
	include(CMake/add_lib_sdl.cmake)
endif()

foreach (extension_ ${SDL2_EXTENSIONS})
	include(CMake/add_lib_sdl_${extension_}.cmake)
endforeach()

if (${BOOST_PROJECT})
	include(CMake/add_lib_boost.cmake)
endif()

######################################
##       Assemble executables       ##
######################################
include(CMake/add_source_files.cmake)

###### Main executable ######
if (HAS_LIBS)
	add_subdirectory("lib")
endif()
add_subdirectory("src")

include_directories("src")

if (IS_LIBRARY)
	add_library(${PROJECT_NAME} ${SOURCE_FILES})
else()
	add_executable(${PROJECT_NAME} src/Main.cpp ${SOURCE_FILES})
endif()
target_link_libraries(${PROJECT_NAME} ${STATIC_LIBRARIES})

#logging
get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
message(STATUS "src_include_dirs: ${dirs}")
message(STATUS "linked libraries:  ${STATIC_LIBRARIES}")


###### UnitTest executable ######
if (HAS_TESTS)
	add_subdirectory("test")

	set(TEST_PROJECT_NAME ${PROJECT_NAME}_tests)

	add_executable(${TEST_PROJECT_NAME} test/Main.cpp ${SOURCE_FILES} ${TEST_FILES})
	target_link_libraries(${TEST_PROJECT_NAME} GTest)
	target_link_libraries(${TEST_PROJECT_NAME} GMock)
	target_link_libraries(${TEST_PROJECT_NAME} ${STATIC_LIBRARIES})
endif()

######################################
##           Installation           ##
######################################
include(CMake/copy_lib.cmake)
include(CMake/copy_resources.cmake)

###### Main executable ######
if (NOT IS_LIBRARY)
	copy_libs(${PROJECT_NAME} ${DYNAMIC_LIBRARIES})
	copy_resources(${PROJECT_NAME})
endif()

###### UnitTest executable ######
if (HAS_TESTS)
	copy_libs(${TEST_PROJECT_NAME} ${DYNAMIC_LIBRARIES})
endif()
