#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "AssetManager.h"
#include "Entity.h"
#include "TileMap.h"

constexpr char GAME_TITLE[] { "Adventure Game" };
constexpr int GAME_FPS {100};

void handleInput(sf::RenderWindow& window, Entity& player);
void updateFrame(sf::RenderWindow& window);
void drawFrame(sf::RenderWindow& window, Entity& player, sf::RectangleShape& bgRect);

enum Tile
{
    GRASS=0, DIRT,

};


int main()
{
    sf::Uint32 win_style = sf::Style::Titlebar | sf::Style::Close;
    sf::RenderWindow window(sf::VideoMode(900, 600), GAME_TITLE, win_style);

    AssetManager assetManager;

    window.setMouseCursorVisible(false);
    window.setFramerateLimit(GAME_FPS);

    // std::vector<Entity> entities;
    // entities.push_back(Entity(window));

    Entity player(window);

    const int level[] {
        GRASS, GRASS, DIRT, GRASS, GRASS,
        GRASS, GRASS, DIRT, GRASS, GRASS,
        GRASS, GRASS, DIRT, GRASS, GRASS,
        GRASS, GRASS, DIRT, GRASS, GRASS,
        GRASS, GRASS, DIRT, GRASS, GRASS
    };

    TileMap map;
    if (!map.load("res/img/map-death-mountain.png", sf::Vector2u(32, 32), level, 5, 5));

    // background
    sf::Image bgImage;
    bgImage.loadFromFile("res/img/map-death-mountain.png");

    sf::Texture bgTexture;
    bgTexture.loadFromImage(bgImage, sf::IntRect(1461, 534, 32, 32));

    bgTexture.setRepeated(true);
    bgTexture.setSmooth(true); // not recommended if "pixel perfect"

    sf::RectangleShape bgRect(sf::Vector2f(32*10, 32*6));
    bgRect.setTextureRect(sf::IntRect(0, 0, 32*10, 32*6));
    bgRect.setTexture(&bgTexture);

    auto windowSize = window.getSize();
    sf::View view(sf::FloatRect(0, 0, windowSize.x, windowSize.y));

    view.setCenter(player.getPosition());
    window.setView(view);

    int numFrames = 10;
    float animationDuration = 1.0f;

    sf::Clock clock;

    sf::Time elapsedTime = clock.restart();
    sf::Time deltaTime;

    // Game Loop
    while (window.isOpen())
    {
        deltaTime = clock.restart();

        elapsedTime += deltaTime;
        float timeAsSeconds = elapsedTime.asSeconds();

        handleInput(window, player);

        player.update(deltaTime);

        updateFrame(window);

        window.draw(map);
        drawFrame(window, player, bgRect);
    }

    return 0;
}

void handleInput(sf::RenderWindow& window, Entity& player)
{
    sf::Event e;
    while (window.pollEvent(e))
    {
        switch (e.type)
        {
            case sf::Event::EventType::Closed:
                window.close();
                break;
            default:
                break;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        player.moveUp();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        player.moveDown();
    }
    else
    {
        player.stopMovingVertical();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        player.moveLeft();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        player.moveRight();
    }
    else
    {
        player.stopMovingHorizontal();
    }

}

void updateFrame(sf::RenderWindow& window)
{
    window.clear(sf::Color::Black);
}

void drawFrame(sf::RenderWindow& window, Entity& player, sf::RectangleShape& bgRect)
{

    // window.draw(bgRect);
    window.draw(player);

    window.display();
}
