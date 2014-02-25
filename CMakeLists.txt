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

################# PROJECT START #################
project(Pong)

################# Compiler flags ################
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pedantic -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-Og -g3")


############### Main executable ##############
add_subdirectory("lib")

add_subdirectory("src")

include_directories($ENV{INCLUDE} "src")

get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "src_include_dir ='${dir}'")
endforeach()

add_executable(Pong src/Main.cpp ${SOURCE_FILES})

######## Add SDL2.dll to output #######
add_custom_command(TARGET Pong POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
	"${PROJECT_SOURCE_DIR}/lib/SDL2.dll"
	$<TARGET_FILE_DIR:Pong>)
	
#install(TARGETS Pong RUNTIME DESTINATION bin)

############### UnitTest executable ##############

add_subdirectory("test")

include_directories($ENV{INCLUDE})

get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "test_include_dir ='${dir}'")
endforeach()

add_executable(PongUnitTests test/Main.cpp ${SOURCE_FILES} ${TEST_FILES})
target_link_libraries(PongUnitTests GTest)
target_link_libraries(PongUnitTests GMock)

######## Add SDL2.dll to output #######
add_custom_command(TARGET PongUnitTests POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
	"${PROJECT_SOURCE_DIR}/lib/SDL2.dll"
	$<TARGET_FILE_DIR:PongUnitTests>)
