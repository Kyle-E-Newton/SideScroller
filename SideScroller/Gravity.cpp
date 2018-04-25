#include "Gravity.h"

Gravity::Gravity()
{
	
}

int Gravity::getGh()
{
	return groundheight;
}

float Gravity::getGs()
{
	return gravitySpeed;
}

float Gravity::getMs()
{
	return moveSpeed;
}

float Gravity::getdMs()
{
	return dMoveSpeed;
}

float Gravity::getmaxS()
{
	return 4.0f;
}

void Gravity::setMoveSpeed(float newMs)
{
	moveSpeed = newMs;
}
