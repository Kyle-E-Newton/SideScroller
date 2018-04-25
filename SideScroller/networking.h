#pragma once

#include "sidescroller.h"

//Names: Kyle Newton, Dustin Peters
//Project: Sidescroller
//Due Date: 4/25/2018
//Github Repository: https://github.com/Kyle-E-Newton/SideScroller

//Network Base
//Still Not implemented, Possibly will be

class networking {
public:
	bool connectToServer();
	void disconnectFromServer();
	void goToDir();
	void getFileFromServer();
	void sendFileToServer();
private:
	sf::Ftp FTP;
};