#include "TileMap.h"

bool TileMap::load(const std::string& tileSet, const sf::Vector2u& tileSize,
                   const int* tiles, const unsigned int& width, const unsigned int& height)
{
    if (!this->tileSet.loadFromFile(tileSet))
        return false;

    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(width*height*4);

    for (unsigned int i = 0; i < width; ++i)
    {
        for (unsigned int j = 0; j < height; ++j)
        {
            int tileNumber = tiles[i + j * width];

            int tu = tileNumber % (this->tileSet.getSize().x / tileSize.x);
            int tv = tileNumber / (this->tileSet.getSize().x / tileSize.x);

            sf::Vertex* quad = &vertices[(i + j * width) * 4];

            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }
    }

    return true;
}

void TileMap::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &tileSet;
    target.draw(vertices, states);
}
