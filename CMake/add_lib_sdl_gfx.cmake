include(CMake/add_lib.cmake)

add_library_to_build(SDL2_gfx)

list(APPEND DYNAMIC_LIBRARIES SDL2_gfx.dll)
