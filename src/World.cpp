#include "World.h"

#include "Textures.h"

World::World()
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

    if (!map.load(IMG_PATH + Textures::WORLD_TILE_MAP + IMG_EXT, sf::Vector2u(32, 32), level, 5, 5));
}

World::~World()
{

}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(map, states);
}
