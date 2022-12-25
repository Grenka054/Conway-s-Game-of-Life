#ifndef RULES_H
#define RULES_H
#include <vector>

class Rules {
public:
    Rules(std::vector<char> arr1, std::vector<char> arr2);
    ~Rules();
    std::vector<char> get_born();
    std::vector<char> get_survive();
private:
    std::vector<char> born;
    std::vector<char> survive;
};

#endif // RULES_H
