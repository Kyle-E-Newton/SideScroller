#include "drawFloor.h"

void drawFloor(sf::RenderWindow &window) {
	sf::RectangleShape Rect = sf::RectangleShape();
	Rect.setFillColor(sf::Color::Black);
	Rect.setSize(sf::Vector2f(800, 50));
	Rect.setPosition(sf::Vector2f(0, 550));
	window.draw(Rect);
}