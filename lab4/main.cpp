#include <QApplication>
#include <QPushButton>
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    lab4::MainWindow w;
    w.show();
    return QApplication::exec();
}
