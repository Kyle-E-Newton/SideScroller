#include "sidescroller.h"

void drawWindow(sf::RenderWindow &window) {

	sf::Texture background;
	Character p1;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			window.setTitle("2D Side Scroller");
			window.setVerticalSyncEnabled(true);
			if (!background.loadFromFile("resources/BackGround.png")) {}
			sf::Sprite background(background);
			window.draw(background);
			drawFloor(window);
			p1.drawChar(window);
			window.display();
		}
	}
}
void drawMenu(sf::RenderWindow &window) {

}