#ifndef PADDLE_H
#define PADDLE_H

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
};

#endif // PADDLE_H