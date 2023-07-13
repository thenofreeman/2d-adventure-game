#include "Entity.h"

Entity::Entity()
    : sprite{sf::Sprite()},
      animator{sprite},
      currentVelocity{sf::Vector2f(0, 0)},
      movementDirection{Direction::NONE},
      movementSpeed{200}

{
    sf::Vector2i entitySize {32, 32};
    sprite.setPosition(sf::Vector2f{100.f, 100.f});
    sprite.setOrigin(sf::Vector2f(entitySize) * 0.5f);
    sprite.setTextureRect(sf::IntRect(0, 0, entitySize.x, entitySize.y));
    sprite.setScale(1.35, 1.35);


    auto& walkUpAnimation = animator.createAnimation(Textures::PLAYER_WALK_UP, sf::seconds(1), true);
    walkUpAnimation.addFrames(sf::Vector2i(0, 0), entitySize, 10);
    auto& walkDownAnimation = animator.createAnimation(Textures::PLAYER_WALK_DOWN, sf::seconds(1), true);
    walkDownAnimation.addFrames(sf::Vector2i(0, 0), entitySize, 10);
    auto& walkLeftAnimation = animator.createAnimation(Textures::PLAYER_WALK_LEFT, sf::seconds(1), true);
    walkLeftAnimation.addFrames(sf::Vector2i(0, 0), entitySize, 10);
    auto& walkRightAnimation = animator.createAnimation(Textures::PLAYER_WALK_RIGHT, sf::seconds(1), true);
    walkRightAnimation.addFrames(sf::Vector2i(0, 0), entitySize, 10);
}

Entity::~Entity()
{ }

void Entity::update(const sf::Time& timePerFrame)
{
    if (currentVelocity != sf::Vector2f(0, 0))
            animator.update(timePerFrame);

    move(timePerFrame);
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}

void Entity::move(const sf::Time& timePerFrame)
{
    if (movementDirection == Direction::UP)
    {
        changeAnimation(Textures::PLAYER_WALK_UP);
        currentVelocity.y = -movementSpeed * timePerFrame.asSeconds();
    }
    else if (movementDirection == Direction::DOWN)
    {
        changeAnimation(Textures::PLAYER_WALK_DOWN);
        currentVelocity.y =  movementSpeed * timePerFrame.asSeconds();
    }
    else
    {
        currentVelocity.y = 0;
    }
    if (movementDirection == Direction::LEFT)
    {
        changeAnimation(Textures::PLAYER_WALK_LEFT);
        currentVelocity.x = -movementSpeed * timePerFrame.asSeconds();
    }
    else if (movementDirection == Direction::RIGHT)
    {
        changeAnimation(Textures::PLAYER_WALK_RIGHT);
        currentVelocity.x =  movementSpeed * timePerFrame.asSeconds();
    }
    else
    {
        currentVelocity.x = 0;
    }

    sf::Vector2f newPosition { sprite.getPosition().x + currentVelocity.x,
                               sprite.getPosition().y + currentVelocity.y };
    sprite.setPosition(newPosition);
}

void Entity::changeAnimation(const std::string& animationName)
{
    if (animator.getCurrentAnimationName() != animationName)
        animator.switchAnimation(animationName);
}
