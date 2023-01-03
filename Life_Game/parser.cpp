#include "parser.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <QCoreApplication>
#include <QMessageBox>
#include <iostream>

bool Parser::parse(std::string& input_file, std::string& output_file, int& iterations_num) {
    int argc = QCoreApplication::arguments().count();
    QList argv = QCoreApplication::arguments();
	input_file = "", output_file = "";
	iterations_num = 0;
	if (argc == 1) return false;
    if (argc == 2) {
        input_file = argv[1].toStdString();
        return true;
    }
    input_file = argv[1].toStdString();
    for (int i = 2; i < argc; i++)
    {
        std::string arg = argv[i].toStdString();
        std::string name_arg = "--iterations=";
        if (!arg.find(name_arg)) {
            iterations_num = std::stoi(arg.erase(0, name_arg.length()));
            continue;
        }
        name_arg = "-i";
        if (!arg.compare(name_arg)) {
            iterations_num = argv[i + 1].toInt();
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
            output_file = argv[i + 1].toStdString();
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

bool Parser::is_offline(){
    QStringList list = QCoreApplication::arguments();
    return list.length() > 2;
}

void Parser::input_read(const std::string input, std::string& name, Rules& rules, int& y_count, int& x_count,
	std::set<std::tuple<int, int>>& tuples) {
	std::ifstream fin(input);
	bool rules_got = false, name_got = false;
	if (!fin) {
        if (!Parser::is_offline()) {
            QMessageBox messageBox;
            messageBox.warning(0,"Warning","The file hasn't been opened");
            messageBox.setFixedSize(500,200);
        }
        else {
            std::cerr << "ERROR! The file hasn't been opened" << std::endl;
            exit(99);
        }
	}
	std::string buf;

	// HEADER
	getline(fin, buf);
	if (buf.compare("#Life 1.06")) {
        if (!Parser::is_offline()) {
            QMessageBox messageBox;
            messageBox.warning(0,"Warning","This file type is not supported");
            messageBox.setFixedSize(500,200);
        }
        else {
            std::cerr << "ERROR! This file type is not supported" << std::endl;
            exit(99);
        }
        return;
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
            rules = Rules(born, survive);
		}
	}
	while (buf.empty() && !fin.eof()) {
		getline(fin, buf);
	}

    // universe SIZE
	std::stringstream bufStream(buf);
	getline(bufStream, buf, ' ');
    y_count = stoi(buf);
	getline(bufStream, buf, ' ');
    x_count = stoi(buf);

	// ALIVE CELLS
	while (!fin.eof()) {
		int x, y;
		getline(fin, buf);
		if (!buf.length()) continue;
		std::stringstream bufStream(buf);
		getline(bufStream, buf, ' ');
        y = stoi(buf);
		getline(bufStream, buf, ' ');
        x = stoi(buf);
        if (!std::get<1>(tuples.insert(std::tuple<int, int>(y, x)))) {
            if (Parser::is_offline())
                std::cerr << "WARNING! Living cells are repetitive" << std::endl;
            else {
                QMessageBox messageBox;
                messageBox.warning(0,"Warning","Living cells are repetitive");
                messageBox.setFixedSize(500,200);
            }
        }
	}
	fin.close();
	if (!name_got) {
        if (!Parser::is_offline()) {
            QMessageBox messageBox;
            messageBox.warning(0,"Warning","The name hasn't founded");
            messageBox.setFixedSize(500,200);
        }
        else std::cerr << "WARNING! The name hasn't founded" << std::endl;
        name = "No name";
	}
	if (!rules_got) {
        if (!Parser::is_offline()) {
            QMessageBox messageBox;
            messageBox.warning(0,"Warning","The rules hasn't founded");
            messageBox.setFixedSize(500,200);
        }
        else std::cerr << "WARNING! The rules hasn't founded" << std::endl;
	}
    fin.close();
}
