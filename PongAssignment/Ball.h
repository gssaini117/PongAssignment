#ifndef BALL_H
#define BALL_H

#include "GameObject.h"

namespace gm {

    class Ball : public GameObject
    {
    protected:
        int BallMovementSpeedPerSecond;
        sf::RectangleShape body;
        sf::Vector2f MovementDirection;
        sf::Clock timer;
        bool moving;
        bool reset;
    public:
        Ball(const sf::Vector2f& position, const sf::Vector2f& size);
        virtual void update(sf::RenderWindow& window, float deltaTime) override;
        virtual void render(sf::RenderWindow& window, float deltaTime) override;

        virtual void setPosition(const sf::Vector2f& position) override;
        // Move the box from its current position to a new one with a specified velocity
        virtual void move(const sf::Vector2f& velocity) override;
        virtual void setMovmentDirection(sf::Vector2f direction);
        virtual sf::Vector2f getMovementDirection() const;

        const sf::Color& getFillColor() const;
        void setFillColor(const sf::Color& color);

        int getCurrSpeed();
        void setCurrSpeed(int speed);

        void bounce(int type);
        void resetBall();
    };
}

#endif