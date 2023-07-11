#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include "GameState.h"

class App
{
    public:
        App(std::string title);

        virtual ~App();

    public:
        void  startup();
        void      run();
        void shutdown();
        int      quit();

    private:
        void  processEvents();
        void         update(const sf::Time& timePerFrame);
        void           draw();

        void registerStates();

    private:
        std::string           title;
        sf::Vector2i     windowSize;
        sf::RenderWindow     window;

        int statusCode;

        GameState game;
        // StateManager stateManager;
        //

};
