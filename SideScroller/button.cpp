#include "button.h"

button::button(float leftX, float rightX, float topY, float bottomY) {
	setCoordinates(leftX, rightX, topY, bottomY);
}
void button::setCoordinates(float leftX, float rightX, float topY, float bottomY)
{
	this->leftX = leftX;
	this->rightX = rightX;
	this->topY = topY;
	this->bottomY = bottomY;
}

float button::getLeft()
{
	return leftX;
}

float button::getRight()
{
	return rightX;
}

float button::getTop()
{
	return topY;
}

float button::getBottom()
{
	return bottomY;
}

void button::drawButton(sf::RenderWindow &window)
{
	sf::RectangleShape b;
	b.setSize(sf::Vector2f(this->rightX - this->leftX, this->topY - this->bottomY));
	b.setPosition(this->leftX, this->bottomY);
	b.setFillColor(sf::Color::Transparent);
	b.setOutlineColor(sf::Color::Black);
	b.setOutlineThickness(10);
	window.draw(b);
}

bool button::isButtonClicked(sf::Vector2i pos) {
	int xPos = pos.x;
	int yPos = pos.y;

	if (xPos > this->leftX && xPos < this->rightX && yPos > topY && yPos < bottomY) {
		return true;
	}
	else
		return false;
}
void button::insertText(sf::RenderWindow &window, std::string text) {
	sf::Font comicSans;
	if (!comicSans.loadFromFile("resources/fonts/comicSans.ttf")) {}
	
	sf::Text drawText;
	drawText.setFont(comicSans);
	drawText.setPosition(sf::Vector2f(leftX, topY));
	drawText.setFillColor(sf::Color::Black);
	drawText.setCharacterSize(50);
	drawText.setString(text);
	window.draw(drawText);
}