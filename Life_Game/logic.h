#pragma once
#include <iostream>
#include <vector>

class Rules {
public:
	Rules(std::vector<char> arr1, std::vector<char> arr2);
	~Rules();
	std::vector<char> born;
	std::vector<char> survive;
};

class Field {
public:
    Field(int W, int H, Rules *rules);
	~Field();
	void printField();
	char** getField();
    void updateState(int iter_num);
    void setCell(int x, int y, char value);
    int get_h();
    int get_w();
    Rules* rules;
private:
	char** field;
	int h;
	int w;
};
