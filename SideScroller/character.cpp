#include "character.h"

Character::Character(sf::Vector2f size, sf::Color color)
{
	character.setSize(size);
	character.setFillColor(color);
}

void Character::drawTo(sf::RenderWindow & window)
{
	window.draw(character);
}

void Character::move(sf::Vector2f distance)
{
	character.move(distance);
}

void Character::setPos(sf::Vector2f newPos)
{
	character.setPosition(newPos);
}

float Character::getY()
{
	return character.getPosition().y;
}
float Character::getX() {
	return character.getPosition().x;
}

float Character::getSizeY()
{
	return character.getSize().y;
}

float Character::getSizeX()
{
	return character.getSize().x;
}
