#pragma once

#include "sidescroller.h"

class Character
{
public:
	Character(sf::Vector2f size, sf::Color color);
	void drawTo(sf::RenderWindow &window);
	void move(sf::Vector2f distance);
	void setPos(sf::Vector2f newPos);
	void setScore(double numAdd);
	int getY();
	int getX();
	double getScore();

private:
	sf::RectangleShape character;
	double score;
};