#ifndef FIELD_H
#define FIELD_H
#include <set>
#include "rules.h"

class Field {
public:
    Field(int W, int H, Rules *rules, std::set<std::tuple<int, int>> tuples);
    ~Field();
    void printField();
    char** getField();
    void updateState(int iter_num);
    void setCell(int x, int y, char value);
    int get_h();
    int get_w();

private:
    char** field;
    int h;
    int w;
    Rules* rules;
};


#endif // FIELD_H
