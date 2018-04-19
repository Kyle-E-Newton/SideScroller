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
	const float gravitySpeed = 0.3;
	const float moveSpeed = 0.4;
};