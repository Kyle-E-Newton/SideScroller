#pragma once

#include "sidescroller.h"

class button : public sf::RectangleShape {
public:
	button(float leftX, float rightX, float topY, float bottomY);
	void setCoordinates(float leftX, float rightX, float topY, float bottomY);
	float getLeft();
	float getRight();
	float getTop();
	float getBottom();

	void drawButton(sf::RenderWindow &window);
	bool isButtonClicked(sf::Vector2i pos);
	void insertText(sf::RenderWindow &window, std::string text);
private:
	float leftX;
	float rightX;
	float topY;
	float bottomY;
};