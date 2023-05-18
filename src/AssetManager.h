#pragma once

#include <SFML/Graphics.hpp>
#include <map>

class AssetManager
{
    public:
        AssetManager();

        static sf::Texture& getTexture(const std::string& filename);

    private:
        std::map<std::string, sf::Texture> textures;

        static AssetManager* Instance;
};
