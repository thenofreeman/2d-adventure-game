#include "Player.h"

#include "Textures.h"

Player::Player()
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

Player::~Player()
{ }
