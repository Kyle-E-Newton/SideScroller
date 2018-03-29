#include "character.h"

Character::Character()
{
	sf::RectangleShape shape(sf::Vector2f(100.0f, 100.0f));
	sf::Vector2f position(sf::Vector2f(100, 100));
	shape.setPosition(position);
	shape.setFillColor(sf::Color::Red);
}

sf::RectangleShape Character::getShape()
{
	return shape;
}

sf::Vector2f Character::getPosition()
{
	return position;
}

void Character::drawChar(sf::RenderWindow & window)
{

	window.draw(this->getShape());
}

