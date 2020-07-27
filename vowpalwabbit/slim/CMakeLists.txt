cmake_minimum_required(VERSION 3.5)
include(../../explore/CMakeLists.txt)

set(CMAKE_EXECUTABLE_SUFFIX ".wasm.js")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CACHEFILE_DIR}/../public/")

project(vwslim_proj CXX)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(src)

if (BUILD_TESTS)
	enable_testing()
	add_subdirectory(test)
endif ()
