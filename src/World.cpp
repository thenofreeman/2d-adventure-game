#include "World.h"

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

    if (!map.load("res/img/map-death-mountain.png", sf::Vector2u(32, 32), level, 5, 5));
}

World::~World()
{

}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(map, states);
}
