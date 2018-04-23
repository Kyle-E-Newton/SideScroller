#include "sidescroller.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "GameWindow", sf::Style::None);
	
	runGame obj;

	//drawMenu(window);
	obj.Game(window);

	
	return 0;
}