#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

#include "Ball.h"
#include "Paddle.h"
#include "PlayerController.h"

namespace gm {
	const int GameWidth = 1080;
	const int GameHeight = 640;

	class Game {
	private:
		sf::RenderWindow window;
		sf::Clock clock;
		float deltaTime;
		
		Ball ball;
		Paddle player;
		Paddle ai;
		Paddle leftWall;
		Paddle rightWall;
		Paddle topWall;
		Paddle bottomWall;
		//PlayerController playerController;

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