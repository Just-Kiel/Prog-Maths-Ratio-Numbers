cmake_minimum_required(VERSION 3.13)

enable_testing()

add_executable(myUnitTests src/sample_test.cpp)
target_link_libraries(myUnitTests gtest Ratio)
target_compile_features(myUnitTests PRIVATE cxx_std_17)

add_test(NAME myUnitTests
    COMMAND myUnitTests)