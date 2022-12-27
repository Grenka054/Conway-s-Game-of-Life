#include "parser.h"
 #include <QProcess>
bool Parser::parse(const int argc, char* argv[], std::string& input_file, std::string& output_file, int& iterations_num) {
	input_file = "", output_file = "";
	iterations_num = 0;
	if (argc == 1) return false;
    if (argc == 2){
        input_file = argv[1];
        return true;
    }
    input_file = argv[1];
    for (int i = 2; i < argc; i++)
    {
        std::string arg = argv[i];
        std::string name_arg = "--iterations=";
        if (!arg.find(name_arg)) {
            iterations_num = std::stoi(arg.erase(0, name_arg.length()));
            continue;
        }
        name_arg = "-i";
        if (!arg.compare(name_arg)) {
            iterations_num = std::stoi(argv[i + 1]);
            ++i;
            continue;
        }
        name_arg = "--output=";
        if (!arg.find(name_arg)) {
            output_file = arg.erase(0, name_arg.length());
            continue;
        }
        name_arg = "-o";
        if (!arg.compare(name_arg)) {
            output_file = argv[i + 1];
            ++i;
            continue;
        }
    }

	if (output_file.empty() || input_file.empty() || iterations_num < 1) {
		std::cerr << "ERROR! Invalid arguments" << std::endl;
		exit(1);
	}
	return true;
}

void Parser::input_read(const std::string input, std::string& name, Rules** rules, int& x_count, int& y_count,
	std::set<std::tuple<int, int>>& tuples) {
	std::ifstream fin(input);
	bool rules_got = false, name_got = false;
	if (!fin) {
		std::cerr << "ERROR! The file hasn't been opened\n";
		exit(2);
	}
	std::string buf;

	// HEADER
	getline(fin, buf);
	if (buf.compare("#Life 1.06")) {
		std::cerr << "ERROR! This file type is not supported";
		exit(99);
	}
	while (!fin.eof()) {
		getline(fin, buf);

		if (buf[0] != '#')
			break;

		// NAME
		if (buf[1] == 'N') {
			name = buf.erase(0, 3);
			name_got = true;
		}

		// RULES
		if (buf[1] == 'R') {
			rules_got = true;
			std::stringstream bufStream(buf.erase(0, 4));
			getline(bufStream, buf, '/');
			std::vector<char> born{};
			for (char digit : buf)
				born.push_back(digit - '0');
			getline(bufStream, buf, '/');
			buf = buf.erase(0, 1);
			std::vector<char> survive{};
			for (char digit : buf)
				survive.push_back(digit - '0');
			*rules = new Rules(born, survive);
		}
	}
	while (buf.empty() && !fin.eof()) {
		getline(fin, buf);
	}
	// FIELD SIZE
	std::stringstream bufStream(buf);
	getline(bufStream, buf, ' ');
	x_count = stoi(buf);
	getline(bufStream, buf, ' ');
	y_count = stoi(buf);

	// ALIVE CELLS
	while (!fin.eof()) {
		int x, y;
		getline(fin, buf);
		if (!buf.length()) continue;
		std::stringstream bufStream(buf);
		getline(bufStream, buf, ' ');
		x = stoi(buf);
		getline(bufStream, buf, ' ');
		y = stoi(buf);
		if (!std::get<1>(tuples.insert(std::tuple<int, int>(x, y))))
			std::cerr << "WARNING! Living cells are repetitive" << std::endl;
	}
	fin.close();
	if (!name_got) {
		std::cerr << "WARNING! The name hasn't founded" << std::endl;
		name = "No name";
	}
	if (!rules_got) {
		std::cerr << "WARNING! The rules hasn't founded" << std::endl;
		*rules = new Rules();
	}
    fin.close();
}

Field Parser::create_field(const int argc, char* argv[]) {
	std::string input_file, output_file, name;
    Rules* rules = nullptr;
	int iterations_num;
	int x_count = 20, y_count = 20;
	std::set<std::tuple<int, int>> tuples;
	if (Parser::parse(argc, argv, input_file, output_file, iterations_num))
        Parser::input_read(input_file, name, &rules, x_count, y_count, tuples);
    else rules = new Rules();
    return Field(x_count, y_count, rules, tuples, name, output_file);
}
