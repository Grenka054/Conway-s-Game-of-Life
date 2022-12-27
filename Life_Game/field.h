#ifndef FIELD_H
#define FIELD_H
#include <set>
#include <tuple>
#include <string>
#include <stdexcept>
#include <fstream>
#include <QString>
#include <QFile>
#include <QTextStream>
#include "rules.h"

class Field {
public:
    Field(int W, int H, Rules *rules, std::set<std::tuple<int, int>> tuples, std::string name,
          std::string output_file, int ticks_count); //throw
    ~Field();
    char** get_field();
    void update_state(int iter_num);
    void set_cell(int x, int y, char value);
    int get_h();
    int get_w();
    Rules* get_rules();
    std::string get_output_file();
    int get_ticks_count();
    std::string get_name();
    void save_to_file(QString output);
    void save_to_file();

private:
    char** field;
    int h;
    int w;
    Rules* rules;
    std::string name;
    std::string output_file;
    int ticks_count;
};

#endif // FIELD_H
