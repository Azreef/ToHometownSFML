#include "MechanicManager.h"
#include <iostream>

//CONSTRUCTOR
MechanicManager::MechanicManager()
{
	this->initVariable();
}


//FUNCTION 

//Update ==============================================================================
void MechanicManager::update()
{
}



//Draw   ==============================================================================



//Setter ==============================================================================
void MechanicManager::initVariable()
{
	this->score = 0;
	this->lives = 5;
}
void MechanicManager::removeLive()
{
	this->lives= this->lives - 1;
	//std::cout << lives << std::endl;
}
void MechanicManager::setCurrentDistance(int distance)
{
	this->currentDistance = distance;
	std::cout << currentDistance << std::endl;
}


//Getter ==============================================================================

