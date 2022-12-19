#include "MechanicManager.h"
#include <iostream>

//CONSTRUCTOR
MechanicManager::MechanicManager()
{
	this->initVariable();
}


//FUNCTION 

//Update ==============================================================================

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
	std::cout << lives << std::endl;
}
//Getter ==============================================================================

