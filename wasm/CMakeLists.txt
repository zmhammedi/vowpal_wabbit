set(CMAKE_EXECUTABLE_SUFFIX ".wasm.js")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../wasm/")

add_executable(vw-wasm wasm_wrapper.cc)
set_target_properties(vw-wasm PROPERTIES LINK_FLAGS "-s WASM=1 -s EXPORTED_FUNCTIONS='[_main]' --bind")
target_link_libraries(vw-wasm PUBLIC VowpalWabbit::explore vwslim)

add_executable(vw-wasm-full wasm_wrapper_full.cc ../vowpalwabbit/slim/src/example_predict_builder.cc)
set_target_properties(vw-wasm-full PROPERTIES LINK_FLAGS "-s WASM=1 -s EXPORTED_FUNCTIONS='[_main]' --bind")
target_link_libraries(vw-wasm-full PUBLIC VowpalWabbit::explore vw)
target_include_directories(vw-wasm-full PUBLIC ../vowpalwabbit/slim/include/)