#pragma once

#include "sidescroller.h"

//Names: Kyle Newton, Dustin Peters
//Project: Sidescroller
//Due Date: 4/25/2018
//Github Repository: https://github.com/Kyle-E-Newton/SideScroller

//Coin object to add to score

class coin : public sf::Sprite {
public:
	coin(int xPos, int yPos);
	void drawCoin(sf::RenderWindow &window);
private:
	int value, xPos, yPos;
};