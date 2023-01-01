#include "gamewindow.h"
#include <QApplication>
#include "universe.h"
#include "parser.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Universe universe = Parser::create_universe(argc, argv);
    if (Parser::is_offline()){
        universe.update_state(universe.get_ticks_count());
        universe.save_to_file();
        return 0;
    }
    GameWindow w(universe);
    w.show();
    return a.exec();
}
