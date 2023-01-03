#pragma once
#include <string>
#include <set>
#include <tuple>
#include "universe.h"
#include "rules.h"

class Parser
{
public:
    static bool parse(std::string& input_file, std::string& output_file, int& iterations_num);
    static void input_read(const std::string input, std::string& name, Rules& rules, int& y_count, int& x_count,
		std::set<std::tuple<int, int>>& tuples);
    static bool is_offline();
};

