#include "coord.h"

Coord::Coord(int X, int Y):
    x(X), y(Y)
{

}

int Coord::getX() const
{
    return x;
}

int Coord::getY() const
{
    return y;
}

void Coord::toLeft()
{
    x--;
}
void Coord::toRight()
{
    x++;
}
void Coord::toUp()
{
    y--;
}
void Coord::toDown()
{
    y++;
}

Coord& Coord::operator=(const Coord& rhs)
{
    x = rhs.x;
    y = rhs.y;
    return *this;
}

bool Coord::operator==(const Coord& rhs)
{
    return (x == rhs.getX()) && (y == rhs.getY());
}
