#ifndef FIELD_H
#define FIELD_H

#include <vector>

class Field
{
public:
    Field();
    Field(const int h, const int w);
    char get_value(const int y, const int x);
    void set_value(const int y, const int x, const char new_value);
    void resize(int new_h, int new_w);

private:
    std::vector<std::vector<char>> vec;
};

#endif // FIELD_H
