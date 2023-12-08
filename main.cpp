#include <QApplication>
#include <limits>
#include "mainwindow.hpp"
# include <QDebug>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
