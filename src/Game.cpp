#include "Game.h"

Game::Game(const std::string& title)
    : title{title},
      windowStyle{sf::Style::Titlebar | sf::Style::Close},
      window{sf::VideoMode(900, 600), title, windowStyle},
      player{Entity(window)},
      map{TileMap()},
      windowSize{window.getSize()},
      view{sf::FloatRect(0, 0, windowSize.x, windowSize.y)}
{
    window.setMouseCursorVisible(false);
    window.setFramerateLimit(100);

    view.setCenter(player.getPosition());
    window.setView(view);
}

Game::~Game()
{ }

void Game::run()
{
    init();

    sf::Clock clock;

    sf::Time elapsedTime = clock.restart();
    sf::Time deltaTime;

    while(window.isOpen())
    {
        deltaTime = clock.restart();

        elapsedTime += deltaTime;
        float timeAsSeconds = elapsedTime.asSeconds();

        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::init()
{
    enum Tile
    {
        GRASS=0, DIRT,

    };

    const int level[] {
        GRASS, GRASS, DIRT, GRASS, GRASS,
        GRASS, GRASS, DIRT, GRASS, GRASS,
        GRASS, GRASS, DIRT, GRASS, GRASS,
        GRASS, GRASS, DIRT, GRASS, GRASS,
        GRASS, GRASS, DIRT, GRASS, GRASS
    };

    if (!map.load("res/img/map-death-mountain.png", sf::Vector2u(32, 32), level, 5, 5));
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
    window.draw(map);
    window.draw(player);

    window.display();
}
