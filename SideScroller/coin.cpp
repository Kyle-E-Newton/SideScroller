#include "coin.h"

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
