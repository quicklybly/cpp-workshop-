#ifndef LAB4_MAINWINDOWMODEL_H
#define LAB4_MAINWINDOWMODEL_H

#include <vector>
#include <memory>
#include "Url.h"

namespace lab4 {
    class MainWindowModel {
    private:
        std::vector<std::string> files;
    public:
        MainWindowModel();
        ~MainWindowModel() = default;

        void addFile(const std::string& filename);
        std::vector<std::string> getFiles();
        void clearFiles();
        std::vector<std::unique_ptr<Url>> searchForUrls();
    };
}

#endif //LAB4_MAINWINDOWMODEL_H
