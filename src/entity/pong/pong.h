#ifndef PONG_H
#define PONG_H

#include "../ball/ball.h"
#include "../paddle/paddle.h"
#include "../../struc.h"

class cPong
{
private:
    int width, height, score1, score2;
    cBall *ball;
    cPaddle *player1, *player2;
    void scoreUp(cPaddle *player);
    void reset();

public:
    cPong(int width, int height);
    void nextTick();
    void movePlayer(int player, int direction);
    std::list<PointWithColor> getPixels();
};

#endif // PONG_H