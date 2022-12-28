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
#include <QCoreApplication>
#include <QMessageBox>

class Parser
{
public:
    Parser();
    static bool parse(const int argc, char* argv[], std::string& input_file, std::string& output_file, int& iterations_num);
    static void input_read(const std::string input, std::string* name, Rules** rules, int& x_count, int& y_count,
		std::set<std::tuple<int, int>>& tuples);
    static Field* create_field(const int argc, char* argv[]);
    static bool is_offline();

private:
};

