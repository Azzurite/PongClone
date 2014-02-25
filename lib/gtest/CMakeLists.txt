cmake_minimum_required(VERSION 2.8.12.1)

set(GTEST_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

macro (add_gtest_sources)
    file (RELATIVE_PATH _relPath "${GTEST_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}")
    foreach (_src ${ARGN})
        if (_relPath)
            list (APPEND GTEST_SOURCE_FILES "${_relPath}/${_src}")
        else()
            list (APPEND GTEST_SOURCE_FILES "${_src}")
        endif()
    endforeach()
    if (_relPath)
        # propagate GTEST_SOURCE_FILES to parent directory
        set (GTEST_SOURCE_FILES ${GTEST_SOURCE_FILES} PARENT_SCOPE)
    endif()
endmacro()

add_subdirectory(src)

include_directories($ENV{INCLUDE} ${CMAKE_CURRENT_SOURCE_DIR})

add_library(GTest ${GTEST_SOURCE_FILES})