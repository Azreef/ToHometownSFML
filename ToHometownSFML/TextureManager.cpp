#include "TextureManager.h"

std::shared_ptr<sf::Texture> TextureManager::getTexture(const std::string& path)
{
    if (textures.count(path) > 0) {
        return textures[path];
    }
    else {
        std::shared_ptr<sf::Texture> tex(new sf::Texture());
        if (!tex->loadFromFile(path)) {
            throw std::runtime_error("Can't load texture: " + path);
        }
        textures[path] = tex;
        return tex;
    }
}
