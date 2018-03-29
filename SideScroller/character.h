#pragma once

#include "sidescroller.h"

class Character
{
public:
	Character();
	//setters

	//getters
	sf::RectangleShape getShape();
	sf::Vector2f getPosition();

	//functions
	void drawChar(sf::RenderWindow &window);

private:
	sf::RectangleShape shape;
	sf::Vector2f position;
};