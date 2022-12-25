#include "rules.h"
#include <vector>

Rules::Rules(std::vector<char> arr1, std::vector<char> arr2) {
    this->born = arr1;
    this->survive = arr2;
}

std::vector<char> Rules::get_born(){
    return born;
}
std::vector<char> Rules::get_survive(){
    return survive;
}
