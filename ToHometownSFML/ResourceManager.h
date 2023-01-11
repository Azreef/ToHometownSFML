#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <SFML/Audio.hpp>


class ResourceManager
{

private:
	std::map<std::string, std::shared_ptr<sf::Texture>> textures;
	std::map<std::string, std::shared_ptr<sf::SoundBuffer>> sound;

public:
	ResourceManager() {}
	~ResourceManager() {}

	std::shared_ptr<sf::SoundBuffer> getSound(const std::string& path);
	std::shared_ptr<sf::Texture> getTexture(const std::string& path);

};

