#include "Game.h"

Game::Game(const std::string& title)
    : title{title},
      windowStyle{sf::Style::Titlebar | sf::Style::Close},
      window{sf::VideoMode(900, 600), title, windowStyle},
      player{Entity(window)},
      currentWorld{World()},
      windowSize{window.getSize()},
      view{sf::FloatRect(0, 0, windowSize.x, windowSize.y)}
{
    window.setMouseCursorVisible(false);
    // window.setFramerateLimit(100);

    view.setCenter(player.getPosition());
    window.setView(view);
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
        player.moveUp();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        player.moveDown();
    }
    else
    {
        player.stopMovingVertical();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        player.moveLeft();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        player.moveRight();
    }
    else
    {
        player.stopMovingHorizontal();
    }
}

void Game::update(const sf::Time& deltaTime)
{
    player.update(deltaTime);
}

void Game::render()
{
    window.clear(sf::Color::Black);

    // draw logic
    window.draw(currentWorld);
    window.draw(player);

    window.display();
}
