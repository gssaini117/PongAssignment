#ifndef PADDLE_H
#define PADDLE_H

#include "GameObject.h"

namespace gm {
    // Paddle movement speed
    const int PlayerMovementSpeedPerSecond = 300;

    enum MovementDirection {
        None = 0,
        Up = -1,
        Down = 1
    };

    class Paddle : public GameObject
    {
    protected:
        sf::RectangleShape body;
        MovementDirection direction;
    public:
        Paddle(const sf::Vector2f& position, const sf::Vector2f& size);
        virtual void update(sf::RenderWindow& window, float deltaTime) override;
        virtual void render(sf::RenderWindow& window, float deltaTime) override;

        virtual void setPosition(const sf::Vector2f& position) override;
        // Move the box from its current position to a new one with a specified velocity
        virtual void move(const sf::Vector2f& velocity) override;
        virtual void setMovementDirection(MovementDirection direction);
        virtual MovementDirection getMovementDirection() const;

        const sf::Color& getFillColor() const;
        void setFillColor(const sf::Color& color);
    };
}

#endif 