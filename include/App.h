#pragma once

#include <SFML/Graphics.hpp>

#include <string>

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
        void         update();
        void           draw();

        void registerStates();

    private:
        std::string           title;
        sf::Vector2i     windowSize;
        sf::RenderWindow     window;

        sf::Time timePerFrame;

        int statusCode;

        // StateManager stateManager;
        //

};
