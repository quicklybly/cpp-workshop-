//
// Created by quicklybly on 5/11/24.
//

#include "Client.h"

namespace bank {
    Client::Client(int id, std::string name):
            Client(id, std::move(name), false) {}

    Client::Client(int id, std::string name, bool is_corporate) :
            id(id),
            name(std::move(name)),
            is_corporate(is_corporate) {}

    int Client::GetId() const {
        return id;
    }

    // todo not secured code
    const std::string &Client::GetName() const {
        return name;
    }

    bool Client::IsCorporate() const {
        return is_corporate;
    }

    Client::~Client() = default;
}
