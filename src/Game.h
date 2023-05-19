#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include "Entity.h"
// #include "Level.h"
#include "TileMap.h"

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

        // shouldn't be here
        Entity player;
        TileMap map;
        sf::View view;
        // Level level;
        // end

        void init();
        void shutdown();
        void processEvents();
        void update(const sf::Time& deltaTime);
        void render();


};
