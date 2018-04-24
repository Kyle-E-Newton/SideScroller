#pragma once

#include "sidescroller.h"

class coin : public sf::Sprite {
public:
	coin(int xPos, int yPos);
	void drawCoin(sf::RenderWindow &window);
private:
	int value, xPos, yPos;
};