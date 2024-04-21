cmake_minimum_required(VERSION 3.0.0)
project(squarepoint_orderbook VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(squarepoint_orderbook main.cpp orderbook.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

# Set C++ standard to C++20
target_compile_features(squarepoint_orderbook PRIVATE cxx_std_20)

include(CPack)
