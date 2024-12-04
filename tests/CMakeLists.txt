add_executable(runUnitTests ApplicationTests.cpp StackOnListTests.cpp StackOnArrayTests.cpp)

target_link_libraries(runUnitTests gtest gtest_main lib)

add_test(runTests runUnitTests)