#include "gtest/gtest.h"
#include "Bank.h"

using namespace bank;

class BankFixture : public ::testing::Test {
protected:
    void SetUp() override
    {
        bank = new Bank();
    }

    void TearDown() override
    {
        delete bank;
    }

    Bank *bank{};
};

TEST_F(BankFixture, ReturnsElementCountCorrectly)
{
    EXPECT_EQ(bank->print(), "hello");
}