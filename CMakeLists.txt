cmake_minimum_required(VERSION 3.22)

project(ExampleGUIRoot)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(ExampleGUIRoot_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)
include(cmake/dependencies.cmake)

enable_testing()

add_subdirectory(app)
add_subdirectory(test)
