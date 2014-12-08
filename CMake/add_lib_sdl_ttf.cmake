include(CMake/add_lib.cmake)

add_library_to_build(SDL2_ttf)

list(APPEND DYNAMIC_LIBRARIES libfreetype-6.dll SDL2_ttf.dll zlib1.dll)
