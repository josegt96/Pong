// ball.h
#include "../../struc.h"
#include <list>
#include <stdlib.h>

#ifndef BALL_H
#define BALL_H

class cBall
{
private:
    int x, y, originalX, originalY;
    eDir direction;
    ColorRGB color;

public:
    cBall(int posX, int posY);

    void Reset();

    void changeDirection(eDir d);

    void randomDirection();

    int getX();

    int getY();

    eDir getDirection();

    void Move();

    std::list<PointWithColor> getPixels();
};

#endif // BALL_H
