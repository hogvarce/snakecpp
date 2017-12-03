#include "shake.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <coord.h>

using std::cout;
using std::endl;

Shake::Shake()
{
    width = 10;
    height = 10;

}

Shake::Shake(int width, int height):
    width(width), height(height)
{

}

void Shake::Setup()
{
    endGame = false;
    setRabbitCoord();
    setSnakeCoord();
    score = 0;
}

void Shake::setRabbitCoord()
{
    delete rabbitCoord;
    rabbitCoord = new Coord(rand() % width, rand() % height);
}

void Shake::setSnakeCoord()
{
    delete snakeCoord;
    snakeCoord = new Coord(width / 2 - 1, height / 2 - 1);
}

int Shake::getWidth()
{
    return width;
}

int Shake::getHeight()
{
    return height;
}

bool Shake::gameOver()
{
    return endGame;
}

void Shake::Draw()
{
     system("cls");
     for (int i = 0; i < width; i++)
     {
         cout << border;
     }
     cout << endl;
     for (int i = 0; i < height; i++)
     {
         for (int j = 0; j < width; j++)
         {
             if (j == 0 || j == width - 1){
                 cout << border;
             } else if (j == rabbitCoord->getX() && i == rabbitCoord->getY()) {
                 cout << rabbit;
             } else if (j == snakeCoord->getX() && i == snakeCoord->getY()) {
                 cout << snake;
             } else {
                 cout << " ";
             }
         }
        cout << endl;
     }
     for (int i = 0; i < width; i++)
     {
         cout << border;
     }
     cout << endl;
     cout << "Score: " << score << endl;
}

void Shake::Input()
{
    if (_kbhit()) {
        switch(_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'q':
            endGame = true;
            break;
        }
    }
}

void Shake::Logic()
{
    switch(dir)
    {
    case LEFT:
        snakeCoord->toLeft();
        break;
    case RIGHT:
        snakeCoord->toRight();
        break;
    case UP:
        snakeCoord->toUp();
        break;
    case DOWN:
        snakeCoord->toDown();
        break;
    }
    if (rabbitCoord == snakeCoord) {
        setRabbitCoord();
        score += 10;
    }
}
