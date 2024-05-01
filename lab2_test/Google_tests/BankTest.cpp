//
// Created by RobotComp.ru on 22.03.2024.
//
#include "gtest/gtest.h"
#include "Bank.h"

using namespace bank;

class BankFixture : public ::testing::Test {
protected:
    void SetUp() override
    {
        p = new Pueque<int>();
    }

    void TearDown() override
    {
        delete p;
    }

    Bank *p;
};

TEST_F(PuqueFixture, AddValue)
{
    p->add(5);
    EXPECT_FALSE(p->isEmpty());
}

TEST_F(PuqueFixture, OrderTest)
{
    p->add(5);
    p->add(6);
    p->add(7);

    EXPECT_EQ(5, *p->pull());
    EXPECT_EQ(6, *p->pull());
    EXPECT_EQ(7, *p->pull());

    EXPECT_TRUE(p->isEmpty());
}

TEST_F(PuqueFixture, PeekTest)
{
    p->add(5);

    EXPECT_EQ(5, *p->peek());

    EXPECT_FALSE(p->isEmpty());
}

TEST_F(PuqueFixture, ExceptionTest)
{
    try {
        p->pull();
        FAIL();
    } catch (PuqueException &e) {
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}
