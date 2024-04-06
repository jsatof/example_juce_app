include(cmake/cpm.cmake)

CPMAddPackage(NAME JUCE
    GITHUB_REPOSITORY juce-framework/JUCE
    GIT_TAG 7.0.11
    VERSION 7.0.11
    SOURCE_DIR ${ExampleGUIRoot_LIB_DIR}/juce
)

CPMAddPackage(NAME GTEST
    GITHUB_REPOSITORY google/googletest
    VERSION 1.14.0
    SOURCE_DIR ${ExampleGUIRoot_LIB_DIR}/gtest
    OPTIONS
        "INSTALL_GTEST OFF"
        "gtest_force_shared_crt ON"
)
