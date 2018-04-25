#pragma once

#include "sidescroller.h"

//Names: Kyle Newton, Dustin Peters
//Project: Sidescroller
//Due Date: 4/25/2018
//Github Repository: https://github.com/Kyle-E-Newton/SideScroller

//Gravity/Movement Speed/Movement

class Gravity {
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

	void setGroundHeight(int height);

protected:
	//gravity const variables
	int groundheight = 1022;
	const float gravitySpeed = 3.0f;
	float moveSpeed = 4.8f;
	float dMoveSpeed = 16.9f;
    float maxSpeed = 6.0f;
};