#include <boost/test/unit_test.hpp>

#include "vw/experimental/vw.h"

BOOST_AUTO_TEST_CASE(create_and_destroy_options) {
  VWOptions* options;
  BOOST_CHECK_EQUAL(vw_create_options(&options, nullptr), VW_SUCCESS);
  BOOST_CHECK_EQUAL(vw_destroy_options(options, nullptr), VW_SUCCESS);
}
