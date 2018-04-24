#include "character.h"

Character::Character(sf::Vector2f size, sf::Color color)
{
	character.setSize(size);
	character.setFillColor(color);
	score = 0;
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

void Character::setScore(double numAdd)
{
	score += numAdd;
}

int Character::getY()
float Character::getY()
{
	return character.getPosition().y;
}
float Character::getX() {
	return character.getPosition().x;
}

double Character::getScore()
{
	return score;
}


float Character::getSizeY()
{
	return character.getSize().y;
}

float Character::getSizeX()
{
	return character.getSize().x;
}
