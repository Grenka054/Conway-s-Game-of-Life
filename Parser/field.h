#ifndef FIELD_H
#define FIELD_H
#include <set>
#include <tuple>
#include "rules.h"

class Field {
public:
    Field(int W, int H, Rules *rules, std::set<std::tuple<int, int>> tuples); //throw
    ~Field();
    char** get_field();
    void update_state(int iter_num);
    void set_cell(int x, int y, char value);
    int get_h();
    int get_w();

private:
    char** field;
    int h;
    int w;
    Rules* rules;
};


#endif // FIELD_H
