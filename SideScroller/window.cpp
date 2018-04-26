#include "sidescroller.h"

//Names: Kyle Newton, Dustin Peters
//Project: Sidescroller
//Due Date: 4/25/2018
//Github Repository: https://github.com/Kyle-E-Newton/SideScroller

//Draws the Game Level
void runGame::drawGameLevelOne(sf::RenderWindow &window) {

	//Background texture
	sf::Texture background;
	//Initial Player Position
	sf::Vector2f position = sf::Vector2f(50, 1022);
	//Makes the moveable character/Mob
	Character p1;
	Mob m1;
	//sets for gravity
	Gravity g;
	//checks for a character jumping
	bool isJumping = false;
	//collision object

	//Check if the Player is moving. Probably could be done with an enum
	bool MoveRight = false;
	bool MoveLeft = false;
	bool MoveUp = false;
	bool MoveDown = false;
	bool right = true;
	bool left = false;
	float least = 0;
	
	//time 
	sf::Clock clock;
	sf::Time time;

	//Player Velocity
	sf::Vector2f velocity(sf::Vector2f(0, 0));
	//Is Colliding?
	bool collide = false;
	//What it is colliding with
	sf::RectangleShape *collision = new sf::RectangleShape;
	
	//m1.setPos();
	p1.setPos(position);
	gameFloor baseFloor;

	//Game View window
	sf::View View(sf::FloatRect(0, 580, 700, 500));
	window.setView(View);
	sf::View defaultView = window.getDefaultView();
	//If the window is open
	while (window.isOpen()) {
		sf::Event event;
		float dt = clock.restart().asSeconds();
		int count = 0;

		while (window.pollEvent(event)) {
			//Check for closing with X or Alt + F4
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			//If Escape Pressed, go back to the menu
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				window.clear();
				window.setView(defaultView);
				drawMenu(window);

			}
			//Check for if jumping
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
			{
				isJumping = false;
			}


		}
		//Draw Floor and Level
		baseFloor.drawFloor(window);
		baseFloor.drawLevel(window);
	
		//Check for collision
		while (count < 26 && !collide)
		{
			
			collide = p1.isColliding(baseFloor.getRect(count), *collision);
			count++;
		}
		//Movement boolean values
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			MoveRight = true;
			MoveLeft = false;
			MoveUp = false;
			MoveDown = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			MoveRight = false;
			MoveLeft = true;
			MoveUp = false;
			MoveDown = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			MoveRight = false;
			MoveLeft = false;
			MoveUp = true;
			MoveDown = false;
		}

		//Check for collision and stopping from moving into that block
		if ((collide == true && (p1.getXRight() <= collision->getGlobalBounds().left)) && MoveRight) {
			//std::cout << "in Right Collision loop" << std::endl;
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
				position.x = p1.getX() - 10;
				position.y = g.getGh();
				p1.setPos(position);
				velocity.y = 0;
			}
			collide = false;
			//MoveRight = false;
		}
		else if (collide == true && (p1.getXLeft() <= (collision->getGlobalBounds().left + 32)) && MoveLeft) {
			//std::cout << "in Left Collision loop" << std::endl;
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
				position.x = p1.getX() + 9;
				position.y = g.getGh();
				p1.setPos(position);
				velocity.y = 0;
			}
			collide = false;
			//MoveLeft = false;
		}
		else if (collide == true)
		{
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
				MoveUp = true;
				velocity.y = -g.getdMs();
			}

		
				position.x = p1.getX();
				std::cout << " " << std::endl;
				position.y = collision->getGlobalBounds().top - 30;
				p1.setPos(position);
				
				velocity.y = 0;
				
			
		}
		 else if (!collide) {

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
				MoveUp = true;
				velocity.y = -g.getdMs();
			}

			if (p1.getY() + p1.getSizeY() < g.getGh() || velocity.y < 0)
			{
				MoveDown = false;
				velocity.y += g.getGs();
			}
			else
			{
				position.x = p1.getX();
				position.y = g.getGh();
				p1.setPos(position);
				velocity.y = 0;
			}
			collide = false;
		}

		 //Mob movement (Doesn't work)
		m1.aiMove(&left, &right);
		 
		//Move the Player
		p1.move(velocity);

		//Window setup
		window.setTitle("2D Side Scroller");
		window.setVerticalSyncEnabled(true);
		window.setFramerateLimit(60);
		if (!background.loadFromFile("resources/BackGround.png")) {}
		sf::Sprite background(background);
		
		window.draw(background);
		p1.drawTo(window);
		m1.drawTo(window);

		//Check to see if player needs to move view window. Probably needs adjusted values
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
		if (p1.getX() > 1750) {
			window.clear();
			window.setView(defaultView);
			drawMenu(window);
		}
		if (p1.getGlobalBounds().intersects(c1.getGlobalBounds())) {
			c1.setPosition(sf::Vector2f(5000, 5000));
			p1.setScore(2000);
			std::cout << p1.getScore() << std::endl;
		}

		baseFloor.drawFloor(window);
		baseFloor.drawLevel(window);
		c1.drawCoin(window);
		c2.drawCoin(window);

		window.display();
		window.clear();
		collide = false;
		}
	}
void runGame::drawMenu(sf::RenderWindow &window) {

	sf::Texture background;

	sf::Text Title;
	sf::Font comicSans;
	if (!comicSans.loadFromFile("resources/fonts/comicSans.ttf")) {}

	//Title, It's real creative
	Title.setCharacterSize(100);
	Title.setString("The Sidescroller");
	Title.setFont(comicSans);
	Title.setColor(sf::Color::Black);
	Title.setPosition(sf::Vector2f(200, 300));

	bool menuOpen = true;

	//Buttons
	button bQuit(272, 450, 947, 1045);
	button bCredits(272, 450, 747, 845);
	button bLevelOne(272, 450, 547, 645);
	button bHighScore(550, 836, 747, 845);

	sf::Event event;
	while (menuOpen) {
		//Check if window closed
		while (window.pollEvent(event)) {
			if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) || event.type == sf::Event::Closed) {
				window.close();
				menuOpen = false;
			}
			//check if Enter is pressed
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
				window.clear();
				menuOpen = false;
				drawGameLevelOne(window);
			}
			//Check if Buttons are clicked
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
			if (event.type == sf::Event::MouseButtonPressed && bHighScore.isButtonClicked(sf::Mouse::getPosition())) {
				window.clear();
				menuOpen = false;
				drawHighScoreScreen(window);
			}

			window.setTitle("2D Side Scroller");
			window.setFramerateLimit(60);
			if (!background.loadFromFile("resources/Background.png")) {}
			sf::Sprite background(background);
			window.draw(background);

			//Button drawing
			bQuit.insertText(window, "Quit");
			bCredits.insertText(window, "Credits");
			bLevelOne.insertText(window, "Level 1");
			bHighScore.insertText(window, "High Scores");

			bQuit.drawButton(window);
			bCredits.drawButton(window);
			bLevelOne.drawButton(window);
			bHighScore.drawButton(window);

			window.draw(Title);
			window.display();
		}
	}
}

//Doesnt Really do anything -- Didn't have time to implement correctly
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

//Runs the Game
void runGame::Game(sf::RenderWindow &window) {
	sf::Texture background;
	//Makes the moveable character
	Character p1;
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
	//window.create(sf::VideoMode(800, 600), "My window");

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

//Doesnt Really do anything -- Didn't have time to implement correctly
void runGame::drawHighScoreScreen(sf::RenderWindow &window) {
	//connects sucessfully when given the correct password
	networking net;
	net.connectToServer();
	net.goToDir();
	net.getFileFromServer();

	sf::Texture background;

	//Main screen button
	button bMain(272, 520, 947, 1045);

	sf::Event event;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) || event.type == sf::Event::Closed) {
				window.close();
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