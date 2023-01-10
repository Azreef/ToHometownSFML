#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>
#include <map>
#include <memory>
#include <string>
class TextureManager
{


private:
	std::map<std::string, std::shared_ptr<sf::Texture>> textures;


public:
	TextureManager() {}
	~TextureManager() {}

	std::shared_ptr<sf::Texture> getTexture(const std::string& path);
    
};

