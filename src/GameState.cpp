#include "GameState.h"

#include "Direction.h"

GameState::GameState(sf::RenderWindow& window)
    : player{new Entity()},
      window{&window}
{ }

GameState::~GameState()
{ }

void GameState::handleInput()
{
    Direction direction = Direction::NONE;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        direction = Direction::UP;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        direction = Direction::DOWN;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        direction = Direction::LEFT;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        direction = Direction::RIGHT;
    }

    // TODO encapsulate
    player->movementDirection = direction;
}

void GameState::update(const sf::Time& timePerFrame)
{
    player->update(timePerFrame);
}

void GameState::draw()
{
    window->draw(*player);
}
