#include <stdexcept>

#include "gtest/gtest.h"
#include "StackOnList.h"

class StackOnListTest : public testing::Test
{
protected:
    StackOnList<int> emptyStack;
    StackOnList<int> singleElementStack;
    StackOnList<int> ctorStack {1, 2, 3};
    StackOnList<int> ctorStack2 {1, 2, 3};

    StackOnListTest()
    {
        singleElementStack.push(10);
    }
};

TEST_F(StackOnListTest, EmptyStackTest)
{
    ASSERT_EQ(emptyStack.size(), 0);
    ASSERT_TRUE(emptyStack.isEmpty());
    EXPECT_THROW(emptyStack.pop(), std::length_error);
    EXPECT_EQ(emptyStack.top(), nullptr);
}

TEST_F(StackOnListTest, PushTest)
{
    emptyStack.push(10);
    ASSERT_EQ(emptyStack.size(), 1);
    ASSERT_FALSE(emptyStack.isEmpty());
    EXPECT_EQ(emptyStack.top()->value, 10);
    EXPECT_EQ(emptyStack.top()->next, nullptr);
}

TEST_F(StackOnListTest, PopTest)
{
    ASSERT_EQ(singleElementStack.pop(), 10);
    EXPECT_EQ(singleElementStack.top(), nullptr);
    EXPECT_TRUE(singleElementStack.isEmpty());
    EXPECT_THROW(singleElementStack.pop(), std::length_error);
}

TEST_F(StackOnListTest, CtorWithInitializerListTest)
{
    EXPECT_EQ(ctorStack.size(), 3);
    EXPECT_FALSE(ctorStack.isEmpty());
    EXPECT_EQ(ctorStack.pop(), 3);
    EXPECT_EQ(ctorStack.pop(), 2);
    EXPECT_EQ(ctorStack.size(), 1);
    EXPECT_EQ(ctorStack.pop(), 1);
    EXPECT_THROW(ctorStack.pop(), std::length_error);
}

