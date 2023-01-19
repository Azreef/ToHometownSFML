/*
    Project Name: To Hometown

    Programmer: Ahmad Zhoreef Bin Mohamed

    Credits: 
    Music by: Steven O'Brien
    https://www.steven-obrien.net/

    “Sound effects obtained from https://www.zapsplat.com“

*/


#include <SFML/Graphics.hpp>
#include "GameManager.h"
int main()
{
    GameManager game;
  
    while (game.running())
    {
        game.update();
        
        game.render();
    }

    return 0;
}