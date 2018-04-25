#include "sidescroller.h"

//Names: Kyle Newton, Dustin Peters
//Project: Sidescroller
//Due Date: 4/25/2018
//Github Repository: https://github.com/Kyle-E-Newton/SideScroller

void runGame::drawGameLevelOne(sf::RenderWindow &window) {

	sf::Texture background;
	sf::Vector2f position = sf::Vector2f(50, 1022);
	//Makes the moveable character
	Character p1;
	Mob m1;
	//sets for gravity
	Gravity g;
	//checks for a character jumping
	bool isJumping = false;
	//collision object

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
	sf::Vector2f velocity(sf::Vector2f(0, 0));
	bool collide = false;
	sf::RectangleShape *collision = new sf::RectangleShape;
	
	//m1.setPos();
	p1.setPos(position);
	gameFloor baseFloor;

	sf::View View(sf::FloatRect(0, 580, 700, 500));
	window.setView(View);
	sf::View defaultView = window.getDefaultView();
	while (window.isOpen()) {
		sf::Event event;
		float dt = clock.restart().asSeconds();
		int count = 0;

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
		baseFloor.drawFloor(window);
		baseFloor.drawLevel(window);
	
		while (count < 26 && !collide)
		{
			
			collide = p1.isColliding(baseFloor.getRect(count), *collision);
			count++;
		}
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
				position.x = p1.getX() + 10;
				position.y = g.getGh();
				p1.setPos(position);
				velocity.y = 0;
			}
			collide = false;
			//MoveLeft = false;
		}
		else if (collide == true && (p1.getGlobalBounds().top <= (collision->getGlobalBounds().top + collision->getGlobalBounds().height)) && MoveUp)
		{
			//std::cout << "Up Collision" << std::endl;
		}
		else if (collide == true && (p1.getGlobalBounds().top + p1.getGlobalBounds().height >= collision->getGlobalBounds().top)) {
			//std::cout << "Down Collision" << std::endl;
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
				velocity.y = -g.getdMs();
			}

			if (p1.getY() + p1.getSizeY() < g.getGh() || velocity.y < 0)
			{
				least = velocity.y;
				velocity.y += g.getGs();
				if (velocity.y == std::min(velocity.y, least))
				{

				}
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
		/*p1.move(velocity);
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
		}*/

		 m1.aiMove(&left, &right);
		p1.move(velocity);
		window.setTitle("2D Side Scroller");
		window.setVerticalSyncEnabled(true);
		window.setFramerateLimit(60);
		if (!background.loadFromFile("resources/BackGround.png")) {}
		sf::Sprite background(background);
		
		window.draw(background);
		p1.drawTo(window);
		m1.drawTo(window);

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

		baseFloor.drawFloor(window);
		baseFloor.drawLevel(window);

		window.display();
		collide = false;
		}
	}
void runGame::drawMenu(sf::RenderWindow &window) {

	sf::Texture background;

	sf::Text Title;
	sf::Font comicSans;
	if (!comicSans.loadFromFile("resources/fonts/comicSans.ttf")) {}

	Title.setCharacterSize(100);
	Title.setString("The Sidescroller");
	Title.setFont(comicSans);
	Title.setColor(sf::Color::Black);
	Title.setPosition(sf::Vector2f(200, 300));

	bool menuOpen = true;
	button bQuit(272, 450, 947, 1045);
	button bCredits(272, 450, 747, 845);
	button bLevelOne(272, 450, 547, 645);
	//button bHighScore(550, 728, 747, 845);

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
			/*if (event.type == sf::Event::MouseButtonPressed && bHighScore.isButtonClicked(sf::Mouse::getPosition())) {
				window.clear();
				drawHighScoreScreen(window);
			}*/

			window.setTitle("2D Side Scroller");
			//window.setVerticalSyncEnabled(true);
			window.setFramerateLimit(60);
			if (!background.loadFromFile("resources/Background.png")) {}
			sf::Sprite background(background);
			window.draw(background);

			bQuit.insertText(window, "Quit");
			bCredits.insertText(window, "Credits");
			bLevelOne.insertText(window, "Level 1");
			//bHighScore.insertText(window, "High Scores");

			bQuit.drawButton(window);
			bCredits.drawButton(window);
			bLevelOne.drawButton(window);
			//bHighScore.drawButton(window);

			window.draw(Title);
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

void runGame::drawHighScoreScreen(sf::RenderWindow &window) {
	networking net;
	net.connectToServer();
	net.goToDir();
	net.getFileFromServer();

	sf::Texture background;

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