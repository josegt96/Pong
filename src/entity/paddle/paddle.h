#include "../../struc.h"
#include <list>

#ifndef PADDLE_H
#define PADDLE_H

class cPaddle
{
private:
    int size, x, y, originalX, originalY;
    ColorRGB color;

public:
    cPaddle(int posX, int posY);
    cPaddle(int posX, int posY, ColorRGB c);
    void Reset();
    int getX();
    int getY();
    void moveUp();
    void moveDown();
    int getSize();
    std::list<PointWithColor> getPixels();
};

#endif // PADDLE_H