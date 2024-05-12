#include "gtest/gtest.h"
#include "Bank.h"

using namespace bank;

class BankFixture : public ::testing::Test {
protected:
    void SetUp() override
    {
        bank = new Bank("Bank Cianfanellich", 20);
    }

    void TearDown() override
    {
        delete bank;
    }

    Bank *bank{};
};

TEST_F(BankFixture, NegativeTransactionFeeCheckWorksCorrect)
{
    try {
        new Bank("", -1);
        FAIL();
    } catch (std::invalid_argument &e) {
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}

TEST_F(BankFixture, TooBigTransactionFeeCheckWorksCorrect)
{
    try {
        new Bank("", 100);
        FAIL();
    } catch (std::invalid_argument &e) {
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}

TEST_F(BankFixture, AddAccountWorksCorrect)
{
    bank->AddAccount(0);
    bank->AddAccount(1);
    try {
        bank->AddAccount(1);
        FAIL();
    } catch (std::invalid_argument &e) {
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}

TEST_F(BankFixture, RemoveAccountWorksCorrect)
{
    bank->AddAccount(0);
    bank->RemoveAccount(0);
    try {
        bank->GetBalance(0);
        FAIL();
    } catch (std::invalid_argument &e) {
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}

TEST_F(BankFixture, GetBalanceThrowsExceptionOnUnkownClient)
{
    try {
        bank->GetBalance(0);
        FAIL();
    } catch (std::invalid_argument &e) {
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}

TEST_F(BankFixture, DepositWorksCorrect)
{
    bank->AddAccount(0);
    bank->Deposit(0, 10);
    EXPECT_EQ(bank->GetBalance(0), 10);
}

TEST_F(BankFixture, DepositThrowsExceptionOnUnkownClient)
{
    try {
        bank->Deposit(0, 10);
        FAIL();
    } catch (std::invalid_argument &e) {
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}

TEST_F(BankFixture, WithdrawWorksCorrect)
{
    bank->AddAccount(0);
    bank->Deposit(0, 10);
    bank->Withdraw(0, 5);
    EXPECT_EQ(bank->GetBalance(0), 5);
}

TEST_F(BankFixture, WithdrawThrowsExceptionOnUnkownClient)
{
    try {
        bank->Withdraw(0, 10);
        FAIL();
    } catch (std::invalid_argument &e) {
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}

TEST_F(BankFixture, TransferWorksCorrect)
{
    bank->AddAccount(0);
    bank->AddAccount(1);
    bank->Deposit(0, 100);
    bank->Transfer(0, 1, 80);
    EXPECT_EQ(bank->GetBalance(0), 20);
    EXPECT_EQ(bank->GetBalance(1), 64);
    EXPECT_EQ(bank->GetBankBalance(), 16);
}

TEST_F(BankFixture, TransferThrowsExceptionOnUnknownClientFrom)
{
    bank->AddAccount(1);
    try {
        bank->Transfer(0, 1, 0);
        FAIL();
    } catch (std::invalid_argument &e) {
        EXPECT_EQ(bank->GetBalance(1), 0);
        EXPECT_EQ(bank->GetBankBalance(), 0);
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}

TEST_F(BankFixture, TransferThrowsExceptionOnUnknownClientTo)
{
    bank->AddAccount(0);
    bank->Deposit(0, 100);
    try {
        bank->Transfer(0, 1, 0);
        FAIL();
    } catch (std::invalid_argument &e) {
        EXPECT_EQ(bank->GetBalance(0), 100);
        EXPECT_EQ(bank->GetBankBalance(), 0);
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}

TEST_F(BankFixture, TransferThrowsExceptionOnInsufficientBalance)
{
    bank->AddAccount(0);
    bank->AddAccount(1);
    bank->Deposit(0, 10);
    try {
        bank->Transfer(0, 1, 100);
        FAIL();
    } catch (std::invalid_argument &e) {
        EXPECT_EQ(bank->GetBalance(0), 10);
        EXPECT_EQ(bank->GetBalance(1), 0);
        EXPECT_EQ(bank->GetBankBalance(), 0);
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}

TEST_F(BankFixture, GetBankBalanceWorksCorrect)
{
    bank->AddAccount(0);
    bank->AddAccount(1);
    bank->Deposit(0, 200);
    bank->Deposit(1, 100);
    bank->Transfer(0, 1, 100);
    EXPECT_EQ(bank->GetBankBalance(), 20);
    bank->Transfer(0, 1, 10);
    EXPECT_EQ(bank->GetBankBalance(), 22);
}

TEST_F(BankFixture, GetTotalBalanceWorksCorrect)
{
    bank->AddAccount(0);
    bank->AddAccount(1);
    bank->Deposit(0, 200);
    bank->Deposit(1, 100);
    EXPECT_EQ(bank->GetTotalBalance(), 300);
    bank->Transfer(0, 1, 100);
    EXPECT_EQ(bank->GetTotalBalance(), 300);
}

TEST_F(BankFixture, SendTransferWorksCorrect)
{
    bank->AddAccount(0);
    bank->Deposit(0, 100);
    bank->SendTransferToAnotherBank(0, 80);
    EXPECT_EQ(bank->GetBalance(0), 20);
    EXPECT_EQ(bank->GetBankBalance(), 16);
    EXPECT_EQ(bank->GetTotalBalance(), 36);
}

TEST_F(BankFixture, SendTransferThrowsExceptionOnUnknownClientFrom)
{
    try {
        bank->SendTransferToAnotherBank(0, 10);
        FAIL();
    } catch (std::invalid_argument &e) {
        EXPECT_EQ(bank->GetBankBalance(), 0);
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}

TEST_F(BankFixture, SendTransferThrowsExceptionOnInsufficiendFunds)
{
    bank->AddAccount(0);
    bank->Deposit(0, 10);
    try {
        bank->SendTransferToAnotherBank(0, 100);
        FAIL();
    } catch (std::invalid_argument &e) {
        EXPECT_EQ(bank->GetBalance(0), 10);
        EXPECT_EQ(bank->GetBankBalance(), 0);
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}

TEST_F(BankFixture, RecieveTransferWorksCorrect)
{
    bank->AddAccount(0);
    bank->ReceiveTransferFromAnotherBank(0, 80);
    EXPECT_EQ(bank->GetBalance(0), 64);
    EXPECT_EQ(bank->GetBankBalance(), 16);
}

TEST_F(BankFixture, RecieveTransferThrowsExceptionOnUnknownClientTo)
{
    try {
        bank->ReceiveTransferFromAnotherBank(0, 10);
        FAIL();
    } catch (std::invalid_argument &e) {
        EXPECT_EQ(bank->GetBankBalance(), 0);
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}
