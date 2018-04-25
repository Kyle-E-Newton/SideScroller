#pragma once

#include "sidescroller.h"

//Names: Kyle Newton, Dustin Peters
//Project: Sidescroller
//Due Date: 4/25/2018
//Github Repository: https://github.com/Kyle-E-Newton/SideScroller

//Draws Levels and needed items per level

class gameFloor {
public:
	void drawFloor(sf::RenderWindow &window);
	void drawLevel(sf::RenderWindow &window);
	void drawPyramind(sf::RenderWindow &window, float startX, float startY);
	void drawCoinsLevelOne(sf::RenderWindow &window);
	void levelOneText(sf::RenderWindow &window);
	//gets the platforms global bounds
	sf::FloatRect getPlatBounds();
private:
	sf::RectangleShape rect;
};