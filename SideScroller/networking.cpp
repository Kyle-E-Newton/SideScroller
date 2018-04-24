#include "networking.h"

bool networking::connectToServer() {
	FTP.connect("144.217.86.151");
	sf::Ftp::Response response;
	response = FTP.login("vnc", "VNCPassword");
	
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
