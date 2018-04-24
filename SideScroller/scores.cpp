#include "scores.h"

std::vector<scores> scores::readFromFile()
{
	std::vector<scores> score;
	std::ifstream infile;

	infile.open("resources/HighScores");

	string temp;
	double sc;
	scores scor;

	while (!infile.eof()) {
		std::getline(infile, temp, ',');
		scor.name = temp;
		std::getline(infile, temp);
		sc = std::stod(temp);
		scor.score = sc;
		score.push_back(scor);
	}

	return score;
}

string scores::getName() { return name; }
double scores::getScore() { return score; }
