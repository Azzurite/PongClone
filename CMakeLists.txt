# Necessary environment variables: QT_PATH, INCLUDE
cmake_minimum_required(VERSION 2.8.12.1)
include (add_macros.cmake)

set(USER_NAME "Azzu")

###### Project Settings ######
set(PROJECT_NAME "Pong_Clone")
set(QT_PROJECT FALSE)
set(SDL2_PROJECT TRUE)
set(SDL2_TTF_PROJECT TRUE)
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

	include_directories(${SDL2_INCLUDE_DIRS})
endif()


###### Find SDL2_TTF lib ######
if (${SDL2_TTF_PROJECT})
	find_package(SDL2_ttf REQUIRED)

	if (NOT SDL2_TTF_FOUND)
		message(SEND_ERROR "SDL2_TTF not found! Adjust or provide a FindSDL2_ttf.cmake!")
		return()
	endif (NOT SDL2_TTF_FOUND)

	include_directories(${SDL2_TTF_INCLUDE_DIRS})
endif()

###### Find Qt ######
if (${QT_PROJECT}) 
	find_package(Qt5Widgets REQUIRED)
endif()

###### Find Boost ######
if (${BOOST_PROJECT})
    SET(BOOST_ROOT "P:/tools/compilers/MinGW/")
    find_package(Boost REQUIRED COMPONENTS ${BOOST_COMPONENTS})
    if (NOT Boost_FOUND)
        message(SEND_ERROR "Boost not found")
    endif()
    if (Boost_FOUND)
        include_directories(${Boost_INCLUDE_DIR})
        add_definitions("-DHAS_BOOST")
        list (APPEND STATIC_LIBRARIES ${Boost_LIBRARIES})
    endif()
endif()

###### Main executable ######
add_subdirectory("lib")
add_subdirectory("src")

include_directories("src")

if (${SDL2_PROJECT})
	list (APPEND STATIC_LIBRARIES ${SDL2_LIBRARIES})
endif()

if (${QT_PROJECT})
	qt5_wrap_ui(UI_HEADERS ${UI_FILES})
	list (APPEND SOURCE_FILES ${UI_HEADERS})
	list (APPEND SOURCE_FILES ${MOC_SRC})
endif()

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${STATIC_LIBRARIES})

if (${QT_PROJECT})
	qt5_use_modules(${PROJECT_NAME} Widgets)
endif()

#logging
get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
message(STATUS "src_include_dirs: ${dirs}")
message(STATUS "linked libraries:  ${STATIC_LIBRARIES}")

if (${QT_PROJECT})
	message(STATUS "UI Headers:  ${UI_HEADERS}")
endif()

###### Add SDL2.dll to main output ######
if (${SDL2_PROJECT})
	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
		"${PROJECT_SOURCE_DIR}/lib/SDL2.dll"
		$<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif()


###### UnitTest executable ######
add_subdirectory("test")

add_executable(${PROJECT_NAME}_tests test/Main.cpp ${SOURCE_FILES} ${TEST_FILES})
target_link_libraries(${PROJECT_NAME}_tests GTest)
target_link_libraries(${PROJECT_NAME}_tests GMock)

if (${SDL2_PROJECT})
	target_link_libraries(${PROJECT_NAME}_tests ${SDL2_LIBRARIES})
endif()

###### Add SDL2.dll to test output ######
if (${SDL2_PROJECT})
	add_custom_command(TARGET ${PROJECT_NAME}_tests POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
		"${PROJECT_SOURCE_DIR}/lib/SDL2.dll"
		$<TARGET_FILE_DIR:${PROJECT_NAME}_tests>)
endif()
