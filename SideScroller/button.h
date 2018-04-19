#pragma once

#include "sidescroller.h"

class button {
public:
	void setCoordinates(float leftX, float rightX, float topY, float bottomY);
	float getLeft();
	float getRight();
	float getTop();
	float getBottom();
private:
	float leftX;
	float rightX;
	float topY;
	float bottomY;
};