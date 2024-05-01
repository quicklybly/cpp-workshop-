//
// Created by quicklybly on 5/1/24.
//

#ifndef LAB2_BANK_H
#define LAB2_BANK_H

#include <string>

namespace bank {
    class Bank {
    public:
        Bank();
        ~Bank() = default;
        std::string print();
    };

    std::string Bank::print() {
        return "hello";
    }

    Bank::Bank() = default;
}

#endif
