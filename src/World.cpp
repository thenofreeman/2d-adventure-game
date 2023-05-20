#include "World.h"

#include "Textures.h"

World::World()
{
    for (int& tile : level)
    {
        tile = 33;
    }

    if (!map.load(IMG_PATH + Textures::WORLD_TILE_MAP + IMG_EXT, sf::Vector2u(16, 16), level, 100, 100));
}

World::~World()
{

}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(map, states);
}
