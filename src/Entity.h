#pragma once

#include <SFML/Graphics.hpp>

#include "Animator.h"

class Entity : public sf::Drawable
{
    public:
        Entity() = delete;
        Entity(sf::RenderWindow& window);

        void init();
        void destruct();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void update(const sf::Time& deltaTime);

        void changeAnimation(const std::string& animationName);

        void action(); // eg. attack
        void interact(); // eg. talk, open chest

        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        void stopMovingVertical();
        void stopMovingHorizontal();

        sf::Vector2f getPosition() const;

    private:
        sf::RenderWindow& window;
        sf::Vector2f pos;
        sf::Sprite sprite;
        Animator animator;

        bool moving [2];
        sf::Vector2f currentMovementSpeed;
        sf::Vector2f movementSpeed;

};
