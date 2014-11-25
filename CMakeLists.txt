# Necessary environment variables: QT_PATH, INCLUDE
cmake_minimum_required(VERSION 2.8.12.1)

set(USER_NAME "Azzu")

###### Project Settings ######
set(PROJECT_NAME "Pong_Clone")
set(HAS_RESOURCES TRUE)
set(SDL2_PROJECT TRUE)
set(SDL2_TTF_PROJECT TRUE)
set(SDL2_IMAGE_PROJECT TRUE)
set(BOOST_PROJECT TRUE)
set(BOOST_COMPONENTS system chrono date_time thread)
include(user_defined_settings.cmake)

###### Project Setup ######
###### Include build macros ######
include (add_macros.cmake)
include (copy_lib.cmake)
include (copy_resources.cmake)
#include (sdl_buildsteps.cmake)




###### PROJECT START ######
project(${PROJECT_NAME})
include_directories($ENV{INCLUDE})

###### Compiler flags ######
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -pedantic -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-Og -ggdb -DDEBUG")


###### Find SDL2 lib ######
if (${SDL2_PROJECT})
	find_package(SDL2 REQUIRED)

	if (NOT SDL2_FOUND) 
		message(SEND_ERROR "SDL2 not found! Adjust or provide a FindSDL2.cmake!")
		return() 
	endif (NOT SDL2_FOUND)

	list(APPEND STATIC_LIBRARIES ${SDL2_LIBRARIES})

	include_directories(${SDL2_INCLUDE_DIRS})

	list(APPEND DYNAMIC_LIBRARIES SDL2.dll)
endif()


###### Find SDL2_TTF lib ######
if (${SDL2_TTF_PROJECT})
	find_package(SDL2_ttf REQUIRED)

	if (NOT SDL2_TTF_FOUND)
		message(SEND_ERROR "SDL2_TTF not found! Adjust or provide a FindSDL2_ttf.cmake!")
		return()
	endif (NOT SDL2_TTF_FOUND)

    list (APPEND STATIC_LIBRARIES ${SDL2_TTF_LIBRARIES})

	include_directories(${SDL2_TTF_INCLUDE_DIRS})

	list(APPEND DYNAMIC_LIBRARIES libfreetype-6.dll SDL2_ttf.dll zlib1.dll)
endif()

###### Find SDL2_IMAGE lib ######
if (${SDL2_IMAGE_PROJECT})
	find_package(SDL2_image REQUIRED)

	if (NOT SDL2_IMAGE_FOUND)
		message(SEND_ERROR "SDL2_IMAGE not found! Adjust or provide a FindSDL2_image.cmake!")
		return()
	endif (NOT SDL2_IMAGE_FOUND)

	list (APPEND STATIC_LIBRARIES ${SDL2_IMAGE_LIBRARIES})

	include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

	list(APPEND DYNAMIC_LIBRARIES SDL2_image.dll libjpeg-9.dll libpng16-16.dll libtiff-5.dll libwebp-4.dll zlib1.dll)
endif()

###### Find Boost ######
if (${BOOST_PROJECT})
	find_package(Boost REQUIRED COMPONENTS ${BOOST_COMPONENTS})
	if (NOT Boost_FOUND)
		message(SEND_ERROR "Boost not found")
	endif()

	include_directories(${Boost_INCLUDE_DIR})
	add_definitions("-DHAS_BOOST")
	list (APPEND STATIC_LIBRARIES ${Boost_LIBRARIES})
endif()

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

copy_libs(${PROJECT_NAME} ${DYNAMIC_LIBRARIES})
copy_resources(${PROJECT_NAME})

###### UnitTest executable ######
add_subdirectory("test")

set(TEST_PROJECT_NAME ${PROJECT_NAME}_tests)
add_executable(${TEST_PROJECT_NAME} test/Main.cpp ${SOURCE_FILES} ${TEST_FILES})
target_link_libraries(${TEST_PROJECT_NAME} GTest)
target_link_libraries(${TEST_PROJECT_NAME} GMock)
target_link_libraries(${TEST_PROJECT_NAME} ${STATIC_LIBRARIES})

copy_libs(${TEST_PROJECT_NAME} ${DYNAMIC_LIBRARIES})
