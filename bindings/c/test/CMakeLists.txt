if(BUILD_TESTS)
  add_executable(vw_c_api_unit_test
    options_test.cc
    test_main.cc
  )

  target_link_libraries(vw_c_api_unit_test PRIVATE vw_c_api Boost::unit_test_framework)

  add_test(
    NAME vw_c_api_unit_test
    COMMAND ./vw_c_api_unit_test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  )
endif()

add_executable(c_main_example c_example.c)
target_link_libraries(c_main_example PRIVATE vw_c_api)

add_test(
  NAME c_main_example
  COMMAND ./c_main_example
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
