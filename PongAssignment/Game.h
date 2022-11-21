#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

namespace gm {
	class Game {
	private:

	public:
		Game();										// Constructor
		~Game();									// Destructor
		void inputs(sf::RenderWindow& window);		// Inputs
		void update(sf::RenderWindow& window);		// Update
		void render(sf::RenderWindow& window);		// Render
	};
}

#endif