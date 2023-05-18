#include "Entity.h"

#include "Sprites.h"

Entity::Entity(sf::RenderWindow& window)
    : window{window},
      pos{sf::Vector2f(50, 50)},
      sprite{sf::Sprite()},
      animator{sprite},
      moving{false, false},
      movementSpeed{sf::Vector2f(20, 20)},
      currentMovementSpeed{movementSpeed}
{
    // shape.setPosition(pos);
    // shape.setOrigin(shape.getSize() * 0.5f);

    sf::Vector2i spriteSize(32, 32);
    sprite.setTextureRect(sf::IntRect(0, 0, spriteSize.x, spriteSize.y));

    auto& walkUpAnimation = animator.createAnimation("player-walk-up", "res/img/player-walk-up.png",
                                                   sf::seconds(1), true);
    walkUpAnimation.addFrames(sf::Vector2i(0, 0), spriteSize, 10);
    auto& walkDownAnimation = animator.createAnimation("player-walk-down", "res/img/player-walk-down.png",
                                                   sf::seconds(1), true);
    walkDownAnimation.addFrames(sf::Vector2i(0, 0), spriteSize, 10);
    auto& walkLeftAnimation = animator.createAnimation("player-walk-side", "res/img/player-walk-side.png",
                                                   sf::seconds(1), true);
    walkLeftAnimation.addFrames(sf::Vector2i(0, 0), spriteSize, 10);
    auto& walkRightAnimation = animator.createAnimation("player-walk-side", "res/img/player-walk-side.png",
                                                   sf::seconds(1), true);
    walkRightAnimation.addFrames(sf::Vector2i(0, 0), spriteSize, 10);

}

void Entity::init()
{

}

void Entity::destruct()
{

}

void Entity::draw()
{
    window.draw(sprite);
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
    changeAnimation("player-walk-up");
    currentMovementSpeed.y = -movementSpeed.y;
    moving[1] = true;
}

void Entity::moveDown()
{
    changeAnimation("player-walk-down");
    currentMovementSpeed.y = movementSpeed.y;
    moving[1] = true;
}

void Entity::moveLeft()
{
    changeAnimation("player-walk-side");
    currentMovementSpeed.x = -movementSpeed.x;
    moving[0] = true;
}

void Entity::moveRight()
{
    changeAnimation("player-walk-side");
    currentMovementSpeed.x = movementSpeed.x;
    moving[0] = true;
}

void Entity::stopMoving()
{
    moving[0] = false;
    moving[1] = false;
}
