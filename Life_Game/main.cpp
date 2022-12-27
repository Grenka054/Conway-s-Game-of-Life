#include "gamewindow.h"
#include <QApplication>
#include "field.h"
#include "parser.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Parser parser;
    Field* field = parser.create_field(argc, argv);
    if(parser.get_is_offline()){
        field->update_state(field->get_ticks_count());
        field->save_to_file();
        return 0;
    }
    GameWindow w(field);
    w.setFixedSize(QSize((field->get_w() + 2) * pixSize + 260, std::max((field->get_h() + 2) * pixSize, 150)));
    w.show();
    return a.exec();
}
