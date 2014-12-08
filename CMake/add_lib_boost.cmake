include(CMake/add_lib.cmake)

add_library_to_build(Boost ${BOOST_COMPONENTS})

add_definitions("-DHAS_BOOST")
