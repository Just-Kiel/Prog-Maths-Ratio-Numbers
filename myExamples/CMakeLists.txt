cmake_minimum_required(VERSION 3.13)

enable_testing()

add_executable(myExamples src/main.cpp)
target_compile_features(myExamples PRIVATE cxx_std_20)

add_test(NAME myExamples
    COMMAND myExamples)