#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include "TileMap.h"

class World : public sf::Drawable
{
    public:
        World();
        virtual ~World();

    private:
        TileMap map;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};
