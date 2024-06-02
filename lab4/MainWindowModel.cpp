#include <regex>
#include <fstream>
#include "MainWindowModel.h"

namespace lab4 {
    MainWindowModel::MainWindowModel():
        files(std::vector<std::string>()){

    }

    void MainWindowModel::addFile(const std::string& filename) {
        files.push_back(filename);
    }

    std::vector<std::string> MainWindowModel::getFiles() {
        return files;
    }

    void MainWindowModel::clearFiles() {
        files.clear();
    }

    std::vector<std::unique_ptr<Url>> MainWindowModel::searchForUrls() {
        auto results = std::vector<std::unique_ptr<Url>>();
        std::regex url_regex(R"(((https?|ftp|gopher|news|telnet)://[-a-zA-Z0-9@:%._\+~#=]{1,256}\.[a-zA-Z0-9()]{1,6}\b([-a-zA-Z0-9()@:%_\+.~#?&//=]*))|(\bfile:\/\/\/[^\s"]+))");

        for (const auto& file : files) {
            std::ifstream infile(file);
            if (!infile.is_open()) {
                continue;
            }

            std::string line;
            int line_number = 0;
            while (std::getline(infile, line)) {
                ++line_number;
                std::sregex_iterator iter(line.begin(), line.end(), url_regex);
                std::sregex_iterator end;
                while (iter != end) {
                    results.push_back(
                            std::make_unique<lab4::Url>(
                                    file,
                                    line_number,
                                    iter->position(),
                                    iter->str()
                                )
                            );
                    ++iter;
                }
            }
        }

        return results;
    }
}
