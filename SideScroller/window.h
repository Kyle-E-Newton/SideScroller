#pragma once

#include "sidescroller.h"

//Names: Kyle Newton, Dustin Peters
//Project: Sidescroller
//Due Date: 4/25/2018
//Github Repository: https://github.com/Kyle-E-Newton/SideScroller

//Game Wrapper
class runGame {
public:
	void drawGameLevelOne(sf::RenderWindow &window);
	void drawMenu(sf::RenderWindow &window);
	void Game(sf::RenderWindow &window);
	void drawCredits(sf::RenderWindow &window);
	void drawHighScoreScreen(sf::RenderWindow & window);
private:
};
