#include "sidescroller.h"

//Open Window

//Menu
//Credits
//Level Selector
//Display High Score

class runGame {
public:
	void drawGameLevelOne(sf::RenderWindow &window);
	void drawMenu(sf::RenderWindow &window);
	void drawPyramid(sf::RenderWindow &window, float startX);
	void Game(sf::RenderWindow &window);
};
