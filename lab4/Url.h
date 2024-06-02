#ifndef LAB4_URL_H
#define LAB4_URL_H

#include <string>

namespace lab4 {
    class Url {
    private:
        std::string file;
        int line;
        int column;
        std::string url;
    public:
        Url(std::string file, int line, int column, std::string url);
        ~Url() = default;

        [[nodiscard]] std::string getFile() const;
        [[nodiscard]] int getLine() const;
        [[nodiscard]] int getColumn() const;
        [[nodiscard]] std::string getUrl() const;
    };
}

#endif //LAB4_URL_H
