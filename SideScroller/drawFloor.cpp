#include "drawFloor.h"

void drawFloor(sf::RenderWindow &window) {
	sf::Texture brick;
	if (!brick.loadFromFile("resources/Brick1.png")) {}

	//Draws 50 instances of the rectangle -- Will need to call addBrick when moving accross the screen
	for (int i = 0; i < 50; i++) {
		sf::RectangleShape Rect = sf::RectangleShape();
		Rect.setTexture(&brick);
		Rect.setSize(sf::Vector2f(32, 32));
		Rect.setPosition(sf::Vector2f(0 + (i*16), 568));
		window.draw(Rect);
	}
}

void addBrick(sf::RenderWindow &window) {
	//Adds Brick at edge of window, has to be called each time
	sf::Texture brick;
	if (!brick.loadFromFile("resources/Brick1.png")) {}
	sf::RectangleShape Rect = sf::RectangleShape();
	Rect.setTexture(&brick);
	Rect.setSize(sf::Vector2f(32, 32));
	Rect.setPosition(sf::Vector2f(768, 568));
	window.draw(Rect);
}