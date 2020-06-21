cmake_minimum_required(VERSION 3.16)
message("Build Cpp lesson 1")
project(cpplesson_1 VERSION 0.0.1)
set(CI_BUILD_NUMBER -1 CACHE STRING "Number of build from CI")

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
message("Boost include path: ${Boost_INCLUDE_DIR}")
message("Boost libs: ${Boost_LIBRARIES}")
configure_file(version.h.in ${PROJECT_SOURCE_DIR}/version.h)

add_executable(cpplesson_1_cli main.cpp)
add_executable(test_version test_version.cpp)

set_target_properties(cpplesson_1_cli test_version PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS "-Wall;-Wextra"
        )

set_target_properties(test_version PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
        )
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(test_version ${Boost_LIBRARIES})

install(TARGETS cpplesson_1_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT kolya-spr@mail.ru)
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)
enable_testing()
add_test(cpptests test_version)
