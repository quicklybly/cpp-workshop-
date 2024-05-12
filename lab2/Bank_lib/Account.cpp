//
// Created by quicklybly on 5/11/24.
//

#include "Account.h"
#include <stdexcept>

namespace bank {
    Account::Account(): balance(0) {}

    Account::~Account() = default;

    double Account::GetBalance() const {
        return balance;
    }

    void Account::Deposit(double amount) {
        if (amount < 0) {
            throw std::invalid_argument("Amount should be less or equal than zero");
        }
        balance += amount;
    }

    void Account::Withdraw(double amount) {
        if (amount < 0) {
            throw std::invalid_argument("Amount should be less or equal than zero");
        }
        if (balance < amount) {
            throw std::invalid_argument("Amount should be less or equal than balance");
        }
        balance -= amount;
    }
}
