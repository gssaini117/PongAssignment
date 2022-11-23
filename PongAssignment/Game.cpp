#include "Game.h"

using namespace gm;
using namespace sf;

// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() :  window(VideoMode(GameWidth, GameHeight), "Game"), 
				clock(), deltaTime(0), playerPoints(0), aiPoints(0), gameState(true),
				paddleSound(), wallSound(), pointSound(), gameoverSound(),
				ball(Vector2f(530, 310), Vector2f(20,20)), 
				player(Vector2f(100, 240), Vector2f(20, 180)), 
				ai(Vector2f(980, 240), Vector2f(20, 180)),
				leftWall(Vector2f(-10, 0), Vector2f(12, 640)),
				rightWall(Vector2f(1078, 0), Vector2f(12, 640)),
				topWall(Vector2f(0, -10), Vector2f(1080, 12)),
				bottomWall(Vector2f(0, 638), Vector2f(1080, 12))
{
	window.setFramerateLimit(60);
}

void Game::run() {
	load();
	std::cout << "GAME BEGIN" << std::endl << std::endl;
	while (window.isOpen())
	{
		// Every frame we keep track of the delta time for smoother movement
		deltaTime = clock.restart().asSeconds();

		handleInput();
		update();
		render();
	}
}

void Game::load() {
	paddlesfx.loadFromFile("Sounds/paddle_sfx.wav");
	paddleSound.setBuffer(paddlesfx);

	wallsfx.loadFromFile("Sounds/wall_sfx.wav");
	wallSound.setBuffer(wallsfx);

	pointsfx.loadFromFile("Sounds/point_sfx.wav");
	pointSound.setBuffer(pointsfx);

	gosfx.loadFromFile("Sounds/gameover_sfx.wav");
	gameoverSound.setBuffer(gosfx);
}

// Implements the handle input portion of our Game Loop Programming Pattern
void Game::handleInput() {

	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();

		if (gameState) {
			// Player control
			player.setMovementDirection(MovementDirection::None);
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Up)
					player.setMovementDirection(MovementDirection::Up);
				else if (event.key.code == Keyboard::Down)
					player.setMovementDirection(MovementDirection::Down);
				else
					player.setMovementDirection(MovementDirection::None);
			}
			if (player.collide(topWall.getCollider()) && player.getMovementDirection() == MovementDirection::Up) {
				player.setMovementDirection(MovementDirection::None);
				player.setPosition(Vector2f(100, 0));
			}
			if (player.collide(bottomWall.getCollider()) && player.getMovementDirection() == MovementDirection::Down) {
				player.setMovementDirection(MovementDirection::None);
				player.setPosition(Vector2f(100, 460));
			}
		}
		else {
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space) window.close();
		}
	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update() {
	if (gameState) {
		ball.update(window, deltaTime);
		player.update(window, deltaTime);
		ai.update(window, deltaTime);

		// collision handling
		if (ball.collide(player.getCollider())) {
			ball.bounce(1);
			paddleSound.play();
		}
		if (ball.collide(ai.getCollider())) {
			ball.bounce(1);
			paddleSound.play();
		}
		if (ball.collide(topWall.getCollider()) || ball.collide(bottomWall.getCollider())) {
			ball.bounce(2);
			wallSound.play();
		}
		if (ball.collide(leftWall.getCollider())) {
			ball.bounce(3);
			ball.resetBall();
			pointSound.play();
			aiPoints++;
			std::cout << "Player 1: " << playerPoints << std::endl;
			std::cout << "Player 2: " << aiPoints << std::endl << std::endl;
		}
		if (ball.collide(rightWall.getCollider())) {
			ball.bounce(3);
			ball.resetBall();
			pointSound.play();
			playerPoints++;
			std::cout << "Player 1: " << playerPoints << std::endl;
			std::cout << "Player 2: " << aiPoints << std::endl << std::endl;
		}

		// AI Control
		ai.setMovementDirection(MovementDirection::None);
		if (ball.getPosition().y < ai.getPosition().y + 45) {
			ai.setMovementDirection(MovementDirection::Up);
		}
		else if (ball.getPosition().y > ai.getPosition().y + 135) {
			ai.setMovementDirection(MovementDirection::Down);
		}
		else
			ai.setMovementDirection(MovementDirection::None);
		if (ai.collide(topWall.getCollider()) && ai.getMovementDirection() == MovementDirection::Up) {
			ai.setMovementDirection(MovementDirection::None);
			ai.setPosition(Vector2f(980, 0));
		}
		if (ai.collide(bottomWall.getCollider()) && ai.getMovementDirection() == MovementDirection::Down) {
			ai.setMovementDirection(MovementDirection::None);
			ai.setPosition(Vector2f(980, 460));
		}

		// win condition
		if (aiPoints == 7 || playerPoints == 7) {
			gameState = false;
			gameoverSound.play();
			std::cout << "GAME OVER" << std::endl << "Press Spacebar to Quit" << std::endl;
		}
	}
	else {

	}
}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render() {
	window.clear();

	if (gameState) {
		ball.render(window, deltaTime);
		player.render(window, deltaTime);
		ai.render(window, deltaTime);
	}

	window.display();
}

// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() {

}