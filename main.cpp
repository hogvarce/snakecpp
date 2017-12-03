#include <shake.h>

int main()
{
    Shake snake(40, 20);
    snake.Setup();
    while(!snake.gameOver()) {
        snake.Draw();
        snake.Input();
        snake.Logic();
    }
    return 0;
}
