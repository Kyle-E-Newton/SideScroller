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
	//get character decellaration
	//float getdMs();
	//get character max speed
protected:
	//gravity const variables
	const int groundheight = 1022;
	const float gravitySpeed = 4.0f;
	const float moveSpeed = 1.0f;
	const float dMoveSpeed = 0.01f;
	const float maxSpeed = 4.0f;
};