set(VW_SLIM_SOURCES
  example_predict_builder.cc
  model_parser.cc
  opts.cc
  vw_slim_predict.cc
  ../../../wasm/my_glue_wrapper.cpp
  ../../example_predict.cc
  ../../feature_group.cc)

set(VW_SLIM_HEADERS
  ../include/example_predict_builder.h
  ../include/model_parser.h
  ../include/opts.h
  ../include/vw_slim_predict.h
  ../include/vw_slim_return_codes.h)

add_executable(vwslim ${VW_SLIM_SOURCES} ${VW_SLIM_HEADERS})
set_target_properties(vwslim PROPERTIES LINK_FLAGS "-s WASM=1 -s EXPORTED_FUNCTIONS='[_main]' --bind")

target_include_directories(vwslim PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/../include
  ${CMAKE_CURRENT_SOURCE_DIR}/../../)
target_compile_definitions(vwslim PUBLIC EXPLORE_NOEXCEPT VW_NOEXCEPT)
target_link_libraries(vwslim PUBLIC VowpalWabbit::explore)

include(GNUInstallDirs)

install(
  TARGETS vwslim
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

install(
  FILES ${VW_SLIM_HEADERS}
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/vowpalwabbit/slim)
