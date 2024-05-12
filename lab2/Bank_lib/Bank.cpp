//
// Created by quicklybly on 5/1/24.
//


#include "Bank.h"
#include <stdexcept>
#include <utility>

namespace bank {
    Bank::Bank(std::string name, double transaction_fee): name(std::move(name)), bank_balance(0) {
        if (transaction_fee < 0 || transaction_fee >= 100) {
            throw std::invalid_argument("Bank transaction fee should be greater or equal to zero");
        }
        this->transaction_fee = transaction_fee;
    }

    double bank::Bank::GetTotalBalance() {
        double result = bank_balance;
        for (auto& pair : client_id_to_account) {
            result += pair.second->GetBalance();
        }
        return result;
    }

    void Bank::AddAccount(int client_id) {
        if (client_id_to_account.contains(client_id)) {
            throw std::invalid_argument("Account for this client already exists");
        }
        client_id_to_account[client_id] = std::make_unique<Account>();
    }

    double Bank::GetBankBalance() const {
        return bank_balance;
    }

    void Bank::Deposit(int client_id, double amount) {
        if (!client_id_to_account.contains(client_id)) {
            throw std::invalid_argument("Client don't have account, create it first");
        }
        client_id_to_account[client_id]->Deposit(amount);
    }

    void Bank::Withdraw(int client_id, double amount) {
        if (!client_id_to_account.contains(client_id)) {
            throw std::invalid_argument("Client don't have account, create it first");
        }
        client_id_to_account[client_id]->Withdraw(amount);
    }

    double Bank::GetBalance(int client_id) {
        if (!client_id_to_account.contains(client_id)) {
            throw std::invalid_argument("Client don't have account, create it first");
        }
        return client_id_to_account[client_id]->GetBalance();
    }

    void Bank::Transfer(int id_from, int id_to, double amount) {
        if (!(client_id_to_account.contains(id_from) && client_id_to_account[id_to])) {
            throw std::invalid_argument("Clients don't have account, create it first");
        }
        if (client_id_to_account[id_from]->GetBalance() < amount) {
            throw std::invalid_argument("Insufficient funds");
        }
        // he-he, no transaction, my bank-system don't care
        double fee = amount * (transaction_fee / 100);
        client_id_to_account[id_from]->Withdraw(amount);
        client_id_to_account[id_to]->Deposit(amount - fee);
        bank_balance += fee;
    }

    void Bank::RemoveAccount(int client_id) {
        if (!client_id_to_account.contains(client_id)) {
            throw std::invalid_argument("Client don't have account, create it first");
        }
        client_id_to_account.erase(client_id);
    }

    double Bank::SendTransferToAnotherBank(int id_from, double amount) {
        if (!client_id_to_account.contains(id_from)) {
            throw std::invalid_argument("Client don't have account, create it first");
        }
        if (client_id_to_account[id_from]->GetBalance() < amount) {
            throw std::invalid_argument("Insufficient funds");
        }
        double fee = amount * (transaction_fee / 100);
        client_id_to_account[id_from]->Withdraw(amount);
        bank_balance += fee;
        return amount - fee;
    }

    void Bank::ReceiveTransferFromAnotherBank(int id_to, double amount) {
        if (!client_id_to_account.contains(id_to)) {
            throw std::invalid_argument("Client don't have account, create it first");
        }
        double fee = amount * (transaction_fee / 100);
        client_id_to_account[id_to]->Deposit(amount - fee);
        bank_balance += fee;
    }

    double Bank::GetTransactionFee() const {
        return transaction_fee;
    }
}
