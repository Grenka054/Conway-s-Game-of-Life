#include "field.h"
#include "qfileinfo.h"

void Field::set_cell(int x, int y, char value){
    this->field[y][x] = value;
}

void Field::normalize_coordinates(int& x, int& y, const int w, const int h){
    x %= w;
    y %= h;
    if (x < 0) x = w + x;
    if (y < 0) y = h + y;
    if (x >= w) x = 0;
    if (y >= h) y = 0;
}

Field::Field(int W, int H, Rules *rules, std::set<std::tuple<int, int>> tuples, std::string name,
             std::string output_file, int ticks_count) {
    if (!rules) throw std::invalid_argument("Rules are not defined");
    h = H;
    w = W;
    this->name = name;
    this->output_file = output_file;
    this->ticks_count = ticks_count;
    this->rules = rules;
    field = new char* [H];
    for (int i = 0; i < H; i++) {
        field[i] = new char[W];
        for (int j = 0; j < W; j++)
            field[i][j] = 0;
    }
    for (std::tuple<int, int> tuple : tuples){
        int x = std::get<1>(tuple), y = std::get<0>(tuple);
        normalize_coordinates(x, y, w, h);
        field[y][x] = 1;
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

Rules* Field::get_rules() {
    return rules;
}

int Field::get_ticks_count(){
    return ticks_count;
}

int Field::get_h(){
    return h;
}

int Field::get_w(){
    return w;
}

std::string Field::get_name(){
    return name;
}

std::string Field::get_output_file(){
    return output_file;
}

void Field::update_state(int iter_num) {
    bool nothing_changed = false;
    for (int iter = 0; iter < iter_num; ++iter) {
        if (nothing_changed) return;
        nothing_changed = true;
        char** new_field = new char* [this->h];
        Rules* rules = this->rules;

        for (short y = 0; y < this->h; y++) {
            new_field[y] = new char[this->w];
            for (short x = 0; x < this->w; x++) {
                new_field[y][x] = 0;
                int neighbour_count = 0;
                for (signed char i = -1; i <= 1; i++) {
                    for (signed char j = -1; j <= 1; j++) {
                        if (!i && !j) continue;
                        int neighbour_x = x + i, neighbour_y = y + j;
                        normalize_coordinates(neighbour_x, neighbour_y, this->w, this->h);

                        int neighbour = field[neighbour_y][neighbour_x];
                        if (neighbour) ++neighbour_count;
                    }
                }
                for (char i = 0; i < rules->get_survive().size(); i++) {
                    if (neighbour_count == rules->get_survive()[i] && field[y][x]) {
                        new_field[y][x] = 1;
                        break;
                    }
                }
                for (char i = 0; i < rules->get_born().size(); i++) {
                    if (neighbour_count == rules->get_born()[i]) {
                        new_field[y][x] = 1;
                        break;
                    }
                }

                if(new_field[y][x] != field[y][x])
                    nothing_changed = false;
            }
        }

        for (short i = 0; i < this->get_h(); ++i)
            delete[] field[i];
        delete[] field;
        field = new_field;
    }
}

void Field::save_to_file() {
    save_to_file(QString::fromStdString(output_file));
}

void Field::save_to_file(QString output){
    QFile file(output);
    QFileInfo fileInfo(file.fileName());
    QString filename(fileInfo.fileName());
    if (file.open(QIODevice::WriteOnly | QFile::Text)) {
        QTextStream stream(&file);
        filename.erase(filename.end()-4, filename.end());
        stream <<"#Life 1.06\n#N " << filename << "\n#R B";

        //RULES
        for (char rule : rules->get_born())
            stream << char(rule + '0');
        stream << "/S";
        for (auto rule : rules->get_survive())
            stream << char(rule + '0');
        stream << "\n";

        //ALIVE CELLS
        stream << get_h() << " " << get_w() << "\n";
        for (int y = 0; y < get_h(); ++y)
            for (int x = 0; x < get_w(); ++x)
                if (field[y][x]) stream << y << " " << x << "\n";
        file.close();
    }
}
