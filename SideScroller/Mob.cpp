#include "sidescroller.h"

Mob::Mob()
{
	mob.setFillColor(sf::Color::Red);
	mob.setPosition(sf::Vector2f(399, 1022));
	mob.setSize(sf::Vector2f{ 28, 28 });
}

void Mob::drawTo(sf::RenderWindow & window)
{
	window.draw(mob);
}

void Mob::aiMove(bool *left, bool *right)
{
	
	if ((mob.getGlobalBounds().left + mob.getGlobalBounds().width) > 484)
	{
	    *left = true;
	}
	if ((mob.getGlobalBounds().left) < 380)
	{
		*right = true;
	}
	if (*left == true)
	{
		mob.move(-4.6, 0);
	}
	if (*right == false)
	{
		mob.move(4.6, 0);
	}
}
