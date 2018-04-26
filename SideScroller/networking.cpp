#include "networking.h"

//Names: Kyle Newton, Dustin Peters
//Project: Sidescroller
//Due Date: 4/25/2018
//Github Repository: https://github.com/Kyle-E-Newton/SideScroller

//Connects to server -- Works when supplied with correct password
//Let me know if you would like a password to use
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

//Disconnects from server
void networking::disconnectFromServer() {
	FTP.disconnect();
}

//Navigates to correct directory
void networking::goToDir() {
	FTP.changeDirectory("Desktop/Sidescroller");
}

//Gets file from server -- Doesn't work
void networking::getFileFromServer() {
	FTP.download("HighScores.txt", "resources", sf::Ftp::Ascii);
}

//Sends updated scores file
void networking::sendFileToServer() {
	FTP.upload("HighScores.txt", "desktop/Sidescroller", sf::Ftp::Binary);
}