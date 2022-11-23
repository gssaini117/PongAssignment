#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>

#include "Ball.h"
#include "Paddle.h"

namespace gm {
	const int GameWidth = 1080;
	const int GameHeight = 640;

	class Game {
	private:
		sf::RenderWindow window;
		sf::Clock clock;
		float deltaTime;
		bool gameState;
		
		Ball ball;
		Paddle leftWall;
		Paddle rightWall;
		Paddle topWall;
		Paddle bottomWall;
		Paddle player;
		Paddle ai;

		sf::Text gameOver;
		sf::Text points1;
		sf::Text points2;

		int playerPoints;
		int aiPoints;

	public:
		Game();
		void run();
		void handleInput();
		void update();
		void render();
		~Game();
	};
}

#endif