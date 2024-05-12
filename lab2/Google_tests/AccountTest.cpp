#include "gtest/gtest.h"
#include "Account.h"

using namespace bank;

class AccountFixture : public ::testing::Test {
protected:
    void SetUp() override
    {
        account = new Account();
    }

    void TearDown() override
    {
        delete account;
    }

    Account *account{};
};

TEST_F(AccountFixture, InitialBalanceCorrent)
{
    EXPECT_EQ(account->GetBalance(), 0);
}

TEST_F(AccountFixture, DepositWorksCorrect)
{
    account->Deposit(10);
    EXPECT_EQ(account->GetBalance(), 10);
    account->Deposit(15.5);
    EXPECT_EQ(account->GetBalance(), 25.5);
}

TEST_F(AccountFixture, DepositThrowsExceptionOnNegativeAmount)
{
    try {
        account->Deposit(-10);
        FAIL();
    } catch (std::invalid_argument &e) {
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}

TEST_F(AccountFixture, WithdrawWorksCorrect)
{
    account->Deposit(100);
    account->Withdraw(50);
    EXPECT_EQ(account->GetBalance(), 50);
    account->Withdraw(24.5);
    EXPECT_EQ(account->GetBalance(), 25.5);
}

TEST_F(AccountFixture, WithdrawThrowsExceptionOnNegativeAmount)
{
    account->Deposit(10);
    try {
        account->Withdraw(-1);
        FAIL();
    } catch (std::invalid_argument &e) {
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}

TEST_F(AccountFixture, WithdrawThrowsExceptionOnTooBigAmount)
{
    account->Deposit(10);
    try {
        account->Withdraw(20);
        FAIL();
    } catch (std::invalid_argument &e) {
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}
