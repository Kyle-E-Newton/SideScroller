#pragma once

#include "sidescroller.h"

//Names: Kyle Newton, Dustin Peters
//Project: Sidescroller
//Due Date: 4/25/2018
//Github Repository: https://github.com/Kyle-E-Newton/SideScroller

//Character Object

class Character	{
public:
	Character(sf::Vector2f size, sf::Color color);
	void drawTo(sf::RenderWindow &window);
	void move(sf::Vector2f distance);
	void setPos(sf::Vector2f newPos);
	double getScore();
	void setScore(double numAdd);
	float getY();
	float getX();
	float getSizeY();
	float getSizeX();
	sf::FloatRect getGlobal();
	int getScale();
	sf::RectangleShape isColliding(sf::RectangleShape &floor);
private:
	sf::RectangleShape character;
	std::string name;
	double score;
	int scale;
};