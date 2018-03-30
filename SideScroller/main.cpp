#include "sidescroller.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game Window");
	

	drawMenu(window);
	drawWindow(window);
	
	return 0;
}