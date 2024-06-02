/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *searchUrlsButton;
    QListWidget *filesListWidget;
    QPushButton *selectFilesButton;
    QListWidget *resultsListWidget;
    QPushButton *clearFilesButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(785, 625);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 781, 571));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        searchUrlsButton = new QPushButton(gridLayoutWidget);
        searchUrlsButton->setObjectName(QString::fromUtf8("searchUrlsButton"));

        gridLayout->addWidget(searchUrlsButton, 5, 0, 1, 1);

        filesListWidget = new QListWidget(gridLayoutWidget);
        filesListWidget->setObjectName(QString::fromUtf8("filesListWidget"));

        gridLayout->addWidget(filesListWidget, 0, 0, 1, 1);

        selectFilesButton = new QPushButton(gridLayoutWidget);
        selectFilesButton->setObjectName(QString::fromUtf8("selectFilesButton"));

        gridLayout->addWidget(selectFilesButton, 3, 0, 1, 1);

        resultsListWidget = new QListWidget(gridLayoutWidget);
        resultsListWidget->setObjectName(QString::fromUtf8("resultsListWidget"));

        gridLayout->addWidget(resultsListWidget, 4, 0, 1, 1);

        clearFilesButton = new QPushButton(gridLayoutWidget);
        clearFilesButton->setObjectName(QString::fromUtf8("clearFilesButton"));

        gridLayout->addWidget(clearFilesButton, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 785, 36));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Task4", nullptr));
        searchUrlsButton->setText(QCoreApplication::translate("MainWindow", "Find URL", nullptr));
        selectFilesButton->setText(QCoreApplication::translate("MainWindow", "Select files", nullptr));
        clearFilesButton->setText(QCoreApplication::translate("MainWindow", "Clear files", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
