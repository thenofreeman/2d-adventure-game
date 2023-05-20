#pragma once

#include <SFML/Graphics.hpp>

#include "Animator.h"

class Entity : public sf::Drawable
{
    public:
        Entity();
        virtual ~Entity();

        void init();
        void destruct();

        void update(const sf::Time& deltaTime);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        void setVelocity(const sf::Vector2f& velocity);
        sf::Vector2f getVelocity() const;
        void setMaxVelocity(const sf::Vector2f& velocity);
        sf::Vector2f getMaxVelocity() const;
        void setPosition(const sf::Vector2f& pos);
        sf::Vector2f getPosition() const;

        void changeAnimation(const std::string& animationName);

        void action(); // eg. attack
        void interact(); // eg. talk, open chest

        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        void stopMovingVertical();
        void stopMovingHorizontal();

    protected:
        sf::Vector2f pos;
        sf::Sprite sprite;
        Animator animator;

        // sf::Vector2<bool> isMoving;
        struct { bool x, y; } isMoving;

        sf::Vector2f currentVelocity;
        sf::Vector2f maxVelocity;

};
