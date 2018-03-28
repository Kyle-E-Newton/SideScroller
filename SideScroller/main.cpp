#include <SFML/Graphics.hpp>

int main()
{
	sf::Window window(sf::VideoMode(800, 600), "Game Window");

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			window.setTitle("2D Side Scroller");
			window.setVerticalSyncEnabled(true);
			
			
		}
	}
	return 0;
}