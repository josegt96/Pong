// paddle.cpp

#include "paddle.h"

cPaddle::cPaddle()
{
    x = y = 0;
}

cPaddle::cPaddle(int posX, int posY) : cPaddle()
{
    originalX = posX;
    originalY = posY;
    x = posX;
    y = posY;
}

void cPaddle::Draw(SDL_Renderer *renderer)
{
    // Set the drawing color to white
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);

    // Draw the paddle using SDL_RenderDrawRect
    SDL_Rect rect = {x, y, 20, 100};
    SDL_RenderDrawRect(renderer, &rect);
}

void cPaddle::Reset()
{
    x = originalX;
    y = originalY;
}

int cPaddle::getX()
{
    return x;
}

int cPaddle::getY()
{
    return y;
}

void cPaddle::moveUp()
{
    y--;
}

void cPaddle::moveDown()
{
    y++;
}
