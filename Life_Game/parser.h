#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "field.h"
#include "rules.h"
#include <fstream>
#include <sstream>
#include <set>
#include <tuple>

class Parser
{
public:
    Parser();
    bool parse(const int argc, char* argv[], std::string& input_file, std::string& output_file, int& iterations_num);
    static void input_read(const std::string input, std::string* name, Rules** rules, int& x_count, int& y_count,
		std::set<std::tuple<int, int>>& tuples);
    Field* create_field(const int argc, char* argv[]);
    bool get_is_offline();

private:
    bool is_offline;
};

