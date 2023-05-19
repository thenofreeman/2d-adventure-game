#pragma once

#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable
{
    public:
        bool load(const std::string& tileSet, const sf::Vector2u& tileSize,
                  const int* tiles, const unsigned int& width, const unsigned int& height);

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        sf::VertexArray vertices;
        sf::Texture tileSet;
};
