set(vw_c_headers
  include/vw/example.h
  include/vw/exports.h
  include/vw/label.h
  include/vw/prediction.h
  include/vw/types.h
  include/vw/workspace.h
)

set(vw_c_sources
  src/example.cc
)

add_library(vw_c_api ${vw_c_headers} ${vw_c_sources})
target_include_directories(vw_c_api PUBLIC include/)
target_link_libraries(vw_c_api VowpalWabbit::vw)

add_executable(c_api_test test/test.c)
target_link_libraries(c_api_test PUBLIC vw_c_api)
