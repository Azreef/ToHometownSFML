#include "TextureManager.h"

TextureManager::TextureManager()
{
	//setTexture();
	//Set Entity Texture

	//Enemy
	//Car

	
	/*if (!carTexture->loadFromFile("Asset/car2.png"))
	{
		std::cout << "ERROR TEXTURE";
	}*/



	//Bus
	/*sf::Texture* busTexture;
	busTexture = new sf::Texture;

	busTexture->loadFromFile("Asset/bus.png");*/
	/*if (!busTexture->loadFromFile("Asset/bus.png"))
	{
		std::cout << "ERROR TEXTURE";
	}*/


	//Pickup
	//Repair
	//if (!repairTexture->loadFromFile("Asset/repairKit.png"))
	//{
	//	std::cout << "ERROR TEXTURE";
	//}

	////Fuel
	//if (!fuelTexture->loadFromFile("Asset/fuel.png"))
	//{
	//	std::cout << "ERROR TEXTURE";
	//}
}

TextureManager::~TextureManager()
{
	delete carTexture;
}

void TextureManager::setTexture()
{
	std::cout << "LALU";
	//Set Entity Texture

	//Enemy
	//Car
	if (!carTexture->loadFromFile("Asset/car2.png"))
	{
		std::cout << "ERROR TEXTURE";
	}

	
	//Bus
	if (!busTexture->loadFromFile("Asset/bus.png"))
	{
		std::cout << "ERROR TEXTURE";
	}


	//Pickup
	//Repair
	if (!repairTexture->loadFromFile("Asset/repairKit.png"))
	{
		std::cout << "ERROR TEXTURE";
	}

	//Fuel
	if (!fuelTexture->loadFromFile("Asset/fuel.png"))
	{
		std::cout << "ERROR TEXTURE";
	}
}

sf::Texture* TextureManager::getTexture(int type, int id)
{
	if (type == 0)
	{
		if (id == 0)
		{
			sf::Texture* texture;
			texture = new sf::Texture;

			std::shared_ptr<sf::Texture> texture(new sf::Texture());

			texture->loadFromFile("Asset/car2.png");
			std::cout << "loadCar" << std::endl;
			return texture;
		}
		else if (id == 1)
		{
			sf::Texture* texture;
			texture = new sf::Texture;

			texture->loadFromFile("Asset/bus.png");
			std::cout << "loadbus" << std::endl;
			//return texture;
		}
	}
	else if (type == 1)
	{
		if (id == 0)
		{
			sf::Texture* texture;
			texture = new sf::Texture;

			texture->loadFromFile("Asset/repairKit.png");
			std::cout << "loadCar" << std::endl;
			//return texture;
		}
		else if (id == 1)
		{
			sf::Texture* texture;
			texture = new sf::Texture;

			texture->loadFromFile("Asset/fuel.png");
			std::cout << "loadCar" << std::endl;
			//return texture;
		}
	}
}
