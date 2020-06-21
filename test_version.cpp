#define BOOST_TEST_MODULE cpptests
#include "boost/test/unit_test.hpp"
#include "version.h"

BOOST_AUTO_TEST_SUITE(cpptests_suite)

BOOST_AUTO_TEST_CASE(cpplesson1_test_version){
    BOOST_CHECK(5 > 0);
}

BOOST_AUTO_TEST_SUITE_END()