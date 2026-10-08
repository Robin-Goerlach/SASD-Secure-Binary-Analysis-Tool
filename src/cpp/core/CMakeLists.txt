add_library(sasd_core STATIC
    src/core.cpp
)

target_compile_features(sasd_core PUBLIC cxx_std_20)

target_include_directories(sasd_core
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

set_target_properties(sasd_core PROPERTIES
    EXPORT_NAME core
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

include(${CMAKE_SOURCE_DIR}/cmake/CompilerWarnings.cmake)
sasd_enable_warnings(sasd_core)

install(TARGETS sasd_core
    EXPORT SASDBinaryInsightTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
