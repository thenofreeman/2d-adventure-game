#include <iostream>

#include <SFML/Graphics.hpp>

#include "AssetManager.h"
#include "Entity.h"

constexpr char GAME_TITLE[] { "Adventure Game" };
constexpr int GAME_FPS {100};

void handleInput(sf::RenderWindow& window, Entity& player);
void updateFrame(sf::RenderWindow& window);
void drawFrame(sf::RenderWindow& window, Entity& player, sf::RectangleShape& bgRect);

int main()
{
    sf::Uint32 win_style = sf::Style::Titlebar | sf::Style::Close;
    sf::RenderWindow window(sf::VideoMode(300, 200), GAME_TITLE, win_style);

    AssetManager assetManager;

    window.setMouseCursorVisible(false);
    window.setFramerateLimit(GAME_FPS);

    Entity player(window);

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

        // TODO make it so it doesn't need params (unlike this)
        drawFrame(window, player, bgRect);

        window.display();
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

}

void drawFrame(sf::RenderWindow& window, Entity& player, sf::RectangleShape& bgRect)
{
    window.clear(sf::Color::Black);

    window.draw(bgRect);
    //window.draw(player); // implement via inheritence of "drawable"
    window.draw(player);

}
