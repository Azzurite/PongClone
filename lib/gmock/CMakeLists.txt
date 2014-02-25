cmake_minimum_required(VERSION 2.8.12.1)

set(GMOCK_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

macro (add_gmock_sources)
    file (RELATIVE_PATH _relPath "${GMOCK_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}")
    foreach (_src ${ARGN})
        if (_relPath)
            list (APPEND GMOCK_SOURCE_FILES "${_relPath}/${_src}")
        else()
            list (APPEND GMOCK_SOURCE_FILES "${_src}")
        endif()
    endforeach()
    if (_relPath)
        # propagate GMOCK_SOURCE_FILES to parent directory
        set (GMOCK_SOURCE_FILES ${GMOCK_SOURCE_FILES} PARENT_SCOPE)
    endif()
endmacro()

add_subdirectory(src)

message(STATUS "ENV INCLUDE: $ENV{INCLUDE}")
include_directories($ENV{INCLUDE} ${CMAKE_CURRENT_SOURCE_DIR})

add_library(GMock ${GMOCK_SOURCE_FILES})
target_link_libraries(GMock GTest)