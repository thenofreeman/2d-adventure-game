#include "Entity.h"

#include "Sprites.h"
#include "Textures.h"

Entity::Entity()
    : pos{sf::Vector2f(50, 50)},
      sprite{sf::Sprite()},
      animator{sprite},
      isMoving{false, false},
      maxVelocity{sf::Vector2f(50, 50)},
      currentVelocity{maxVelocity}
{ }

Entity::~Entity()
{ }

void Entity::init()
{

}

void Entity::destruct()
{

}

void Entity::update(const sf::Time& deltaTime)
{
    if (isMoving.x || isMoving.y)
        animator.update(deltaTime);

    if (isMoving.x)
        pos.x += currentVelocity.x * deltaTime.asSeconds();
    if (isMoving.y)
        pos.y += currentVelocity.y * deltaTime.asSeconds();

    sprite.setPosition(pos);
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}

void Entity::setVelocity(const sf::Vector2f& velocity)
{
    currentVelocity = velocity;
}

sf::Vector2f Entity::getVelocity() const
{
    return currentVelocity;
}

void Entity::setMaxVelocity(const sf::Vector2f& velocity)
{
    maxVelocity = velocity;
}

sf::Vector2f Entity::getMaxVelocity() const
{
    return maxVelocity;
}

void Entity::setPosition(const sf::Vector2f& pos)
{
    this->pos = pos;
}

sf::Vector2f Entity::getPosition() const
{
    return pos;
}

void Entity::changeAnimation(const std::string& animationName)
{
    if (animator.getCurrentAnimationName() != animationName)
        animator.switchAnimation(animationName);
}

void Entity::moveUp()
{
    changeAnimation(Textures::PLAYER_WALK_UP);

    currentVelocity.y = -maxVelocity.y;

    isMoving.y = true;
}

void Entity::moveDown()
{
    changeAnimation(Textures::PLAYER_WALK_DOWN);
    currentVelocity.y = maxVelocity.y;
    isMoving.y = true;
}

void Entity::moveLeft()
{
    changeAnimation(Textures::PLAYER_WALK_SIDE);
    currentVelocity.x = -maxVelocity.x;
    isMoving.x = true;
}

void Entity::moveRight()
{
    changeAnimation(Textures::PLAYER_WALK_SIDE);
    currentVelocity.x = maxVelocity.x;
    isMoving.x = true;
}

void Entity::stopMovingVertical()
{
    isMoving.y = false;
}

void Entity::stopMovingHorizontal()
{
    isMoving.x = false;
}
