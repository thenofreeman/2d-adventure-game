#include "World.h"

#include "Textures.h"
#include "Player.h"

#include "Map.h"

World::World(sf::RenderWindow& window)
    : window{window},
      view{window.getDefaultView()},
      bounds{0.f, 0.f, view.getSize().x, 100.f},
      player{nullptr}
{
    buildScene();
    loadTextures();

    view.setCenter(sf::Vector2f(50.f, 50.f));
}

void World::loadTextures()
{
    if (!map->load(IMG_PATH + Textures::WORLD_TILE_MAP + IMG_EXT, sf::Vector2u(16, 16), mapData, 20, 20));
}

void World::buildScene()
{
    for (std::size_t i = 0; i < LayerCount; ++i)
    {
        SceneNode::NodePtr layer(new SceneNode());
        sceneLayers[i] = layer.get();

        sceneGraph.attachChild(std::move(layer));
    }

    std::unique_ptr<TileMap> background(new TileMap());
    map = background.get();
    background->setPosition(bounds.left, bounds.top);
    sceneLayers[Background]->attachChild(std::move(background));

    std::unique_ptr<Entity> p(new Player());
    player = p.get();
    player->setPosition(sf::Vector2f(50.f, 50.f));
    sceneLayers[Foreground]->attachChild(std::move(p));

}

World::~World()
{

}

void World::update(const sf::Time& deltaTime)
{

    view.setCenter(player->getPosition());

    sceneGraph.update(deltaTime);
}

void World::draw()
{
    window.setView(view);
    window.draw(sceneGraph);
}
