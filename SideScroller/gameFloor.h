#pragma once

#include "sidescroller.h"

class gameFloor {
public:
	void drawFloor(sf::RenderWindow &window);
	void drawLevel(sf::RenderWindow &window);
	void drawPyramind(sf::RenderWindow &window, float startX, float startY);
};