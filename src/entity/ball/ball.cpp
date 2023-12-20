// ball.cpp

#include "ball.h"

cBall::cBall(int posX, int posY)
{
    x = posX;
    y = posY;
    originalX = posX;
    originalY = posY;
    direction = RIGHT;
    color = {0, 255, 255};
}

void cBall::Reset()
{
    x = originalX;
    y = originalY;
    direction = RIGHT;
}

std::list<PointWithColor> cBall::getPixels()
{
    return {{{x, y}, color}};
}

void cBall::changeDirection(eDir d)
{
    direction = d;
}

void cBall::randomDirection()
{
    direction = static_cast<eDir>((rand() % 6) + 1);
}

int cBall::getX()
{
    return x;
}

int cBall::getY()
{
    return y;
}

eDir cBall::getDirection()
{
    return direction;
}

void cBall::Move()
{
    switch (direction)
    {
    case STOP:
        break;
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UPLEFT:
        x--;
        y--;
        break;
    case DOWNLEFT:
        x--;
        y++;
        break;
    case UPRIGHT:
        x++;
        y--;
        break;
    case DOWNRIGHT:
        x++;
        y++;
        break;
    default:
        break;
    }
}
