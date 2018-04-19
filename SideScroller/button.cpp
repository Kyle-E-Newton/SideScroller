#include "button.h"

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
