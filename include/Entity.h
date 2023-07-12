#pragma once

#include <SFML/Graphics.hpp>

#include "Direction.h"
#include "Textures.h"
#include "Animator.h"

class Entity : public sf::Drawable
{
    public:
        Entity();
        virtual ~Entity();

        void update(const sf::Time& timePerFrame);

    public:
        Direction movementDirection;

    private:
        sf::Sprite sprite;
        Animator animator;

        sf::Vector2f currentVelocity;

        int movementSpeed;

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        void move(const sf::Time& timePerFrame);
        void changeAnimation(const std::string& animationName);


};
