#include "coin.h"

//Names: Kyle Newton, Dustin Peters
//Project: Sidescroller
//Due Date: 4/25/2018
//Github Repository: https://github.com/Kyle-E-Newton/SideScroller

coin::coin()
{
}

coin::coin(int xPos, int yPos)
{
	this->xPos = xPos;
	this->yPos = yPos;
}

void coin::drawCoin(sf::RenderWindow &window)
{
	sf::Sprite c;
	sf::Texture tCoin;
	if (!tCoin.loadFromFile("resources/coin.png")) {}
	c.setTexture(tCoin);
	c.setPosition(xPos, yPos);
	c.setScale(sf::Vector2f(.1, .1));
	window.draw(c);
}
