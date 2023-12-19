#include "pong.h"

cPong::cPong(int w, int h)
{
    width = w;
    height = h;
    score1 = score2 = 0;
    ball = new cBall(w / 2, h / 2);
    player1 = new cPaddle(1, h / 2 - 1);
    player2 = new cPaddle(w - 1, h / 2 - 1);
}

void cPong::reset()
{
    ball->Reset();
    player1->Reset();
    player2->Reset();
}

void cPong::scoreUp(cPaddle *player)
{
    if (player == player1)
        score1++;
    else if (player == player2)
        score2++;
    reset();
}

void cPong::nextTick()
{
    ball->Move();

    int ballx = ball->getX();
    int bally = ball->getY();
    int player1x = player1->getX();
    int player2x = player2->getX();
    int player1y = player1->getY();
    int player2y = player2->getY();

    int size1 = player1->getSize();
    int size2 = player2->getSize();
    // Left Paddle
    for (int i = 0; i < size1; i++)
        if (ballx == player1x + 1 && bally == player1y + i)
            ball->changeDirection((eDir)((rand() % 3) + 4));

    // Right Paddle
    for (int i = 0; i < size2; i++)
        if (ballx == player2x - 1 && bally == player2y + i)
            ball->changeDirection((eDir)((rand() % 3) + 1));

    // Bottom Wall
    if (bally == height - 1)
        ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);

    // Top Wall
    if (bally == 0)
        ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);

    // Right Wall
    if (ballx == width - 1)
        scoreUp(player1);

    // Left Wall
    if (ballx == 0)
        scoreUp(player2);
}

std::list<PointWithColor> cPong::getPixels()
{
    std::list<PointWithColor> pixels;

    pixels.splice(pixels.end(), ball->getPixels());
    pixels.splice(pixels.end(), player1->getPixels());
    pixels.splice(pixels.end(), player2->getPixels());

    return pixels;
}

void cPong::movePlayer(int player, int direction)
{
    if (player == 0)
    {
        if (direction == 0)
            player1->moveDown();
        else if (direction == 1)
            player1->moveUp();
    }
    else if (player == 1)
    {
        if (direction == 0)
            player2->moveDown();
        else if (direction == 1)
            player2->moveUp();
    }
}