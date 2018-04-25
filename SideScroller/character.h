#pragma once

#include "sidescroller.h"

class Character
{
public:
	Character(sf::Vector2f size, sf::Color color);
	void drawTo(sf::RenderWindow &window);
	void move(sf::Vector2f distance);
	void setPos(sf::Vector2f newPos);
	float getY();
	float getX();
	float getSizeY();
	float getSizeX();
private:
	sf::RectangleShape character;
};