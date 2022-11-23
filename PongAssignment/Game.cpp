#include "Game.h"

using namespace gm;
using namespace sf;

// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() :  window(VideoMode(GameWidth, GameHeight), "Game"), 
				clock(), deltaTime(0), 
				ball(Vector2f(530, 310), Vector2f(20,20)), 
				player(Vector2f(100, 240), Vector2f(20, 180)), 
				ai(Vector2f(980, 240), Vector2f(20, 180)),
				leftWall(Vector2f(-10, 0), Vector2f(12, 640)),
				rightWall(Vector2f(1078, 0), Vector2f(12, 640)),
				topWall(Vector2f(0, -10), Vector2f(1080, 12)),
				bottomWall(Vector2f(0, 638), Vector2f(1080, 12)) {
	window.setFramerateLimit(60);
}

void Game::run() {
	while (window.isOpen())
	{
		// Every frame we keep track of the delta time for smoother movement
		deltaTime = clock.restart().asSeconds();

		handleInput();
		update();
		render();
	}
}

// Implements the handle input portion of our Game Loop Programming Pattern
void Game::handleInput() {

	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();

		// playerController.handleInput(event);
		// AIController.handleInput();

	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update() {
	ball.update(window, deltaTime);
	player.update(window, deltaTime);
	ai.update(window, deltaTime);

	// collision handling
	if (ball.collide(player.getCollider())) {
		ball.bounce(1);
	}
	if (ball.collide(ai.getCollider())) {
		ball.bounce(1);
	}
	if (ball.collide(topWall.getCollider()) || ball.collide(bottomWall.getCollider())) {
		ball.bounce(2);
	}
	if (ball.collide(leftWall.getCollider())) {
		ball.bounce(3);
		ball.resetBall();
	}
	if (ball.collide(rightWall.getCollider())) {
		ball.bounce(3);
		ball.resetBall();
	}
}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render() {
	window.clear();
	ball.render(window, deltaTime);
	player.render(window, deltaTime);
	ai.render(window, deltaTime);
	window.display();
}

// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() {

}