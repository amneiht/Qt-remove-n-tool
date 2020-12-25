#include "mainwindow.h"
#include <QScreen>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QRect sc = a.primaryScreen()->geometry();
    w.move(sc.right(),sc.top());
    w.setFixedSize(w.size());
    w.show();
    return a.exec();
}
