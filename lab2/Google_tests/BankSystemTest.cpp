#include "gtest/gtest.h"
#include <algorithm>
#include "BankSystem.h"

using namespace bank;

class BankSystemFixture : public ::testing::Test {
protected:
    void SetUp() override
    {
        system = new BankSystem();
    }

    void TearDown() override
    {
        delete system;
    }

    BankSystem *system{};
};

TEST_F(BankSystemFixture, AddBankWorksCorrect) {
    system->AddBank("Bank Vivaldich", 10);
    system->AddBank("Bank Cianfanellich", 15);
    auto banks = system->GetBanks();
    EXPECT_EQ(banks.size(), 2);
    EXPECT_EQ(std::ranges::find(banks, "Bank Vivaldich") != banks.end(), true);
    EXPECT_EQ(system->GetBankFee("Bank Vivaldich"), 10);
    EXPECT_EQ(std::ranges::find(banks, "Bank Cianfanellich") != banks.end(), true);
    EXPECT_EQ(system->GetBankFee("Bank Cianfanellich"), 15);
}

TEST_F(BankSystemFixture, AddBankThrowsExceptionOnExistingBank) {
    system->AddBank("Bank Vivaldich", 10);
    try {
        system->AddBank("Bank Vivaldich", 15);
        FAIL();
    } catch (std::invalid_argument &e) {
        auto banks = system->GetBanks();
        EXPECT_EQ(banks.size(), 1);
        EXPECT_EQ(std::ranges::find(banks, "Bank Vivaldich") != banks.end(), true);
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}

TEST_F(BankSystemFixture, RemoveBankWorksCorrect) {
    system->AddBank("Bank Vivaldich", 10);
    system->AddBank("Bank Cianfanellich", 15);
    system->RemoveBank("Bank Vivaldich");
    auto banks = system->GetBanks();
    EXPECT_EQ(banks.size(), 1);
    EXPECT_EQ(std::ranges::find(banks, "Bank Vivaldich") != banks.end(), false);
    EXPECT_EQ(std::ranges::find(banks, "Bank Cianfanellich") != banks.end(), true);
}

TEST_F(BankSystemFixture, RemoveBankThrowsExceptionOnNotExistingBank) {
    try {
        system->RemoveBank("Bank Vivaldich");
        FAIL();
    } catch (std::invalid_argument &e) {
        auto banks = system->GetBanks();
        EXPECT_EQ(banks.size(), 0);
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}

TEST_F(BankSystemFixture, AddClientWorksCorrect) {
    system->AddBank("Bank Vivaldich", 10);
    int id1 = system->AddClient("Bank Vivaldich", "White Wolf");
    int id2 = system->AddClient("Bank Vivaldich", "Ciri");
    EXPECT_EQ(id1, 0);
    EXPECT_EQ(system->Balance(id1), 0);
    EXPECT_EQ(id2, 1);
    EXPECT_EQ(system->Balance(id2), 0);
}

TEST_F(BankSystemFixture, AddClientThrowsExceptionOnNonExistingBank) {
    try {
        system->AddClient("Bank Vivaldich", "Escel");
        FAIL();
    } catch (std::invalid_argument &e) {
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}

TEST_F(BankSystemFixture, RemoveClientWorksCorrect) {
    system->AddBank("Bank Vivaldich", 10);
    int id = system->AddClient("Bank Vivaldich", "White Wolf");
    EXPECT_EQ(system->Balance(id), 0);
    system->RemoveClient(id);
    try {
        system->Balance(id);
        FAIL();
    } catch (std::invalid_argument &e) {
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}

TEST_F(BankSystemFixture, RemoveClientThrowsExceptionOnUnknownClient) {
    try {
        system->RemoveClient(999);
        FAIL();
    } catch (std::invalid_argument &e) {
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}

TEST_F(BankSystemFixture, DepositWorksCorrect) {
    system->AddBank("Bank Vivaldich", 10);
    int id = system->AddClient("Bank Vivaldich", "White Wolf");
    system->Deposit(id, 100);
    EXPECT_EQ(system->Balance(id), 100);
}

TEST_F(BankSystemFixture, DepositThrowsExceptionOnUnknownClient) {
    system->AddBank("Bank Vivaldich", 10);
    try {
        system->Deposit(999, 10);
        FAIL();
    } catch (std::invalid_argument &e) {
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}

TEST_F(BankSystemFixture, WithdrawWorksCorrect) {
    system->AddBank("Bank Vivaldich", 10);
    int id = system->AddClient("Bank Vivaldich", "White Wolf");
    system->Deposit(id, 100);
    EXPECT_EQ(system->Balance(id), 100);
    system->Withdraw(id, 75);
    system->Deposit(id, 25);
}

TEST_F(BankSystemFixture, WithdrawThrowsExceptionOnUnknownClient) {
    system->AddBank("Bank Vivaldich", 10);
    try {
        system->Deposit(999, 10);
        FAIL();
    } catch (std::invalid_argument &e) {
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}

TEST_F(BankSystemFixture, TransferInsideBankWorksCorrect) {
    system->AddBank("Bank Vivaldich", 10);
    int id1 = system->AddClient("Bank Vivaldich", "White Wolf");
    int id2 = system->AddClient("Bank Vivaldich", "Ciri");
    system->Deposit(id1, 100);
    system->Transfer(id1, id2, 80);
    EXPECT_EQ(system->Balance(id1), 20);
    EXPECT_EQ(system->GetBankBalance("Bank Vivaldich"), 8);
    EXPECT_EQ(system->Balance(id2), 72);
}

TEST_F(BankSystemFixture, TransferThrowsExceptionOnUnknownClientFrom) {
    system->AddBank("Bank Vivaldich", 10);
    int id1 = system->AddClient("Bank Vivaldich", "White Wolf");
    try {
        system->Transfer(999, id1, 10);
        FAIL();
    } catch (std::invalid_argument &e) {
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}

TEST_F(BankSystemFixture, TransferThrowsExceptionOnUnknownClientTo) {
    system->AddBank("Bank Vivaldich", 10);
    int id1 = system->AddClient("Bank Vivaldich", "White Wolf");
    system->Deposit(id1, 100);
    try {
        system->Transfer(id1, 100, 10);
        FAIL();
    } catch (std::invalid_argument &e) {
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}

TEST_F(BankSystemFixture, TransferBetweenBanksWorksCorrect) {
    system->AddBank("Bank Vivaldich", 10);
    system->AddBank("Bank Cianfanellich", 20);
    int id1 = system->AddClient("Bank Vivaldich", "White Wolf", true);
    int id2 = system->AddClient("Bank Cianfanellich", "Ciri");
    system->Deposit(id1, 1000);
    system->Transfer(id1, id2, 800);
    EXPECT_EQ(system->Balance(id1), 200);
    EXPECT_EQ(system->GetBankBalance("Bank Vivaldich"), 80);
    EXPECT_EQ(system->GetBankBalance("Bank Cianfanellich"), 144);
    EXPECT_EQ(system->Balance(id2), 576);
}

TEST_F(BankSystemFixture, TransferBetweenBanksThrowsExceptionOnNonCorporateClient) {
    system->AddBank("Bank Vivaldich", 10);
    system->AddBank("Bank Cianfanellich", 20);
    int id1 = system->AddClient("Bank Vivaldich", "White Wolf");
    int id2 = system->AddClient("Bank Cianfanellich", "Ciri", true);
    system->Deposit(id1, 1000);
    try {
        system->Transfer(id1, id2, 800);
        FAIL();
    } catch (std::invalid_argument &e) {
        EXPECT_EQ(system->Balance(id1), 1000);
        EXPECT_EQ(system->GetBankBalance("Bank Vivaldich"), 0);
        EXPECT_EQ(system->GetBankBalance("Bank Cianfanellich"), 0);
        EXPECT_EQ(system->Balance(id2), 0);
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}
