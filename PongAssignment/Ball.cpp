#include "Ball.h"
#include "Random.h"

using namespace sf;
using namespace gm;

Ball::Ball(const Vector2f& position, const Vector2f& size) : GameObject(position, size) {
	body.setPosition(position);
	body.setSize(size);
	resetBall();
}

void Ball::update(sf::RenderWindow& window, float deltaTime) {
	if (moving) move(Vector2f(BallMovementSpeedPerSecond * MovementDirection.x * deltaTime, BallMovementSpeedPerSecond * MovementDirection.y * deltaTime));
	else {
		if (reset) {
			timer.restart();
			reset = false;
		}
		if (timer.getElapsedTime().asSeconds() > 2.0f) {
			moving = true;
		}
	}
}

void Ball::render(sf::RenderWindow& window, float deltaTime) {
	window.draw(body);
}

void Ball::setPosition(const Vector2f& position) {
	GameObject::setPosition(position);
	body.setPosition(position);
}

void Ball::move(const Vector2f& velocity) {
	GameObject::move(velocity);
	body.setPosition(position);
}

void Ball::setMovmentDirection(sf::Vector2f direction) {
	MovementDirection = direction;
}

sf::Vector2f Ball::getMovementDirection() const {
	return MovementDirection;
}


const Color& Ball::getFillColor() const {
	return body.getFillColor();
}

void Ball::setFillColor(const Color& color) {
	body.setFillColor(color);
}

int Ball::getCurrSpeed() {
	return BallMovementSpeedPerSecond;
}

void Ball::setCurrSpeed(int speed) {
	BallMovementSpeedPerSecond = speed;
}

void Ball::bounce(int type) {
	switch (type) {
	case 1: // paddle collision
		BallMovementSpeedPerSecond += 20;
		MovementDirection = Vector2f(-MovementDirection.x, MovementDirection.y);
		break;
	case 2: // top/bottom wall collision
		MovementDirection = Vector2f(MovementDirection.x, -MovementDirection.y);
		break;
	case 3: // left/right wall collision
		
		break;
	}
}

void Ball::resetBall() {
	moving = false;
	reset = true;
	setPosition(Vector2f(530, 310));
	BallMovementSpeedPerSecond = 180;
	MovementDirection = Vector2f(-1.08, Random::Range(-0.64f, 0.64f));
}