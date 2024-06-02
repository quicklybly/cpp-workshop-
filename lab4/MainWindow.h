#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <string>
#include "MainWindowModel.h"
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace lab4 {
    class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow() override;

    private slots:
        void on_selectFilesButton_clicked();
        void on_clearFilesButton_clicked();
        void on_searchUrlsButton_clicked();

    private:
        Ui::MainWindow *ui{};
        std::unique_ptr<MainWindowModel> view_model{};
    };
}

#endif
