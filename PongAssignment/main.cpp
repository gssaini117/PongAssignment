#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>
#include "Game.h"

using namespace std;
using namespace sf;
using namespace gm;

int main()
{
    RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    Game game;
    
    // game loop
    while (window.isOpen())
    {
        game.inputs(window);
        game.update(window);
        game.render(window);
    }

    return 0;
}