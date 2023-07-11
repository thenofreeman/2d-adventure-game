#pragma once

#include <SFML/Graphics.hpp>

#include "Direction.h"

class Entity : public sf::Drawable
{
    public:
        Entity();
        virtual ~Entity();

        void update(const sf::Time& timePerFrame);

    public:
        Direction movementDirection;

    private:
        sf::RectangleShape shape;

        sf::Vector2f currentVelocity;

        int movementSpeed;

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        void move(const sf::Time& timePerFrame);


};
