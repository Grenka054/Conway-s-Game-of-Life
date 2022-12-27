#include "gamewindow.h"
#include <iostream>
#include <string>
#include <vector>
#include "field.h"
#include "rules.h"
#include <fstream>
#include <sstream>
#include <set>

#include <QApplication>
#include <QTextStream>

bool parse(const int argc, char* argv[], std::string& input_file, std::string& output_file, int& iterations_num) {
    input_file = "game.lif", output_file = "";
    iterations_num = 0;
    switch (argc)
    {
    case 1:
        return false;

    case 2:
        input_file = argv[1];
        break;

    case 4: {
        input_file = argv[1];
        output_file = argv[2];
        iterations_num = std::stoi(argv[3]);
    }
        break;

    default:
        std::cerr << "Invalid arguments" << std::endl;
        exit(1);
    }
    return true;
}

void input_read(const std::string input, std::string& name, Rules& rules, int& x_count, int& y_count,
    std::set<std::tuple<int, int>>& tuples) {
    std::ifstream fin(input);
    bool rules_got = false, name_got = false;
    if (!fin) {
        std::cerr << "ERROR! The file hasn't been opened\n";
        exit(2);
    }
    std::string buf;

    // HEADER
    getline(fin, buf);
    if (buf.compare("#Life 1.06")) {
        std::cerr << "ERROR! This file type is not supported";
        exit(99);
    }
    while (!fin.eof()) {
        getline(fin, buf);

        if (buf[0] != '#')
            break;

        // NAME
        if (buf[1] == 'N') {
            name = buf.erase(0, 3);
        }

        // RULES
        if (buf[1] == 'R') {
            rules_got = true;
            std::stringstream bufStream(buf.erase(0, 4));
            getline(bufStream, buf, '/');
            std::vector<char> born{};
            for (char digit : buf)
                born.push_back(digit - '0');
            getline(bufStream, buf, '/');
            buf = buf.erase(0, 1);
            std::vector<char> survive{};
            for (char digit : buf)
                survive.push_back(digit - '0');
            rules = Rules(born, survive);
        }
    }

    // FIELD SIZE
    std::stringstream bufStream(buf);
    getline(bufStream, buf, ' ');
    x_count = stoi(buf);
    getline(bufStream, buf, ' ');
    y_count = stoi(buf);

    // ALIVE CELLS
    while (!fin.eof()) {
        int x, y;
        getline(fin, buf);
        if(!buf.length()) continue;
        std::stringstream bufStream(buf);
        getline(bufStream, buf, ' ');
        x = stoi(buf);
        getline(bufStream, buf, ' ');
        y = stoi(buf);
        if (!std::get<1>(tuples.insert(std::tuple<int, int>(x, y))))
            std::cerr << "WARNING! Living cells are repetitive" << std::endl;
    }
    fin.close();
    if (name_got) {
        std::cerr << "WARNING! The name hasn't founded" << std::endl;
        name = "No name";
    }
    if (!rules_got) {
        std::cerr << "WARNING! The rules hasn't founded" << std::endl;
        rules = Rules();
    }
}

int main(int argc, char* argv[])
{
    std::string input_file, output_file, name;
    Rules rules;
    int iterations_num;
    int x_count = 20, y_count = 20;
    std::set<std::tuple<int, int>> tuples;
    if(parse(argc, argv, input_file, output_file, iterations_num))
        input_read(input_file, name, rules, x_count, y_count, tuples);
    Field field = Field(x_count, y_count, &rules, tuples);
    QApplication a(argc, argv);

    GameWindow w(x_count, y_count, &field);
    w.setFixedSize(QSize((x_count + 2) * pixSize + 260, std::max((y_count + 2) * pixSize, w.minimumHeight())));
    w.show();
    return a.exec();
    return 0;
}
