// ball.h

#ifndef BALL_H
#define BALL_H

#include <SDL2/SDL_render.h>

enum eDir
{
    STOP = 0,
    LEFT = 1,
    UPLEFT = 2,
    DOWNLEFT = 3,
    RIGHT = 4,
    UPRIGHT = 5,
    DOWNRIGHT = 6
};

class cBall
{
private:
    int x, y;
    int originalX, originalY;
    eDir direction;

public:
    cBall(int posX, int posY);

    void Reset();

    void changeDirection(eDir d);

    void randomDirection();

    int getX();

    int getY();

    eDir getDirection();

    void Move();

    void Draw(SDL_Renderer *renderer);
};

#endif // BALL_H
