//
// Created by quicklybly on 5/12/24.
//

#include "BankSystem.h"

namespace bank {
    void BankSystem::AddBank(const std::string& name, double transaction_fee) {
        if (bank_name_to_bank.contains(name)) {
            throw std::invalid_argument("Bank already exists");
        }
        bank_name_to_bank[name] = std::make_unique<Bank>(name, transaction_fee);
    }

    void BankSystem::RemoveBank(const std::string& name) {
        if (!bank_name_to_bank.contains(name)) {
            throw std::invalid_argument("Bank not found");
        }
        bank_name_to_bank.erase(name);
    }

    int BankSystem::AddClient(const std::string& bank_name, const std::string& name) {
        return AddClient(bank_name, name, false);
    }

    int BankSystem::AddClient(const std::string& bank_name, const std::string& name, bool is_corporate) {
        if (!bank_name_to_bank.contains(bank_name)) {
            throw std::invalid_argument("Bank not found");
        }
        client_id_to_client[client_id_generator] = std::make_unique<Client>(client_id_generator, name, is_corporate);
        client_id_to_bank_name[client_id_generator] = bank_name;
        bank_name_to_bank[bank_name]->AddAccount(client_id_generator);
        return client_id_generator++;
    }

    void BankSystem::RemoveClient(int id) {
        if (!client_id_to_client.contains(id)) {
            throw std::invalid_argument("Client not found");
        }
        client_id_to_client.erase(id);
        bank_name_to_bank[client_id_to_bank_name[id]]->RemoveAccount(id);
        client_id_to_bank_name.erase(id);
    }

    void BankSystem::Deposit(int client_id, double amount) {
        if (!client_id_to_client.contains(client_id)) {
            throw std::invalid_argument("Client not found");
        }
        bank_name_to_bank[client_id_to_bank_name[client_id]]->Deposit(client_id, amount);
    }

    void BankSystem::Withdraw(int client_id, double amount) {
        if (!client_id_to_client.contains(client_id)) {
            throw std::invalid_argument("Client not found");
        }
        bank_name_to_bank[client_id_to_bank_name[client_id]]->Withdraw(client_id, amount);
    }

    void BankSystem::Transfer(int id_from, int id_to, double amount) {
        if (!(client_id_to_client.contains(id_from) && client_id_to_client.contains(id_to))) {
            throw std::invalid_argument("Client not found");
        }

        auto bank_from = client_id_to_bank_name[id_from];
        auto bank_to = client_id_to_bank_name[id_to];

        if (bank_from != bank_to && !client_id_to_client[id_from]->IsCorporate()) {
            throw std::invalid_argument("Only corporate clients can transfer money between banks");
        } else if (bank_from != bank_to) {
            double amount_to_deposit = bank_name_to_bank[bank_from]->SendTransferToAnotherBank(id_from, amount);
            bank_name_to_bank[bank_to]->ReceiveTransferFromAnotherBank(id_to, amount_to_deposit);
            return;
        }
        bank_name_to_bank[bank_from]->Transfer(id_from, id_to, amount);
    }

    std::vector<std::string> BankSystem::GetBanks() {
        std::vector<std::string> result(bank_name_to_bank.size());
        int i = 0;
        auto it = bank_name_to_bank.begin();
        while(it != bank_name_to_bank.end()) {
            result[i] = it->first;
            it++;
            ++i;
        }
        return result;
    }

    double BankSystem::GetBankFee(const std::string& name) {
        if (!bank_name_to_bank.contains(name)) {
            throw std::invalid_argument("Bank not found");
        }
        return bank_name_to_bank[name]->GetTransactionFee();
    }

    double BankSystem::GetBankBalance(const std::string &name) {
        if (!bank_name_to_bank.contains(name)) {
            throw std::invalid_argument("Bank not found");
        }
        return bank_name_to_bank[name]->GetBankBalance();
    }

    double BankSystem::Balance(int client_id) {
        if (!client_id_to_bank_name.contains(client_id)) {
            throw std::invalid_argument("Client not found");
        }
        return bank_name_to_bank[client_id_to_bank_name[client_id]]->GetBalance(client_id);
    }
}
