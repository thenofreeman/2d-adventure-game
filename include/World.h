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

        // virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};
