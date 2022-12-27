#include "field.h"
#include <stdexcept>

void Field::set_cell(int x, int y, char value){
    this->field[y][x] = value;
}

void normalize_coordinates(int& x, int& y, const int w, const int h){
    x %= w;
    y %= h;
    if (x < 0) x = w + x;
    if (y < 0) y = h + y;
    if (x >= w) x = 0;
    if (y >= h) y = 0;
}

Field::Field(int W, int H, Rules *rules, std::set<std::tuple<int, int>> tuples) {
    if (!rules) throw std::invalid_argument("Rules are not defined");
    h = H;
    w = W;
    this->rules = rules;
    field = new char* [H];
    for (int i = 0; i < H; i++)
    {
        field[i] = new char[W];
        for (int j = 0; j < W; j++)
            field[i][j] = '0';
    }
    for (std::tuple<int, int> tuple : tuples){
        int x = std::get<0>(tuple), y = std::get<1>(tuple);
        normalize_coordinates(x, y, h, w);
        field[x][y] = '1';
    }
}

Field::~Field() {
    for (int i = 0; i < this->h; i++)
        delete[] field[i];
    delete[] field;
}

char** Field::get_field() {
    return this->field;
}

int Field::get_h(){
    return h;
}

int Field::get_w(){
    return w;
}

void Field::update_state(int iter_num) {
    for (int iter = 0; iter < iter_num; ++iter) {
        char** new_field = new char* [this->h];
        Rules* rules = this->rules;

        for (int i = 0; i < this->h; i++) {
            new_field[i] = new char[this->w];
            for (int j = 0; j < this->w; j++)
                new_field[i][j] = '0';
        }

        for (short x = 0; x < this->w; x++) {
            for (short y = 0; y < this->h; y++) {
                int neighbour_count = 0;
                for (signed char i = -1; i <= 1; i++) {
                    for (signed char j = -1; j <= 1; j++) {
                        if (!i && !j) continue;
                        int neighbour_x = x + i, neighbour_y = y + j;
                        normalize_coordinates(neighbour_x, neighbour_y, this->w, this->h);

                        int neighbour = field[neighbour_y][neighbour_x];
                        if (neighbour == '1') ++neighbour_count;
                    }
                }
                for (char i = 0; i < rules->get_survive().size(); i++) {
                    if (neighbour_count == rules->get_survive()[i] && field[y][x] == '1') {
                        new_field[y][x] = '1';
                        continue;
                    }
                }
                for (char i = 0; i < rules->get_born().size(); i++)
                    if (neighbour_count == rules->get_born()[i]) new_field[y][x] = '1';
            }
        }

        for (short i = 0; i < this->get_h(); ++i)
            delete[] field[i];
        delete[] field;
        field = new_field;
    }
}
