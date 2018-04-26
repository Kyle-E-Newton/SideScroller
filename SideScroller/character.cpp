#include "character.h"

//Names: Kyle Newton, Dustin Peters
//Project: Sidescroller
//Due Date: 4/25/2018
//Github Repository: https://github.com/Kyle-E-Newton/SideScroller

Character::Character()
{
	character.setSize(sf::Vector2f{ 28, 28 });
	character.setFillColor(sf::Color::Green);
	scale = 1;
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

double Character::getScore()
{
	return score;
}

void Character::setScore(double numAdd)
{
	score += numAdd;
}


float Character::getSizeY()
{
	return character.getSize().y;
}

float Character::getSizeX()
{
	return character.getSize().x;
}

sf::FloatRect Character::getGlobal()
{
	return character.getGlobalBounds();;
}

int Character::getScale()
{
	return scale;
}

bool Character::isColliding(sf::RectangleShape &brick, sf::RectangleShape &collision)
{
	Gravity g;
	if (this->getGlobal().intersects(brick.getGlobalBounds()))
	{
		collision = brick;
		return true;
	} 
	else {
		return false;
	}

}

float Character::getXLeft()
{
	return this->getGlobalBounds().left;
}

float Character::getXRight()
{
	return this->getPosition().x + this->getGlobalBounds().left + this->getGlobalBounds().width;
}


