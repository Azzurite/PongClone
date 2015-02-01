cmake_minimum_required(VERSION 2.8.12.1)

###########################################################################
## Project Settings                                                      ##
## ----------------                                                      ##
## Can be changed across projects                                        ##
###########################################################################
# how the project and the build targets will be called
set(PROJECT_NAME "Pong_Clone")

# when false, this will add "src/Main.cpp" to the build and build an executable.
# otherwise, it will build a library
set(IS_LIBRARY false)
# set the type of the library, either STATIC or SHARED
set(LIBRARY_TYPE STATIC)

# will add the "test" subdirectory and "test/Main.cpp"
set(HAS_TESTS true)

# will add the lib/ directory to the build if true
set(HAS_LIBS true)
# define the names of the built libs to be added to the main target
list(APPEND LIBS )
# define the names of the built libs to be added to the test target
list(APPEND TEST_LIBS GTest GMock)

# will copy the resources/ folder to the installation directory
set(HAS_RESOURCES true)

# third party libs that will be added with find_package
list(APPEND THIRD_PARTY_PACKAGES SDL2_gfx SDL2_image SDL2_ttf AzzuUtils SDL2Wrap SDL2)

# dynamic libraries that will be copied from the lib/ folder to the app directory
list(APPEND DYNAMIC_LIBRARIES SDL2.dll)
list(APPEND DYNAMIC_LIBRARIES SDL2_gfx.dll)
list(APPEND DYNAMIC_LIBRARIES SDL2_image.dll libjpeg-9.dll libpng16-16.dll libtiff-5.dll libwebp-4.dll zlib1.dll)
list(APPEND DYNAMIC_LIBRARIES libfreetype-6.dll SDL2_ttf.dll zlib1.dll)

# boost libraries
set(ADD_BOOST true)
set(BOOST_COMPONENTS system chrono date_time thread)

# Settings necessary for individual computer configurations go in this file
include(CMake/user_settings.cmake)

### Build ###
include(CMake/project_build.cmake)
