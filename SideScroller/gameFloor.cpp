#include "gameFloor.h"

void gameFloor::drawFloor(sf::RenderWindow &window) {
	sf::Texture brick;
	if (!brick.loadFromFile("resources/Brick2.png")) {}

	//Draws 50 instances of the rectangle -- Will need to call addBrick when moving accross the screen
	for (int i = 0; i < 60; i++) {
		sf::RectangleShape Rect = sf::RectangleShape();
		Rect.setTexture(&brick);
		Rect.setSize(sf::Vector2f(32, 32));
		Rect.setPosition(sf::Vector2f(0 + (i*32), 1050));
		window.draw(Rect);
	}
}

void gameFloor::drawLevel(sf::RenderWindow &window) {
	//Base Code
	sf::Texture brick;
	if (!brick.loadFromFile("resources/Brick2.png")) {}
	sf::RectangleShape Rect = sf::RectangleShape();
	Rect.setTexture(&brick);
	Rect.setSize(sf::Vector2f(32, 32));

	//Section 1 (0 - 15)
	Rect.setPosition(sf::Vector2f(160, 986));
	window.draw(Rect);
	Rect.setPosition(sf::Vector2f(192, 986));
	window.draw(Rect);
	Rect.setPosition(sf::Vector2f(224, 986));
	window.draw(Rect);
	Rect.setPosition(sf::Vector2f(352, 1018));
	window.draw(Rect);
	Rect.setPosition(sf::Vector2f(512, 1018));
	window.draw(Rect);
	Rect.setPosition(sf::Vector2f(640, 986));
	window.draw(Rect);
	Rect.setPosition(sf::Vector2f(672, 986));
	window.draw(Rect);
	Rect.setPosition(sf::Vector2f(704, 986));
	window.draw(Rect);
	Rect.setPosition(sf::Vector2f(736, 922));
	window.draw(Rect);
	Rect.setPosition(sf::Vector2f(768, 922));
	window.draw(Rect);
	Rect.setPosition(sf::Vector2f(800, 922));
	window.draw(Rect);
	Rect.setPosition(sf::Vector2f(832, 986));
	window.draw(Rect);
	Rect.setPosition(sf::Vector2f(864, 986));
	window.draw(Rect);
	Rect.setPosition(sf::Vector2f(896, 986));
	window.draw(Rect);
	Rect.setPosition(sf::Vector2f(928, 922));
	window.draw(Rect);
	Rect.setPosition(sf::Vector2f(960, 922));
	window.draw(Rect);
	Rect.setPosition(sf::Vector2f(992, 922));
	window.draw(Rect);	
	Rect.setPosition(sf::Vector2f(1024, 858));
	window.draw(Rect);
	Rect.setPosition(sf::Vector2f(1056, 858));
	window.draw(Rect);
	Rect.setPosition(sf::Vector2f(1088, 858));
	window.draw(Rect);
	Rect.setPosition(sf::Vector2f(1120, 922));
	window.draw(Rect);
	Rect.setPosition(sf::Vector2f(1152, 922));
	window.draw(Rect);
	Rect.setPosition(sf::Vector2f(1184, 922));
	window.draw(Rect);
	Rect.setPosition(sf::Vector2f(1216, 986));
	window.draw(Rect);
	Rect.setPosition(sf::Vector2f(1248, 986));
	window.draw(Rect);
	Rect.setPosition(sf::Vector2f(1280, 986));
	window.draw(Rect);
	
	Rect.setPosition(sf::Vector2f());

	sf::Texture spikes;
	if (!spikes.loadFromFile("resources/spikes.png")) {}
	Rect.setTexture(&spikes);
	Rect.setPosition(sf::Vector2f(1344, 1018));

	drawPyramind(window, 1504, 1018);
	window.draw(Rect);
}

void gameFloor::drawPyramind(sf::RenderWindow &window, float startX, float startY) {
	sf::Texture brick;
	if (!brick.loadFromFile("resources/Brick1.png")) {}
	sf::RectangleShape Rect = sf::RectangleShape();
	Rect.setTexture(&brick);
	Rect.setSize(sf::Vector2f(32, 32));

	//Bottom Layer
	for (int i = 0; i < 5; i++) {
		Rect.setPosition(startX + (32 * i), startY);
		window.draw(Rect);
	}
	//2nd Layer
	startX += 32;
	startY -= 32;
	for (int i = 0; i < 4; i++) {
		Rect.setPosition(startX + (32 * i), startY);
		window.draw(Rect);
	}
	//3rd Layer
	startX += 32;
	startY -= 32;
	for (int i = 0; i < 3; i++) {
		Rect.setPosition(startX + (32 * i), startY);
		window.draw(Rect);
	}
	//4th Layer
	startX += 32;
	startY -= 32;
	for (int i = 0; i < 2; i++) {
		Rect.setPosition(startX + (32 * i), startY);
		window.draw(Rect);
	}
	//5th Layer
	startX += 32;
	startY -= 32;
	Rect.setPosition(startX, startY);
	window.draw(Rect);
}
