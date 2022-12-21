#include "gamewindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameWindow w;
//    w.resize(1800,1000);
    w.show();
    return a.exec();
}
