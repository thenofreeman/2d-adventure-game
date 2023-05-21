#include "Game.h"

#include "Player.h"

Game::Game(const std::string& title)
    : title{title},
      windowStyle{sf::Style::Titlebar | sf::Style::Close},
      window{sf::VideoMode(900, 600), title, windowStyle},
      currentWorld{new World(window)},
      windowSize{window.getSize()}
{
    window.setMouseCursorVisible(false);
}

Game::~Game()
{ }

void Game::run()
{
    init();

    sf::Clock clock;

    sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
    // sf::Time elapsedTime = clock.restart();
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();
        // elapsedTime += deltaTime;

        processEvents();

        timeSinceLastUpdate += deltaTime;

        while (timeSinceLastUpdate > timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;

            processEvents();
            update(timePerFrame);
        }

        render();
    }

    shutdown();
}

void Game::init()
{
    // Enable V-Sync
    // window.setVerticalSyncEnabled();

}

void Game::shutdown()
{

}

void Game::processEvents()
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
        currentWorld->player->moveUp();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        currentWorld->player->moveDown();
    }
    else
    {
        currentWorld->player->stopMovingVertical();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        currentWorld->player->moveLeft();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        currentWorld->player->moveRight();
    }
    else
    {
        currentWorld->player->stopMovingHorizontal();
    }
}

void Game::update(const sf::Time& deltaTime)
{
    currentWorld->update(deltaTime);
    currentWorld->player->update(deltaTime);
}

void Game::render()
{
    window.clear(sf::Color::Black);
    currentWorld->draw();

    window.setView(window.getDefaultView());

    window.display();
}
