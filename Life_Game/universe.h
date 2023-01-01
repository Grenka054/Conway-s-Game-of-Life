#ifndef UNIVERSE_H
#define UNIVERSE_H
#include <set>
#include <tuple>
#include <string>
#include <stdexcept>
#include <fstream>
#include <QString>
#include <QFile>
#include <QTextStream>
#include "rules.h"
#include "field.h"

class Universe
{
public:
    Universe();
    Universe(const int W, const int H, const Rules rules, const std::set<std::tuple<int, int>> tuples,
             const std::string name, const std::string output_file, const int ticks_count);
    Field get_field();
    void update_state(const int iter_num);
    void set_cell(const int x, const int y, const char value);
    int get_h();
    int get_w();
    Rules get_rules();
    std::string get_output_file();
    int get_ticks_count();
    std::string get_name();
    void save_to_file(const QString output);
    void save_to_file();

private:
    Field field;
    int h;
    int w;
    Rules rules;
    std::string name;
    std::string output_file;
    int ticks_count;
    void normalize_coordinates(int& x, int& y, const int w, const int h);
};

#endif // UNIVERSE_H
