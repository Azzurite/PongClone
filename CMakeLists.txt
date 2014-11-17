# Necessary environment variables: QT_PATH, INCLUDE
cmake_minimum_required(VERSION 2.8.12.1)
include (add_macros.cmake)
include (copy_lib.cmake)

set(USER_NAME "Azzu")

###### Project Settings ######
set(PROJECT_NAME "Pong_Clone")
set(QT_PROJECT FALSE)
set(SDL2_PROJECT TRUE)
set(SDL2_TTF_PROJECT TRUE)
set(SDL2_IMAGE_PROJECT TRUE)
set(BOOST_PROJECT FALSE)
set(BOOST_COMPONENTS system chrono date_time thread)

###### Project Setup ######
if (${QT_PROJECT}) 
	set(CMAKE_PREFIX_PATH $ENV{QT_PATH})
endif()

###### PROJECT START ######
project(${PROJECT_NAME})
include_directories($ENV{INCLUDE})

if (${QT_PROJECT}) 
	set(CMAKE_AUTOMOC ON)
	set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

###### Compiler flags ######
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -pedantic -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-Og -ggdb -DDEBUG")

if (${QT_PROJECT})
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
endif()

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

###### Find Qt ######
if (${QT_PROJECT})
	find_package(Qt5Widgets REQUIRED)

	qt5_wrap_ui(UI_HEADERS ${UI_FILES})
	list (APPEND SOURCE_FILES ${UI_HEADERS})
	list (APPEND SOURCE_FILES ${MOC_SRC})
	message(STATUS "UI Headers:  ${UI_HEADERS}")
endif()

###### Find Boost ######
if (${BOOST_PROJECT})
	SET(BOOST_ROOT "P:/tools/compilers/MinGW/")
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

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${STATIC_LIBRARIES})

if (${QT_PROJECT})
	qt5_use_modules(${PROJECT_NAME} Widgets)
endif()

#logging
get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
message(STATUS "src_include_dirs: ${dirs}")
message(STATUS "linked libraries:  ${STATIC_LIBRARIES}")



###### UnitTest executable ######
add_subdirectory("test")

add_executable(${PROJECT_NAME}_tests test/Main.cpp ${SOURCE_FILES} ${TEST_FILES})
target_link_libraries(${PROJECT_NAME}_tests GTest)
target_link_libraries(${PROJECT_NAME}_tests GMock)

if (${SDL2_PROJECT})
	target_link_libraries(${PROJECT_NAME}_tests ${SDL2_LIBRARIES})
endif()

###### Copy libraries to normal and test target ######
copy_lib(${DYNAMIC_LIBRARIES})
