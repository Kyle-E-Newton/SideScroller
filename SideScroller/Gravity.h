#pragma once
#include "sidescroller.h"

class Gravity
{
public:
	Gravity();
	//get ground height
	int getGh();
	//get gravity speed
	float getGs();
	//get character movespeed
	float getMs();
	//get decellarator
	float getdMs();
	//get max speed
	float getmaxS();
protected:
	//gravity const variables
	const int groundheight = 1022;
	const float gravitySpeed = 0.3f;
	const float moveSpeed = 7.0f;
	const float dMoveSpeed = 0.0001f;
	const float maxSpeed = 10.0f;
};