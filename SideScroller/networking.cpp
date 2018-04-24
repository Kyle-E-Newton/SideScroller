#include "networking.h"

bool networking::connectToServer()
{
	sf::Ftp FTP;
	FTP.connect("ftp://144.217.86.151", 21, sf::seconds(10));
	//sf::Ftp::Response response = FTP.login();
	FTP.login("vnc", "VNCPassword");
	/*if (response.isOk()) {
		return true;
	}*/
	//else
		return false;
}
