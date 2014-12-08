include(CMake/add_lib.cmake)

add_library_to_build(SDL2)

list(APPEND DYNAMIC_LIBRARIES SDL2.dll)
