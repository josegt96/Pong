#ifndef PADDLE_H
#define PADDLE_H

#include <SDL2/SDL_render.h>

class cPaddle
{
private:
    int x, y;
    int originalX, originalY;

public:
    cPaddle();
    cPaddle(int posX, int posY);
    void Reset();
    int getX();
    int getY();
    void moveUp();
    void moveDown();
    void Draw(SDL_Renderer *renderer);
};

#endif // PADDLE_H