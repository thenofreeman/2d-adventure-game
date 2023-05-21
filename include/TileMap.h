#pragma once

#include <SFML/Graphics.hpp>

#include "SceneNode.h"

class TileMap : public SceneNode
{
    public:
        bool load(const std::string& tileSet,
                  const sf::Vector2u& tileSize,
                  const int* tiles,
                  const unsigned int& width,
                  const unsigned int& height);

    private:
        virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

        sf::VertexArray vertices;
        sf::Texture tileSet;
};
