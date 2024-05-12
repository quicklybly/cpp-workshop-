//
// Created by quicklybly on 5/1/24.
//

#ifndef LAB2_BANK_H
#define LAB2_BANK_H

#include <string>
#include <unordered_map>
#include <memory>
#include "Account.h"

namespace bank {
    class Bank {
    private:
        double transaction_fee;
        double bank_balance;
        std::string name;
        std::unordered_map<int, std::unique_ptr<Account>> client_id_to_account;
    public:
        explicit Bank(std::string name, double transaction_fee);
        ~Bank() = default;

        double GetTotalBalance();
        double GetBankBalance() const;
        double GetTransactionFee() const;

        void AddAccount(int client_id);
        void RemoveAccount(int client_id);
        void Deposit(int client_id, double amount);
        void Withdraw(int client_id, double amount);
        double GetBalance(int client_id);
        void Transfer(int id_from, int id_to, double amount);

        double SendTransferToAnotherBank(int id_from, double amount);
        void ReceiveTransferFromAnotherBank(int id_to, double amount);
    };
}

#endif
