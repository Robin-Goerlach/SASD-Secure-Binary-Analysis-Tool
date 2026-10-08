cmake_minimum_required(VERSION 3.25)

project(SASDBinaryInsight
    VERSION 0.1.0
    DESCRIPTION "SASD Secure Binary Analysis Tool"
    LANGUAGES CXX
)

option(SASD_BUILD_TESTS "Build the C++ test suite" ON)
option(SASD_BUILD_EXAMPLES "Build C++ examples" OFF)

include(GNUInstallDirs)

add_subdirectory(src/cpp/core)

if(SASD_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests/cpp)
endif()

if(SASD_BUILD_EXAMPLES)
    add_subdirectory(examples/cpp)
endif()
