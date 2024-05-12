//
// Created by quicklybly on 5/11/24.
//

#ifndef LAB2_CLIENT_H
#define LAB2_CLIENT_H

#include <string>
#include <memory>

namespace bank {
    class Client {
    protected:
        int id;
        std::string name;
        bool is_corporate;
    public:
        Client(int  id, std::string name);
        Client(int  id, std::string name, bool is_corporate);
        ~Client();

        [[nodiscard]] int GetId() const;
        [[nodiscard]] const std::string& GetName() const;
        [[nodiscard]] bool IsCorporate() const;
    };
}

#endif //LAB2_CLIENT_H
