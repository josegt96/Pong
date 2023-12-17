// ball.h

#ifndef BALL_H
#define BALL_H

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

    int getX() const;

    int getY() const;

    eDir getDirection() const;

    void Move();
};

#endif // BALL_H
