#define BOOST_TEST_MODULE cpptests
#include <iostream>
#include "boost/test/unit_test.hpp"
#include "version.h"

BOOST_AUTO_TEST_SUITE(cpptests_suite)

BOOST_AUTO_TEST_CASE(cpplesson1_test_version){
    std::cout << CI_BUILD_NUMBER << std::endl;
    BOOST_CHECK(CI_BUILD_NUMBER > 0);
}

BOOST_AUTO_TEST_SUITE_END()