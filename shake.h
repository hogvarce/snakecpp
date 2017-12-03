#ifndef SHAKE_H
#define SHAKE_H
#include <coord.h>

class Shake
{
public:
    Shake();
    Shake(int, int);
    void Draw();
    int getWidth();
    int getHeight();
    bool gameOver();
    void setRabbitCoord();
    void setSnakeCoord();
    void Setup();
    void Input();
    void Logic();
private:
    int width, height;
    enum Directions{ STOP = 0, LEFT, RIGHT, UP, DOWN };
    bool endGame;
    const char border = '#';
    const char rabbit = '@';
    const char snake = 'S';
    Coord* rabbitCoord;
    Coord* snakeCoord;
    Directions dir = STOP;
    int score;
};

#endif // SHAKE_H
