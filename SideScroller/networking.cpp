#include "networking.h"

//Names: Kyle Newton, Dustin Peters
//Project: Sidescroller
//Due Date: 4/25/2018
//Github Repository: https://github.com/Kyle-E-Newton/SideScroller


bool networking::connectToServer() {
	FTP.connect("ftp://144.217.86.151");
	FTP.login("vnc", "VNCPassword");
	sf::Ftp::Response response;
	response = FTP.login();
	if (response.isOk()) {
		return true;
	}
	else
		return false;
}

void networking::disconnectFromServer() {
	FTP.disconnect();
}

void networking::goToDir() {
	FTP.changeDirectory("Desktop/Sidescroller");
}

void networking::getFileFromServer() {
	FTP.download("HighScores.txt", "resources", sf::Ftp::Ascii);
}

void networking::sendFileToServer() {
	FTP.upload("HighScores.txt", "desktop/Sidescroller", sf::Ftp::Binary);
}