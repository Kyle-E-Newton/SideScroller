#pragma once

#include "sidescroller.h"

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