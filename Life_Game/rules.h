#ifndef RULES_H
#define RULES_H
#include <vector>

class Rules {
public:
    Rules();
    Rules(const std::vector<char> born, const std::vector<char> survive);
    std::vector<char> get_born();
    std::vector<char> get_survive();

private:
    std::vector<char> born;
    std::vector<char> survive;
};

#endif // RULES_H
