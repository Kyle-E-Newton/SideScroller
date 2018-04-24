#include "sidescroller.h"

void runGame::drawGameLevelOne(sf::RenderWindow &window) {

	sf::Texture background;
	//Makes the moveable character
	Character p1({ 28, 28 }, sf::Color::Green);
	//sets for gravity
	Gravity g;
	//checks for a character jumping
	bool isJumping = false;
	
	//time 
	sf::Clock deltaTime;
	sf::Vector2f velocity;
	sf::Vector2f position;

	gameFloor baseFloor;
	p1.setPos({ 50, 1022 });
	sf::View View(sf::FloatRect(0, 580, 700, 500));
	//window.setView(View);
	sf::View defaultView = window.getDefaultView();
	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				window.clear();
				window.setView(defaultView);
				drawMenu(window);
				
			}
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
			{
				isJumping = false;
			}
		
			
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			p1.move({ 0, -22 });

			isJumping = true;
		}

			baseFloor.drawFloor(window);
			baseFloor.drawLevel(window);
			p1.drawTo(window);

			View.setCenter(sf::Vector2f(p1.getX() + 300, 832));
			window.setView(View);

			window.display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{

			velocity.x -= g.getMs();
		}
		else
		{
			velocity.x += g.getMs();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			velocity.x += g.getMs();
		}
		else
		{
			velocity.x -= g.getMs();
		}

		if (velocity.x < -g.getmaxS()) velocity.x = -g.getmaxS();
		if (velocity.x >  g.getmaxS()) velocity.x = g.getmaxS();

		if (p1.getY() < g.getGh() && isJumping == false)
		{
			velocity.y += g.getMs();
			p1.move(position);
		}


		position += velocity;
		p1.move(position);
		
	
		

		window.setTitle("2D Side Scroller");
		window.setVerticalSyncEnabled(true);
		if (!background.loadFromFile("resources/BackGround.png")) {}
		sf::Sprite background(background);
		window.setVerticalSyncEnabled(true);
		window.draw(background);

		baseFloor.drawFloor(window);
		baseFloor.drawLevel(window);
		p1.drawTo(window);
		window.display();
	
	}
}
void runGame::drawMenu(sf::RenderWindow &window) {

	sf::Texture background;

	bool menuOpen = true;
	button bQuit(272, 450, 947, 1045);
	button bCredits(272, 450, 747, 845);
	button bLevelOne(272, 450, 547, 645);

	sf::Event event;
	while (menuOpen) {
		while (window.pollEvent(event)) {
			if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) || event.type == sf::Event::Closed) {
				window.close();
				menuOpen = false;
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
				window.clear();
				menuOpen = false;
				drawGameLevelOne(window);
			}
			if (event.type == sf::Event::MouseButtonPressed && bLevelOne.isButtonClicked(sf::Mouse::getPosition())) {
				window.clear();
				menuOpen = false;
				drawGameLevelOne(window);
			}
			if (event.type == sf::Event::MouseButtonPressed && bQuit.isButtonClicked(sf::Mouse::getPosition())) {
				window.close();
				menuOpen = false;
			}
			if (event.type == sf::Event::MouseButtonPressed && bCredits.isButtonClicked(sf::Mouse::getPosition())) {
				window.clear();
				menuOpen = false;
				drawCredits(window);
			}

			window.setTitle("2D Side Scroller");
			//window.setVerticalSyncEnabled(true);
			window.setFramerateLimit(60);
			if (!background.loadFromFile("resources/Background.png")) {}
			sf::Sprite background(background);
			window.draw(background);

			bQuit.insertText(window, "Quit");
			bCredits.insertText(window, "Credits");
			bLevelOne.insertText(window, "Level 1");

			bQuit.drawButton(window);
			bCredits.drawButton(window);
			bLevelOne.drawButton(window);
			window.display();
		}
	}
}

void runGame::drawCredits(sf::RenderWindow &window) {
	sf::Texture background;

	button bMain(272, 520, 947, 1045);

	sf::Event event;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) || event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
				window.clear();
				drawGameLevelOne(window);
			}
			if (event.type == sf::Event::MouseButtonPressed && bMain.isButtonClicked(sf::Mouse::getPosition())) {
				window.clear();
				drawMenu(window);
			}

			window.setTitle("2D Side Scroller");
			window.setVerticalSyncEnabled(true);
			if (!background.loadFromFile("resources/Background.png")) {}
			sf::Sprite background(background);
			window.draw(background);

			bMain.insertText(window, "Main Menu");
			bMain.drawButton(window);
			window.display();
		}
	}
}

void runGame::Game(sf::RenderWindow &window) {
	sf::Texture background;
	//Makes the moveable character
	Character p1({ 28, 28 }, sf::Color::Green);
	//sets for gravity
	Gravity g;
	//checks for a character jumping
	bool isJumping = false;
	p1.setPos({ 50, 1022 });

	//What Window
	bool menuRunning = true;
	bool gameRunning = false;

	gameFloor baseFloor;

	window.create(sf::VideoMode::getDesktopMode(), "Borderless FullScreen", sf::Style::None);

	while (menuRunning) {
		drawMenu(window);
		menuRunning = false;
		gameRunning = true;
	}
	
	while(gameRunning){
		drawGameLevelOne(window);
		gameRunning = false;
	}
}