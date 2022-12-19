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