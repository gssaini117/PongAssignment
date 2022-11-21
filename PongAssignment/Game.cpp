#include "Game.h"

using namespace gm;
using namespace sf;

Game::Game() {

}

Game::~Game() {

}

void Game::inputs(RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update(RenderWindow& window) {

}

void Game::render(RenderWindow& window) {
    window.clear();
    window.display();
}