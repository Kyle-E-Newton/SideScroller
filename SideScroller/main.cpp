#include "sidescroller.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game Window");
	
	runGame obj;

	//drawMenu(window);
	obj.drawWindow(window);

	
	return 0;
}