#pragma once

#include <map>

#include <SFML/Graphics.hpp>

class AssetManager
{
    public:
        AssetManager();

        static sf::Texture& getTexture(const std::string& filename);

    private:
        std::map<std::string, sf::Texture> textures;

        static AssetManager* Instance;
};
