#pragma once

#include <SFML/Graphics.hpp>

#include "Animator.h"
#include "SceneNode.h"

class Entity : public SceneNode
{
    public:
        Entity();
        virtual ~Entity();

        virtual void updateCurrent(const sf::Time& deltaTime);
        virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

        void setVelocity(const sf::Vector2f& velocity);
        sf::Vector2f getVelocity() const;
        void setMaxVelocity(const sf::Vector2f& velocity);
        sf::Vector2f getMaxVelocity() const;

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
        sf::Sprite sprite;
        Animator animator;

        sf::Vector2f currentVelocity;
        sf::Vector2f maxVelocity;

};
