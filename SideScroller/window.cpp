#include "sidescroller.h"

void drawWindow(sf::RenderWindow &window) {

	sf::Texture background;
	//Makes the moveable character
	Character p1({ 28, 28 }, sf::Color::Green);
	//sets for gravity
	Gravity g;
	//checks for a character jumping
	bool isJumping = false;
	p1.setPos({ 50, 1022 });

	//window.create(sf::VideoMode::getDesktopMode(), "Borderless FullScreen", sf::Style::None);
	window.create(sf::VideoMode(600, 600), "Game Window");

	sf::View View(sf::FloatRect(0, 480, 600, 600));
	window.setView(View);
	sf::View defaultView = window.getDefaultView();

	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				window.close();
			}
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::W)
				{
					isJumping = false;
				}
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W)
			{
				p1.move({ 0, -g.getMs() });
				isJumping = true;
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
			{
				p1.move({ -g.getMs(), 0 });
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D)
			{
				p1.move({ g.getMs(), 0 });
			}

			window.setTitle("2D Side Scroller");
			window.setVerticalSyncEnabled(true);
			if (!background.loadFromFile("resources/BackGround.png")) {}
			sf::Sprite background(background);
			window.setVerticalSyncEnabled(true);
			window.draw(background);
			drawFloor(window);
			drawLevel(window);
			p1.drawTo(window);
			window.display();
			
		}
	}
}
void drawMenu(sf::RenderWindow &window) {

	sf::Texture background;


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
			window.display();
		}
	}
}