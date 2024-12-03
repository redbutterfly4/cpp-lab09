add_executable(runUnitTests ApplicationTests.cpp)

target_link_libraries(runUnitTests gtest gtest_main lib)

add_test(runUnitTests Google_Tests_run)