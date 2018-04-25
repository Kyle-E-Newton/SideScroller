#include "Gravity.h"

//Names: Kyle Newton, Dustin Peters
//Project: Sidescroller
//Due Date: 4/25/2018
//Github Repository: https://github.com/Kyle-E-Newton/SideScroller

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

void Gravity::setGroundHeight(int height)
{
	this->groundheight = height;
}

