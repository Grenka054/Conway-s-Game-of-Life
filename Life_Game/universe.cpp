#include "universe.h"
#include "qfileinfo.h"

void Universe::set_cell(const int x, const int y, const char value){
    field.set_value(y, x, value);
}

void Universe::normalize_coordinates(int& x, int& y, const int w, const int h){
    x %= w;
    y %= h;
    if (x < 0) x = w + x;
    if (y < 0) y = h + y;
    if (x >= w) x = 0;
    if (y >= h) y = 0;
}

Universe::Universe() {}

Universe::Universe(const int W, const int H, const Rules rules, const std::set<std::tuple<int, int>> tuples,
                   const std::string name, const std::string output_file, const int ticks_count) {
    h = H;
    w = W;
    this->name = name;
    this->output_file = output_file;
    this->ticks_count = ticks_count;
    this->rules = rules;
    field = Field(H, W);
    for (std::tuple<int, int> tuple : tuples){
        int x = std::get<1>(tuple), y = std::get<0>(tuple);
        normalize_coordinates(x, y, w, h);
        field.set_value(y, x, 1);
    }
}

Field Universe::get_field() {
    return field;
}

Rules Universe::get_rules() {
    return rules;
}

int Universe::get_ticks_count(){
    return ticks_count;
}

int Universe::get_h(){
    return h;
}

int Universe::get_w(){
    return w;
}

std::string Universe::get_name(){
    return name;
}

std::string Universe::get_output_file(){
    return output_file;
}

void Universe::update_state(const int iter_num) {
    bool nothing_changed = false;
    for (int iter = 0; iter < iter_num; ++iter) {
        if (nothing_changed) return;
        nothing_changed = true;
        Field new_field(h, w);

        for (short y = 0; y < this->h; y++) {
            for (short x = 0; x < this->w; x++) {
                int neighbour_count = 0;
                for (signed char i = -1; i <= 1; i++) {
                    for (signed char j = -1; j <= 1; j++) {
                        int neighbour_x = x + i, neighbour_y = y + j;
                        normalize_coordinates(neighbour_x, neighbour_y, this->w, this->h);
                        neighbour_count += field.get_value(neighbour_y, neighbour_x);
                    }
                }
                neighbour_count -= field.get_value(y, x);
                for (char i = 0; i < rules.get_survive().size(); i++) {
                    if (neighbour_count == rules.get_survive()[i] && field.get_value(y, x)) {
                        new_field.set_value(y, x, 1);
                        break;
                    }
                }
                for (char i = 0; i < rules.get_born().size(); i++) {
                    if (neighbour_count == rules.get_born()[i]) {
                        new_field.set_value(y, x, 1);
                        break;
                    }
                }

                if(new_field.get_value(y, x) != field.get_value(y, x))
                    nothing_changed = false;
            }
        }
        field = std::move(new_field);
    }
}

void Universe::save_to_file() {
    save_to_file(QString::fromStdString(output_file));
}

void Universe::save_to_file(const QString output){
    QFile file(output);
    QFileInfo fileInfo(file.fileName());
    QString filename(fileInfo.fileName());
    if (file.open(QIODevice::WriteOnly | QFile::Text)) {
        QTextStream stream(&file);
        filename.erase(filename.end()-4, filename.end());
        stream <<"#Life 1.06\n#N " << filename << "\n#R B";

        //RULES
        for (char rule : rules.get_born())
            stream << char(rule + '0');
        stream << "/S";
        for (auto rule : rules.get_survive())
            stream << char(rule + '0');
        stream << "\n";

        //ALIVE CELLS
        stream << get_h() << " " << get_w() << "\n";
        for (int y = 0; y < get_h(); ++y)
            for (int x = 0; x < get_w(); ++x)
                if (field.get_value(y, x)) stream << y << " " << x << "\n";
        file.close();
    }
}
