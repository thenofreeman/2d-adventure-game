#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "AssetManager.h"
#include "Game.h"

int main()
{
    AssetManager assetManager;

    // std::vector<Entity> entities;
    // entities.push_back(Entity(window));

    // sf::Image bgImage;
    // bgImage.loadFromFile("res/img/map-death-mountain.png");

    // sf::Texture bgTexture;
    // bgTexture.loadFromImage(bgImage, sf::IntRect(1461, 534, 32, 32));

    // bgTexture.setRepeated(true);
    // bgTexture.setSmooth(true); // not recommended if "pixel perfect"

    // sf::RectangleShape bgRect(sf::Vector2f(32*10, 32*6));
    // bgRect.setTextureRect(sf::IntRect(0, 0, 32*10, 32*6));
    // bgRect.setTexture(&bgTexture);

    Game game("Adventure Game");
    game.run();

}
