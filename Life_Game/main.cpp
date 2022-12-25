#include "gamewindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    int x_count, y_count;
    x_count = 60, y_count = 50; // 3200 cells
    x_count = 20, y_count = 20;
    QApplication a(argc, argv);

    char x[1] = { 3 };
    std::vector<char> born(x, x + sizeof x / sizeof x[0]);
    char y[2] = { 2, 3 };
//    char y[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    std::vector<char> survive(y, y + sizeof y / sizeof x[0]);
    std::vector<std::tuple<int, int>> tuples;
    tuples.push_back(std::tuple<int, int>(2,2));
    tuples.push_back(std::tuple<int, int>(3,2));
    tuples.push_back(std::tuple<int, int>(4,2));
    Rules *rules = new Rules(born, survive);
    Field *field = new Field(x_count, y_count, rules, tuples);

    GameWindow w(x_count, y_count, field);
    w.setFixedSize(QSize((x_count + 2) * pixSize + 160, (y_count + 2) * pixSize + 20));
    w.show();
    return a.exec();

}
