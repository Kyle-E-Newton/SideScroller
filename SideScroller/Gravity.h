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
	//set moveSpeed
	void setMoveSpeed(float newMs);
protected:
	//gravity const variables
	const int groundheight = 1022;
	const float gravitySpeed = 3.0f;
	float moveSpeed = 3.0f;
	float moveSpeed = 4.8f;
	float dMoveSpeed = 16.9f;
    float maxSpeed = 6.0f;
};