#include "AssetManager.h"

#include <assert.h>
#include <iostream>

AssetManager* AssetManager::Instance = nullptr;

AssetManager::AssetManager()
{
    assert(Instance == nullptr);
    Instance = this;
}

sf::Texture& AssetManager::getTexture(const std::string& filename)
{
    auto& textureMap = Instance->textures;

    auto pairFound = textureMap.find(filename);

    if (pairFound != textureMap.end())
    {
        return pairFound->second;
    }
    else
    {
        auto& texture = textureMap[filename];
        texture.loadFromFile(filename);

        return texture;
    }
}
