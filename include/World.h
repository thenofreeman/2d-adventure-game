#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include "TileMap.h"
#include "Entity.h"

class World : public sf::NonCopyable //, public sf::Drawable
{
    public:
        explicit World(sf::RenderWindow& window);
        virtual ~World();

        void update(const sf::Time& deltaTime);
        void draw();


        // should be private!!
        Entity* player;
        // should be private!!

    private:
        enum Layer
        {
            Background=0,
            Foreground,
            Hud,

            LayerCount,
        };

        sf::RenderWindow& window;
        sf::View view;

        SceneNode sceneGraph;
        std::array<SceneNode*, LayerCount> sceneLayers;

        sf::FloatRect bounds;
        //Entity* player;

        void loadTextures();
        void buildScene();

        TileMap* map;
        int level[10000];

        enum Tiles
        {
            PATH_CORNER_TL=0, PATH_CENTER_TOP=1, PATH_CORNER_TR=2, PATH_END_TOP=4,

            PATH_SIDE_LEFT=10, PATH_CENTER=11, PATH_SIDE_RIGHT=12, PATH_VERT_CENTER=13,

            PATH_CORNER_BL=20, PATH_CENTER_BOTTOM=21, PATH_CORNER_BR=22, PATH_END_BOTTOM=23,

            PATH_END_LEFT=30, PATH_HORIZ_CENTER=31, PATH_END_RIGHT=32, GROUND=33,

            GROUND_SPOT_A=40, GROUND_SPOT_B=41,
        };

        // virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};
