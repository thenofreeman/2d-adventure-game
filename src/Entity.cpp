#include "Entity.h"

#include "Sprites.h"
#include "Textures.h"

Entity::Entity(sf::RenderWindow& window)
    : window{window},
      pos{sf::Vector2f(50, 50)},
      sprite{sf::Sprite()},
      animator{sprite},
      moving{false, false},
      movementSpeed{sf::Vector2f(50, 50)},
      currentMovementSpeed{movementSpeed}
{
    sf::Vector2i spriteSize(32, 32);
    sprite.setOrigin(sf::Vector2f(spriteSize) * 0.5f);

    sprite.setTextureRect(sf::IntRect(0, 0, spriteSize.x, spriteSize.y));

    auto& walkUpAnimation = animator.createAnimation(Textures::PLAYER_WALK_UP,
                                                     IMG_PATH + Textures::PLAYER_WALK_UP + IMG_EXT,
                                                     sf::seconds(1), true);
    walkUpAnimation.addFrames(sf::Vector2i(0, 0), spriteSize, 10);
    auto& walkDownAnimation = animator.createAnimation(Textures::PLAYER_WALK_DOWN,
                                                       IMG_PATH + Textures::PLAYER_WALK_DOWN + IMG_EXT,
                                                       sf::seconds(1), true);
    walkDownAnimation.addFrames(sf::Vector2i(0, 0), spriteSize, 10);
    auto& walkLeftAnimation = animator.createAnimation(Textures::PLAYER_WALK_SIDE,
                                                       IMG_PATH + Textures::PLAYER_WALK_SIDE + IMG_EXT,
                                                       sf::seconds(1), true);
    walkLeftAnimation.addFrames(sf::Vector2i(0, 0), spriteSize, 10);
    auto& walkRightAnimation = animator.createAnimation(Textures::PLAYER_WALK_SIDE,
                                                        IMG_PATH + Textures::PLAYER_WALK_SIDE + IMG_EXT,
                                                        sf::seconds(1), true);
    walkRightAnimation.addFrames(sf::Vector2i(0, 0), spriteSize, 10);
}

void Entity::init()
{

}

void Entity::destruct()
{

}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}

void Entity::update(const sf::Time& deltaTime)
{
    if (moving[0] || moving[1])
        animator.update(deltaTime);

    if (moving[0])
        pos.x += currentMovementSpeed.x * deltaTime.asSeconds();
    if (moving[1])
        pos.y += currentMovementSpeed.y * deltaTime.asSeconds();

    sprite.setPosition(pos);
}

void Entity::changeAnimation(const std::string& animationName)
{
    if (animator.getCurrentAnimationName() != animationName)
        animator.switchAnimation(animationName);
}

void Entity::moveUp()
{
    changeAnimation(Textures::PLAYER_WALK_UP);

    currentMovementSpeed.y = -movementSpeed.y;

    moving[1] = true;
}

void Entity::moveDown()
{
    changeAnimation(Textures::PLAYER_WALK_DOWN);
    currentMovementSpeed.y = movementSpeed.y;
    moving[1] = true;
}

void Entity::moveLeft()
{
    changeAnimation(Textures::PLAYER_WALK_SIDE);
    currentMovementSpeed.x = -movementSpeed.x;
    moving[0] = true;
}

void Entity::moveRight()
{
    changeAnimation(Textures::PLAYER_WALK_SIDE);
    currentMovementSpeed.x = movementSpeed.x;
    moving[0] = true;
}

void Entity::stopMovingVertical()
{
    moving[1] = false;
}

void Entity::stopMovingHorizontal()
{
    moving[0] = false;
}

sf::Vector2f Entity::getPosition() const
{
    return pos;
}
