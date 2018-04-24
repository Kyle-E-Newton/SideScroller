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
protected:
	//gravity const variables
	const int groundheight = 1022;
	const float gravitySpeed = 4.0f;
	const float moveSpeed = 6.0f;
};