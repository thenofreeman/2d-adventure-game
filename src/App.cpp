#include "App.h"

#include <SFML/Graphics.hpp>

App::App(std::string title)
    : title{title},
      windowSize{900, 600},
      window{sf::VideoMode(windowSize.x, windowSize.y), title},
      statusCode{0}
{
    registerStates();
}

App::~App() { }

void App::startup()
{

}

void App::run()
{
    sf::Clock clock;

    timePerFrame = sf::seconds(1.0f / 60.0f);
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();

        processEvents();

        timeSinceLastUpdate += deltaTime;

        while (timeSinceLastUpdate > timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;

            processEvents();
            update();
        }

        draw();
    }
}

void App::shutdown()
{

}

int App::quit()
{
    return statusCode;
}

void App::processEvents()
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {

    }
}

void App::update()
{
    // stateManager.update(timePerFrame);
}

void App::draw()
{
    window.clear();

    // stateManager.draw();

    window.setView(window.getDefaultView());

    window.display();
}

void App::registerStates()
{
    // stateManager.registerState<...>(State);
}
