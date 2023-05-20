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
        int level[10000];

        enum Tiles
        {
            PATH_CORNER_TL=0, PATH_CENTER_TOP=1, PATH_CORNER_TR=2, PATH_END_TOP=4,

            PATH_SIDE_LEFT=10, PATH_CENTER=11, PATH_SIDE_RIGHT=12, PATH_VERT_CENTER=13,

            PATH_CORNER_BL=20, PATH_CENTER_BOTTOM=21, PATH_CORNER_BR=22, PATH_END_BOTTOM=23,

            PATH_END_LEFT=30, PATH_HORIZ_CENTER=31, PATH_END_RIGHT=32, GROUND=33,

            GROUND_SPOT_A=40, GROUND_SPOT_B=41,
        };

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};
