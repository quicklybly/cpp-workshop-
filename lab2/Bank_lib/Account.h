//
// Created by quicklybly on 5/11/24.
//

#ifndef LAB2_ACCOUNT_H
#define LAB2_ACCOUNT_H

namespace bank {
    class Account {
    private:
        double balance;
    public:
        Account();
        ~Account();
        void Deposit(double amount);
        void Withdraw(double amount);
        [[nodiscard]] double GetBalance() const;
    };
}

#endif //LAB2_ACCOUNT_H
