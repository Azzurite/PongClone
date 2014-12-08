include(CMake/add_lib.cmake)

add_library_to_build(SDL2_image)

list(APPEND DYNAMIC_LIBRARIES SDL2_image.dll libjpeg-9.dll libpng16-16.dll libtiff-5.dll libwebp-4.dll zlib1.dll)
