//
// Created by quicklybly on 5/12/24.
//

#ifndef LAB2_BANKSYSTEM_H
#define LAB2_BANKSYSTEM_H

#include <memory>
#include <unordered_map>
#include <vector>
#include "Bank.h"
#include "Client.h"

namespace bank {
    class BankSystem {
    private:
        int client_id_generator = 0;
        std::unordered_map<std::string, std::unique_ptr<Bank>> bank_name_to_bank;
        std::unordered_map<int, std::unique_ptr<Client>> client_id_to_client;
        std::unordered_map<int, std::string> client_id_to_bank_name;
    public:
        BankSystem() = default;
        ~BankSystem() = default;

        void AddBank(const std::string& name, double transaction_fee);
        void RemoveBank(const std::string& name);

        std::vector<std::string> GetBanks();
        double GetBankFee(const std::string& name);
        double GetBankBalance(const std::string& name);

        int AddClient(const std::string& bank_name, const std::string& name);
        int AddClient(const std::string& bank_name, const std::string& name, bool is_corporate);
        void RemoveClient(int id);

        double Balance(int client_id);
        void Deposit(int client_id, double amount);
        void Withdraw(int client_id, double amount);
        void Transfer(int id_from, int id_to, double amount);
    };

}

#endif //LAB2_BANKSYSTEM_H
