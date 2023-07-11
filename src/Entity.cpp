#include "Entity.h"

Entity::Entity()
    : shape{sf::Vector2f(20.f, 20.f)},
      currentVelocity{sf::Vector2f(0, 0)},
      movementDirection{Direction::DOWN},
      movementSpeed{200}

{
    shape.setFillColor(sf::Color::White);
    shape.setPosition(sf::Vector2f{100.f, 100.f});
}

Entity::~Entity()
{ }

void Entity::update(const sf::Time& timePerFrame)
{
    move(timePerFrame);
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(shape, states);
}

void Entity::move(const sf::Time& timePerFrame)
{
    if (movementDirection == Direction::UP)
        currentVelocity.y = -movementSpeed * timePerFrame.asSeconds();
    else if (movementDirection == Direction::DOWN)
        currentVelocity.y =  movementSpeed * timePerFrame.asSeconds();
    else
        currentVelocity.y = 0;

    if (movementDirection == Direction::LEFT)
        currentVelocity.x = -movementSpeed * timePerFrame.asSeconds();
    else if (movementDirection == Direction::RIGHT)
        currentVelocity.x =  movementSpeed * timePerFrame.asSeconds();
    else
        currentVelocity.x = 0;

    sf::Vector2f newPosition { shape.getPosition().x + currentVelocity.x,
                               shape.getPosition().y + currentVelocity.y };
    shape.setPosition(newPosition);
}
