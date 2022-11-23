#include "PlayerController.h"

using namespace gm;
using namespace sf;

PlayerController::PlayerController() {

}

PlayerController::PlayerController(Paddle* playerPaddle) {
	player = playerPaddle;
}

PlayerController::~PlayerController() {

}

void PlayerController::handleInput(Event event) {
	// Handle keyboard input to move player paddle
	if (event.type == Event::KeyPressed) {
		if (event.key.code == Keyboard::Up) {
			player->setMovementDirection(MovementDirection::Up);
		}
		else if (event.key.code == Keyboard::Down) {
			player->setMovementDirection(MovementDirection::Down);
		}
	}
	else
		player->setMovementDirection(MovementDirection::None);
}

void PlayerController::update() {
	if (player->getPosition().y <= 0 && player->getMovementDirection() == MovementDirection::Up) {
		player->setMovementDirection(MovementDirection::None);
	}
	if (player->getPosition().y >= 400 && player->getMovementDirection() == MovementDirection::Down) {
		player->setMovementDirection(MovementDirection::None);
	}
}