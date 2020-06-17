set(vw_c_public_headers
  include/vw/experimental/example.h
  include/vw/experimental/exports.h
  include/vw/experimental/feature_space.h
  include/vw/experimental/label.h
  include/vw/experimental/options.h
  include/vw/experimental/prediction.h
  include/vw/experimental/search.h
  include/vw/experimental/types.h
  include/vw/experimental/utility.h
  include/vw/experimental/vw.h
  include/vw/experimental/workspace.h
)

set(vw_c_impl_files
  src/c_io_adapter.cc
  src/c_io_adapter.h
  src/error_handling.h
  src/example.cc
  src/feature_space.cc
  src/interop_helper.h
  src/label.cc
  src/options.cc
  src/owned_string.h
  src/parser.cc
  src/prediction.cc
  src/search.cc
  src/utility.cc
  src/workspace.cc
)

add_library(vw_c_api ${vw_c_public_headers} ${vw_c_impl_files})
target_include_directories(vw_c_api PUBLIC include/)
target_link_libraries(vw_c_api VowpalWabbit::vw VowpalWabbit::io)

add_subdirectory(test)