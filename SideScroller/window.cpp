#include "sidescroller.h"

void runGame::drawGameLevelOne(sf::RenderWindow &window) {

	sf::Texture background;
	sf::Vector2f position = sf::Vector2f(50, 1022);
	//Makes the moveable character
	Character p1({ 28, 28 }, sf::Color::Green);
	//sets for gravity
	Gravity g;
	//checks for a character jumping
	bool isJumping = false;
	
	//time 
	sf::Clock clock;
	sf::Time time;
	sf::Vector2f velocity(sf::Vector2f(0, 0));
	
	p1.setPos(position);
	gameFloor baseFloor;

	sf::View View(sf::FloatRect(0, 580, 700, 500));
	window.setView(View);
	sf::View defaultView = window.getDefaultView();
	while (window.isOpen()) {
		sf::Event event;
		float dt = clock.restart().asSeconds();
		
		if (p1.getGlobal().intersects(baseFloor.getPlatBounds()))
		{
			std::cout << "Collision" << std::endl;
			if (p1.getGlobal().left + p1.getGlobal().width > baseFloor.getPlatBounds().left)
			{
				std::cout << "Collision" << std::endl;
				p1.setPos(sf::Vector2f(baseFloor.getPlatBounds().left - p1.getGlobal().width * p1.getScale(), p1.getY()));
			}
			/*if (p1.getGlobal().left + p1.getGlobal().width > baseFloor.getPlatBounds().left + baseFloor.getPlatBounds().width)
			{

			}
			if (p1.getGlobal().top > baseFloor.getPlatBounds().top)
			{

			}
			if (p1.getGlobal().top + p1.getGlobal().height > baseFloor.getPlatBounds().top + baseFloor.getPlatBounds().height)
			{

			}*/
		}
		

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
		
		p1.move(velocity);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			velocity.x = g.getMs();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{ 
			velocity.x = -g.getMs();
		}
		else
		{
			velocity.x = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
				velocity.y = -g.getdMs();
		}

		if (p1.getY() + p1.getSizeY() < g.getGh() || velocity.y < 0)
		{
			velocity.y += g.getGs();
			
		}
		else
		{
			position.x = p1.getX();
			position.y = g.getGh();
			p1.setPos(position);
			velocity.y = 0;
		}

		p1.move(velocity);
		window.setTitle("2D Side Scroller");
		window.setVerticalSyncEnabled(true);
		window.setFramerateLimit(60);
		if (!background.loadFromFile("resources/BackGround.png")) {}
		sf::Sprite background(background);
		
		window.draw(background);
		baseFloor.drawFloor(window);
		baseFloor.drawLevel(window);
		p1.drawTo(window);

		if (p1.getX() > 550 && p1.getX() < 600) {
			View.setCenter(sf::Vector2f(800, 832));
			window.setView(View);
		}
		if (p1.getX() > 900 && p1.getX() < 950) {
			View.setCenter(sf::Vector2f(1100, 832));
			window.setView(View);
		}
		if (p1.getX() > 1300 && p1.getX() < 1350) {
			View.setCenter(sf::Vector2f(1400, 832));
			window.setView(View);
		}
		if (p1.getX() > 1600 && p1.getX() < 1650) {
			View.setCenter(sf::Vector2f(1400, 832));
			window.setView(View);
		}

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
	//p1.setPos({ 50, 1022 });

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