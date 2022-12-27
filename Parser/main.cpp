//#include "gamewindow.h"
#include "field.h"
#include "parser.h"

int main(int argc, char* argv[])
{
	Field field = Parser::create_field(argc, argv);
	//QApplication a(argc, argv);

	//GameWindow w(x_count, y_count, &field);
	//w.setFixedSize(QSize((x_count + 2) * pixSize + 260, std::max((y_count + 2) * pixSize, w.minimumHeight())));
	//w.show();
	//return a.exec();
}
