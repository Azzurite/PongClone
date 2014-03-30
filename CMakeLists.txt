cmake_minimum_required(VERSION 2.8.12.1)
set(_ECLIPSE_VERSION "4.3")

macro (add_sources)
    file (RELATIVE_PATH _relPath "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}")
    foreach (_src ${ARGN})
        if (_relPath)
            list (APPEND SOURCE_FILES "${_relPath}/${_src}")
        else()
            list (APPEND SOURCE_FILES "${_src}")
        endif()
    endforeach()
    if (_relPath)
        # propagate SOURCE_FILES to parent directory
        set (SOURCE_FILES ${SOURCE_FILES} PARENT_SCOPE)
    endif()
endmacro()
macro (add_tests)
    file (RELATIVE_PATH _relPath1 "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}")
    foreach (_src1 ${ARGN})
        if (_relPath1)
            list (APPEND TEST_FILES "${_relPath1}/${_src1}")
        else()
            list (APPEND TEST_FILES "${_src1}")
        endif()
    endforeach()
    if (_relPath1)
        # propagate TEST_FILES to parent directory
        set (TEST_FILES ${TEST_FILES} PARENT_SCOPE)
    endif()
endmacro()


###### PROJECT START ######
project(Pong)
include_directories($ENV{INCLUDE})


###### Compiler flags ######
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pedantic -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-Og -g3 -DDEBUG")


###### Find SDL2 lib ######
find_package(SDL2 REQUIRED)

if (NOT SDL2_FOUND) 
	message(SEND_ERROR "SDL2 not found! Adjust or provide a FindSDL2.cmake!")
	return() 
endif (NOT SDL2_FOUND)

include_directories(${SDL2_INCLUDE_DIRS})


###### Main executable ######
add_subdirectory("lib")

add_subdirectory("src")

include_directories("src")

get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "src_include_dir ='${dir}'")
endforeach()

add_executable(pong src/Main.cpp ${SOURCE_FILES})
message(STATUS "linked libraries:  ${SDL2_LIBRARIES}")
target_link_libraries(pong ${SDL2_LIBRARIES})


###### Add SDL2.dll to main output ######
add_custom_command(TARGET Pong POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
	"${PROJECT_SOURCE_DIR}/lib/SDL2.dll"
	$<TARGET_FILE_DIR:Pong>)
	
#install(TARGETS Pong RUNTIME DESTINATION bin)


###### UnitTest executable ######
add_subdirectory("test")

get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "test_include_dir ='${dir}'")
endforeach()

add_executable(pong_tests test/Main.cpp ${SOURCE_FILES} ${TEST_FILES})
target_link_libraries(pong_tests GTest)
target_link_libraries(pong_tests GMock)
target_link_libraries(pong_tests ${SDL2_LIBRARIES})


###### Add SDL2.dll to test output ######
add_custom_command(TARGET PongUnitTests POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
	"${PROJECT_SOURCE_DIR}/lib/SDL2.dll"
	$<TARGET_FILE_DIR:PongUnitTests>)
