#include "sidescroller.h"

//Names: Kyle Newton, Dustin Peters
//Project: Sidescroller
//Due Date: 4/25/2018
//Github Repository: https://github.com/Kyle-E-Newton/SideScroller

int main()
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "GameWindow", sf::Style::None);
	
	runGame obj;

	//drawMenu(window);
	obj.Game(window);

	
	return 0;
}