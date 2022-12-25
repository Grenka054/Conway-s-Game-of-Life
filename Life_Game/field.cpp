#include "field.h"
#include <vector>

void Field::setCell(int x, int y, char value){
    this->field[y][x] = value;
}

Field::Field(int W, int H, Rules *rules, std::vector<std::tuple<int, int>> tuples) {
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
    for (std::tuple<int, int> tuple : tuples)
        field[std::get<0>(tuple)][std::get<1>(tuple)] = '1';
}

Field::~Field() {
    for (int i = 0; i < this->h; i++)
        delete[] field[i];
    delete[] field;
}

char** Field::getField() {
    return this->field;
}

int Field::get_h(){
    return h;
}

int Field::get_w(){
    return w;
}

void Field::updateState(int iter_num) {
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
                        if (neighbour_x < 0) neighbour_x = this->w - 1;
                        if (neighbour_y < 0) neighbour_y = this->h - 1;
                        if (neighbour_x >= this->w) neighbour_x = 0;
                        if (neighbour_y >= this->h) neighbour_y = 0;

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
