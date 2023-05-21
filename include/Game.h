#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include "World.h"

class Game
{
    public:
        Game(const std::string& title);
        virtual ~Game();

        void run();

    private:
        std::string title;
        sf::Uint32 windowStyle;
        sf::RenderWindow window;
        sf::Vector2f windowSize;

        World* currentWorld;

        void init();
        void shutdown();
        void processEvents();
        void update(const sf::Time& deltaTime);
        void render();

};
