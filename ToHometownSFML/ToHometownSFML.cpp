#include <SFML/Graphics.hpp>
#include "GameManager.h"
int main()
{
    GameManager game;
    game.setData();

    while (game.running())
    {
        game.update();
        
        game.render();
    }

    return 0;
}