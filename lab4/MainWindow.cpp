#include "ui_mainwindow.h"
#include "MainWindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <sstream>
#include <regex>

namespace lab4 {
    MainWindow::MainWindow(QWidget *parent)
            : QMainWindow(parent)
            , ui(new Ui::MainWindow), view_model(std::make_unique<MainWindowModel>()) {
        ui->setupUi(this);
    }

    MainWindow::~MainWindow() {
        delete ui;
    }

    void MainWindow::on_selectFilesButton_clicked() {
        QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Select HTML Files"), "", tr("HTML Files (*.html *.htm)"));
        for (const QString& fileName : fileNames) {
            view_model->addFile(fileName.toStdString());
        }
        ui->filesListWidget->addItems(fileNames);
    }

    void MainWindow::on_clearFilesButton_clicked() {
        view_model->clearFiles();
        ui->filesListWidget->clear();
    }

    void MainWindow::on_searchUrlsButton_clicked() {
        if (view_model->getFiles().empty()) {
            QMessageBox::warning(this, tr("No Files Selected"), tr("Please select HTML files first."));
            return;
        }

        auto results = view_model->searchForUrls();

        ui->resultsListWidget->clear();
        for (const auto& entry : results) {
            QString result = QString("File: %1, Line: %2, Column: %3, URL: %4")
                    .arg(QString::fromStdString(entry->getFile()))
                    .arg(entry->getLine())
                    .arg(entry->getColumn())
                    .arg(QString::fromStdString(entry->getUrl()));
            ui->resultsListWidget->addItem(result);
        }
    }
}
