#include "Player.h"

Coord &Coord::operator=(const Coord &b) 
{
    if (this==&b) return *this;

    this->x = b.x;
    this->y = b.y;

    return *this;
}

Player::Player(std::string _name)
{
    name = _name;
    coord.x=0;
    coord.y=0;
}

std::string Player::getName() const
{
    return name;
}

Coord Player::getCoord() const
{
    return coord;
}

void Player::setCoord(Coord &_coord)
{
    coord = _coord;
}

void Player::setCoord(int x, int y)
{
    coord.x = x;
    coord.y = y;
}