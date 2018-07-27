#include <iostream>

#include "Player.h"

int main()
{
    Player player("Nagy Béla");


    while(player.getCoord().x<100)
    {
        player.setCoord(player.getCoord().x+1,player.getCoord().y+1);
        std::cout << "Name: " << player.getName() << "\n"
        << "Coord: (" << player.getCoord().x << ", " << player.getCoord().y << ")\n";
        getchar();
    }

    return 0;
}