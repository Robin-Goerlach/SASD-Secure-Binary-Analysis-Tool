add_executable(sasd_core_tests
    core_tests.cpp
)

target_link_libraries(sasd_core_tests PRIVATE sasd_core)
target_compile_features(sasd_core_tests PRIVATE cxx_std_20)

include(${CMAKE_SOURCE_DIR}/cmake/CompilerWarnings.cmake)
sasd_enable_warnings(sasd_core_tests)

add_test(NAME sasd.core.api_version COMMAND sasd_core_tests)
