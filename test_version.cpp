#define BOOST_TEST_MODULE cpptests
#include <iostream>
#include "boost/test/unit_test.hpp"
#include "version.h"

BOOST_AUTO_TEST_SUITE(cpptests_suite)

BOOST_AUTO_TEST_CASE(cpplesson1_test_version){
    std::cout << "Some text to console output" << std::endl;
    std::cerr << "Some text to console errors" << std::endl;
    std::cout << "CI_BUILD_NUMBER from application: " << CI_BUILD_NUMBER << std::endl;
    std::cout.flush();
    BOOST_CHECK(CI_BUILD_NUMBER < 0);
}

BOOST_AUTO_TEST_SUITE_END()