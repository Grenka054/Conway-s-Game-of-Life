#include "rules.h"

Rules::Rules() {
    std::vector<char> born{ 3 };
    std::vector<char> survive{ 2, 3 };
    this->born = born;
    this->survive = survive;
}

Rules::Rules(std::vector<char> born, std::vector<char> survive) {
    this->born = born;
    this->survive = survive;
}

std::vector<char> Rules::get_born(){
    return born;
}

std::vector<char> Rules::get_survive(){
    return survive;
}
