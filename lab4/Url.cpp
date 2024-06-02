//
// Created by quicklybly on 6/2/24.
//

#include "Url.h"

#include <utility>

namespace lab4 {
    Url::Url(std::string file, int line, int column, std::string url):
            file(std::move(file)),
            line(line),
            column(column),
            url(std::move(url)) { }

    std::string Url::getFile() const {
        return file;
    }

    int Url::getLine() const {
        return line;
    }

    int Url::getColumn() const {
        return column;
    }

    std::string Url::getUrl() const {
        return url;
    }
}
