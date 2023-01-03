#ifndef UNIVERSE_H
#define UNIVERSE_H
#include <set>
#include <tuple>
#include <string>
#include <QString>
#include <QFile>
#include "rules.h"
#include "field.h"

class Universe
{
public:
    Universe();
    Universe(const int H, const int W, const Rules rules, const std::set<std::tuple<int, int>> tuples,
             const std::string name, const std::string output_file, const int ticks_count);
    void update_state(const int iter_num);
    int get_h();
    int get_w();
    void set_h(int h);
    void set_w(int w);
    Rules get_rules();
    std::string get_output_file();
    int get_ticks_count();
    std::string get_name();
    void save_to_file(const QString output);
    void save_to_file();
    static Universe create_universe();
    Field field;

private:
    int h;
    int w;
    Rules rules;
    std::string name;
    std::string output_file;
    int ticks_count;
    void normalize_coordinates(int& x, int& y, const int w, const int h);
};

#endif // UNIVERSE_H
