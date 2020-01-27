cmake_policy(SET CMP0048 NEW)
add_subdirectory(zlib)
target_include_directories(zlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/zlib ${CMAKE_CURRENT_BINARY_DIR}/zlib)
add_library(ZLIB::ZLIB ALIAS zlib)
# Undo the file rename that zlib does as it leaves the src dir dirty.
file(RENAME ${CMAKE_CURRENT_SOURCE_DIR}/zlib/zconf.h.included ${CMAKE_CURRENT_SOURCE_DIR}/zlib/zconf.h)


set(Boost_POPULATED True)
set(boost_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/boost)
set(BOOST_SOURCE ${boost_SOURCE_DIR})
add_subdirectory(boost-cmake)
