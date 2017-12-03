#ifndef COORD_H
#define COORD_H


class Coord
{
public:
    Coord(int, int);
    Coord& operator=(const Coord& rhs);
    bool operator==(const Coord& rhs);
    int getX() const;
    int getY() const;
    void toLeft();
    void toRight();
    void toUp();
    void toDown();
private:
    int x, y;
};

#endif // COORD_H
