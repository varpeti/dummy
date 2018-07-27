#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

struct Coord
{
    int x;
    int y;

    Coord &operator=(const Coord &);
};

class Player
{
    public:
        Player(std::string);

        std::string getName() const;
        Coord getCoord() const;

        void setCoord(Coord &);
        void setCoord(int, int);

    private:
        std::string name;
        Coord coord;
};

#endif