#include "ResourceManager.h"

std::shared_ptr<sf::Texture> ResourceManager::getTexture(const std::string& path)
{
    if (textures.count(path) > 0) 
    {
        return textures[path];
    }
    else 
    {
        std::shared_ptr<sf::Texture> tex(new sf::Texture());
        if (!tex->loadFromFile(path)) {
            throw std::runtime_error("Can't load texture: " + path);
        }
        textures[path] = tex;
        return tex;
    }
}


std::shared_ptr<sf::SoundBuffer> ResourceManager::getSound(const std::string& path)
{
    if (sound.count(path) > 0)
    {
        return sound[path];
    }
    else
    {
        std::shared_ptr<sf::SoundBuffer> so(new sf::SoundBuffer());
        if (!so->loadFromFile(path)) {
            throw std::runtime_error("Can't load Sound: " + path);
        }
        sound[path] = so;
        return so;
    }
}
