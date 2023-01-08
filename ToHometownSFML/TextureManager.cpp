#include "TextureManager.h"

TextureManager::TextureManager()
{
	//setTexture();
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
			return carTexture;
		}
		else if (id == 1)
		{
			return busTexture;
		}
	}
	else if (type == 1)
	{
		if (id == 0)
		{
			return repairTexture;
		}
		else if (id == 1)
		{
			return fuelTexture;
		}
	}
}
