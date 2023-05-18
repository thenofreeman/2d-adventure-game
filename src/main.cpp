#include <iostream>

#include <SFML/Graphics.hpp>

#include "AssetManager.h"
#include "Animator.h"
#include "Entity.h"

constexpr char GAME_TITLE[] { "Adventure Game" };
constexpr int GAME_FPS {100};

void handleInput(sf::RenderWindow& window, Animator& animator, bool& moving);
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

    sf::Vector2i spriteSize(32, 32);
    sf::Sprite sprite;
    sprite.setTextureRect(sf::IntRect(0, 0, spriteSize.x, spriteSize.y));

    Animator animator(sprite);
    auto& walkUpAnimation = animator.createAnimation("player-walk-up", "res/img/player-walk-up.png",
                                                   sf::seconds(1), true);
    walkUpAnimation.addFrames(sf::Vector2i(0, 0), spriteSize, 10);
    auto& walkDownAnimation = animator.createAnimation("player-walk-down", "res/img/player-walk-down.png",
                                                   sf::seconds(1), true);
    walkDownAnimation.addFrames(sf::Vector2i(0, 0), spriteSize, 10);
    auto& walkLeftAnimation = animator.createAnimation("player-walk-side", "res/img/player-walk-side.png",
                                                   sf::seconds(1), true);
    walkLeftAnimation.addFrames(sf::Vector2i(0, 0), spriteSize, 10);
    auto& walkRightAnimation = animator.createAnimation("player-walk-side", "res/img/player-walk-side.png",
                                                   sf::seconds(1), true);
    walkRightAnimation.addFrames(sf::Vector2i(0, 0), spriteSize, 10);

    sprite.setPosition(sf::Vector2f(50, 50));

    int numFrames = 10;
    float animationDuration = 1.0f;

    sf::Clock clock;

    sf::Time elapsedTime = clock.restart();
    sf::Time deltaTime;

    bool moving = false;

    // Game Loop
    while (window.isOpen())
    {
        deltaTime = clock.restart();


        elapsedTime += deltaTime;
        float timeAsSeconds = elapsedTime.asSeconds();

        handleInput(window, animator, moving);
        if (moving)
        {
            animator.update(deltaTime);
        }
        updateFrame(window);

        // TODO make it so it doesn't need params (unlike this)
        drawFrame(window, player, bgRect);

        window.draw(sprite);

        window.display();
    }

    return 0;
}

void handleInput(sf::RenderWindow& window, Animator& animator, bool& moving)
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
        if (animator.getCurrentAnimationName() != "player-walk-up")
            animator.switchAnimation("player-walk-up");

        moving = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        if (animator.getCurrentAnimationName() != "player-walk-down")
            animator.switchAnimation("player-walk-down");

        moving = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        if (animator.getCurrentAnimationName() != "player-walk-side")
            animator.switchAnimation("player-walk-side");

        moving = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        if (animator.getCurrentAnimationName() != "player-walk-side")
            animator.switchAnimation("player-walk-side");

        moving = true;
    }
    else
    {
        moving = false;
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
    // player.draw();

}
