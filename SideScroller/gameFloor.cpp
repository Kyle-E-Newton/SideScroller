#include "gameFloor.h"

void gameFloor::drawFloor(sf::RenderWindow &window) {
	sf::Texture brick;
	if (!brick.loadFromFile("resources/Brick1.png")) {}

	//Draws 50 instances of the rectangle
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
	if (!brick.loadFromFile("resources/Brick1.png")) {}
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
	drawCoinsLevelOne(window);
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

void gameFloor::drawCoinsLevelOne(sf::RenderWindow &window)
{
	coin coin1(192, 954);
	coin1.drawCoin(window);
	coin c2(1056, 826);
	c2.drawCoin(window);
}

void gameFloor::levelOneTutorialText(sf::RenderWindow & window)
{
	sf::Font comicSans;
	if (!comicSans.loadFromFile("resources/fonts/comicSans.ttf")) {}
	sf::Text m1;	m1.setString("Use 'A' to move Left and 'D' to move right");	m1.setCharacterSize(20);
	sf::Text m2;	m2.setString("Jump on enemies to defeat them");				m2.setCharacterSize(20);
	sf::Text m3;	m3.setString("Collect Coins to increase Score");			m3.setCharacterSize(20);
	sf::Text m4;	m4.setString("Don't hit the Spikes");						m4.setCharacterSize(20);
	sf::Text m5;	m5.setString("Stand Here to end the level");				m5.setCharacterSize(20);

	m1.setFont(comicSans);	m1.setScale(.5, .5);	m1.setPosition(sf::Vector2f(10, 900));
	m2.setFont(comicSans);	m2.setScale(.5, .5);	m2.setPosition(sf::Vector2f(400, 900));
	m3.setFont(comicSans);	m3.setScale(.5, .5);	m3.setPosition(sf::Vector2f(160, 800));
	m4.setFont(comicSans);	m4.setScale(.5, .5);	m4.setPosition(sf::Vector2f(580, 900));
	m5.setFont(comicSans);	m5.setScale(.5, .5);	m5.setPosition(sf::Vector2f(660, 900));

	window.draw(m1);
	window.draw(m2);
	window.draw(m3);
	window.draw(m4);
	window.draw(m5);
}
