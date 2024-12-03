#include "gtest/gtest.h"
#include "Application.h"

TEST(ApplicationTests, Test1)
{
    EXPECT_EQ(Application::main(), 0);
}