#include <stdexcept>

#include "gtest/gtest.h"
#include "StackOnArray.h"

class StackOnArrayTest : public testing::Test {
protected:
    StackOnArray<int> emptyStack;
    StackOnArray<int> singleElementStack;
    StackOnArray<int> threeElementStack;
    StackOnArray<int> threeElementStack2;

    StackOnArrayTest()
    {
        singleElementStack.push(1);
        threeElementStack = StackOnArray<int>({1, 2, 3});
        threeElementStack2= StackOnArray<int>({1, 2, 3});
    }
};

TEST_F(StackOnArrayTest, EmptyStackTest)
{
    ASSERT_EQ(emptyStack.size(), 0);
    ASSERT_TRUE(emptyStack.isEmpty());
}

TEST_F(StackOnArrayTest, PopTest)
{
    ASSERT_EQ(threeElementStack.pop(), 3);
    EXPECT_EQ(threeElementStack.pop(), 2);
    EXPECT_EQ(threeElementStack.pop(), 1);
    EXPECT_THROW(threeElementStack.pop(), std::length_error);
}

TEST_F(StackOnArrayTest, PushTest)
{
    emptyStack.push(1);
    EXPECT_EQ(emptyStack.size(), 1);
    ASSERT_EQ(emptyStack.pop(), 1);
}

TEST_F(StackOnArrayTest, OperatorEqTest)
{
    ASSERT_TRUE(threeElementStack == threeElementStack2);
    EXPECT_FALSE(threeElementStack != threeElementStack2);
    EXPECT_FALSE(threeElementStack == emptyStack);
    EXPECT_FALSE(threeElementStack == singleElementStack);
}