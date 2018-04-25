#pragma once

#include "sidescroller.h"

//Names: Kyle Newton, Dustin Peters
//Project: Sidescroller
//Due Date: 4/25/2018
//Github Repository: https://github.com/Kyle-E-Newton/SideScroller

//Character Object

class Character	: public sf::RectangleShape {
public:
	Character();
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
	bool isColliding(sf::RectangleShape &floor, sf::RectangleShape &collision);
	float getXLeft();
	float getXRight();
private:
	sf::RectangleShape character;
	std::string name;
	double score;
	int scale;
};

class Mob : public Character
{
public:
	Mob();
	void drawTo(sf::RenderWindow &window);
	void aiMove(bool *left, bool *right);
private:
	sf::RectangleShape mob;
	
};