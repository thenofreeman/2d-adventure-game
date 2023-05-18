#pragma once

#include <SFML/Graphics.hpp>

class Entity
{
    public:
        Entity() = delete;
        Entity(sf::RenderWindow& window);

        void init();
        void destruct();
        void draw();
        void update();

        void action(); // eg. attack
        void interact(); // eg. talk, open chest

    private:
        sf::RenderWindow& window;
        sf::Vector2f pos;
        sf::RectangleShape shape;
        sf::Texture texture;
        sf::Sprite sprite;

};
