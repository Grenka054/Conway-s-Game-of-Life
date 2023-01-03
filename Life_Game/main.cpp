#include "gamewindow.h"
#include <QApplication>
#include "universe.h"
#include "parser.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    GameWindow w;
    w.show();
    return a.exec();
}
