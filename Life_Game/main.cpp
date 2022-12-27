#include "gamewindow.h"
#include <QApplication>
#include "field.h"
#include "parser.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Field field = Parser::create_field(argc, argv);
    GameWindow w(field.get_w(), field.get_h(), &field);
    w.setFixedSize(QSize((field.get_w() + 2) * pixSize + 260, std::max((field.get_h() + 2) * pixSize, w.minimumHeight())));
    w.show();
    return a.exec();
}
