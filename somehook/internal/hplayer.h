#include <string>

struct Coord;

struct Player
{
    std::string getName() const;
    void setCoord(int, int);
};