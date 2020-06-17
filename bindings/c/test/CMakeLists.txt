add_executable(c-api-unit-test
  options_test.cc
  test_main.cc
)

target_link_libraries(c-api-unit-test PRIVATE vw_c_api Boost::unit_test_framework)

add_executable(c-main-example c_example.c)
target_link_libraries(c-main-example PRIVATE vw_c_api)

add_test(
  NAME c-api-unit-test
  COMMAND ./c-api-unit-test
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

add_test(
  NAME c-main-example
  COMMAND ./c-main-example
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
