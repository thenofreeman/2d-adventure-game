#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.h"

class GameState
{
    public:
        GameState() = delete;
        GameState(sf::RenderWindow& window);
        virtual ~GameState();

        void handleInput();
        void update(const sf::Time& timePerFrame);
        void draw();

    private:
        sf::RenderWindow* window;

        Entity* player;


};
