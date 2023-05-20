#include "Entity.h"

#include "Sprites.h"
#include "Textures.h"

Entity::Entity()
    : sprite{sf::Sprite()},
      animator{sprite},
      maxVelocity{sf::Vector2f(50, 50)},
      currentVelocity{maxVelocity}
{
    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

Entity::~Entity()
{ }

void Entity::updateCurrent(const sf::Time& deltaTime)
{
    if (currentVelocity != sf::Vector2f(0, 0))
        animator.update(deltaTime);

    move(currentVelocity * deltaTime.asSeconds());
}

void Entity::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
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

void Entity::changeAnimation(const std::string& animationName)
{
    if (animator.getCurrentAnimationName() != animationName)
        animator.switchAnimation(animationName);
}

void Entity::moveUp()
{
    changeAnimation(Textures::PLAYER_WALK_UP);

    currentVelocity.y = -maxVelocity.y;
}

void Entity::moveDown()
{
    changeAnimation(Textures::PLAYER_WALK_DOWN);
    currentVelocity.y = maxVelocity.y;
}

void Entity::moveLeft()
{
    changeAnimation(Textures::PLAYER_WALK_SIDE);
    currentVelocity.x = -maxVelocity.x;
}

void Entity::moveRight()
{
    changeAnimation(Textures::PLAYER_WALK_SIDE);
    currentVelocity.x = maxVelocity.x;
}

void Entity::stopMovingVertical()
{
    currentVelocity.y = 0;
}

void Entity::stopMovingHorizontal()
{
    currentVelocity.x = 0;
}
