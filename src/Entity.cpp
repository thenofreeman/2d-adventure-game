#include "Entity.h"

#include "Sprites.h"

Entity::Entity(sf::RenderWindow& window)
    : window{window},
      texture{sf::Texture()},
      pos{sf::Vector2f(50, 50)}
{
    shape.setPosition(pos);
    shape.setOrigin(shape.getSize() * 0.5f);

    // -- SHOULD BE GLOBAL
    sf::Image PLAYER;
    PLAYER.loadFromFile(Images::PLAYER_PATH);
    const int SCALE = 2;
    // -- END

    texture.loadFromImage(PLAYER, sf::IntRect(5, 781, 18, 21));
    sf::Vector2u textureSize = texture.getSize();

    sprite.setTexture(texture);
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

void Entity::update()
{

}
