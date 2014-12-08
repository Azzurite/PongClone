cmake_minimum_required(VERSION 2.8.12.1)

###########################################################################
## Project Settings                                                      ##
## ----------------                                                      ##
## Can be changed across projects                                        ##
###########################################################################
set(PROJECT_NAME "Pong_Clone")
set(HAS_RESOURCES true) # will copy the resources/ folder to the installation directory
set(SDL2_PROJECT true)
set(SDL2_TTF_PROJECT true)
set(SDL2_IMAGE_PROJECT true)
set(BOOST_PROJECT true)
set(BOOST_COMPONENTS system chrono date_time thread)
include(CMake/user_defined_settings.cmake)

###########################################################################
## Project build                                                         ##
## -------------                                                         ##
## Should probably not be changed across projects.                       ##
###########################################################################
project(${PROJECT_NAME})

###### Stupid user ######
if(SDL2_TTF_PROJECT OR SDL2_IMAGE_PROJECT)
	message(STATUS "SDL2 addons used but SDL2_PROJECT set to false. Assuming SDL2_PROJECT was meant to be true")
	set(SDL2_PROJECT TRUE)
endif()

###### Compiler flags ######
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -pedantic -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-Og -ggdb -DDEBUG")

###### Library inclusion #######
if (${SDL2_PROJECT})
	include(CMake/add_lib_sdl.cmake)
endif()

if (${SDL2_TTF_PROJECT})
	include(CMake/add_lib_sdl_ttf.cmake)
endif()

if (${SDL2_IMAGE_PROJECT})
	include(CMake/add_lib_sdl_image.cmake)
endif()

if (${BOOST_PROJECT})
	include(CMake/add_lib_boost.cmake)
endif()

######################################
##       Assemble executables       ##
######################################
include(CMake/add_source_files.cmake)

###### Main executable ######
add_subdirectory("lib")
add_subdirectory("src")

include_directories("src")

add_executable(${PROJECT_NAME} src/Main.cpp ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${STATIC_LIBRARIES})

#logging
get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
message(STATUS "src_include_dirs: ${dirs}")
message(STATUS "linked libraries:  ${STATIC_LIBRARIES}")


###### UnitTest executable ######
add_subdirectory("test")

set(TEST_PROJECT_NAME ${PROJECT_NAME}_tests)
add_executable(${TEST_PROJECT_NAME} test/Main.cpp ${SOURCE_FILES} ${TEST_FILES})
target_link_libraries(${TEST_PROJECT_NAME} GTest)
target_link_libraries(${TEST_PROJECT_NAME} GMock)
target_link_libraries(${TEST_PROJECT_NAME} ${STATIC_LIBRARIES})

######################################
##           Installation           ##
######################################
include(CMake/copy_lib.cmake)
include(CMake/copy_resources.cmake)

###### Main executable ######
copy_libs(${PROJECT_NAME} ${DYNAMIC_LIBRARIES})
copy_resources(${PROJECT_NAME})

###### UnitTest executable ######
copy_libs(${TEST_PROJECT_NAME} ${DYNAMIC_LIBRARIES})

INSTALL(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${PROJECT_NAME})
SET(CPACK_CMAKE_GENERATOR "Unix Makefiles")
SET(CPACK_GENERATOR "STGZ;TGZ;TZ")
INCLUDE(CPack)
