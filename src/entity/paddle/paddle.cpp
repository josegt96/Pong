// paddle.cpp

#include "paddle.h"

cPaddle::cPaddle(int posX, int posY)
{
    originalX = posX;
    originalY = posY;
    x = posX;
    y = posY;
    size = 4;
    color = {255, 0, 255};
}

std::list<PointWithColor> cPaddle::getPixels()
{
    std::list<PointWithColor> pixels;

    // Draw the paddle using SDL_RenderDrawRect
    for (int i = 0; i < size; i++)
    {
        pixels.push_back({{x, y + i}, color});
    }

    return pixels;
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

int cPaddle::getSize()
{
    return size;
}