#pragma once

#include "sidescroller.h";

class scores {
public:
	std::string getName();
	double getScore();
	std::vector<scores> readFromFile();
private:
	std::string name;
	double score;
};