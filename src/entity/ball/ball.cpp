// ball.cpp

#include "ball.h"

cBall::cBall(int posX, int posY)
    : originalX(posX), originalY(posY), x(posX), y(posY), direction(RIGHT)
{
}

void cBall::Reset()
{
    x = originalX;
    y = originalY;
    direction = RIGHT;
}

void cBall::Draw(SDL_Renderer *renderer)
{
    // Set the drawing color to white
    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
    // Draw the paddle using SDL_RenderDrawRect
    SDL_Rect rect = {x * 20, y * 20, 20, 20};
    SDL_RenderDrawRect(renderer, &rect);
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
