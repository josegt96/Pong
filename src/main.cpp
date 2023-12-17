#include <iostream>
#include <time.h>

#include "ball.h"
#include "paddle.h"

class cGameManger
{
private:
	int width, height;
	int score1, score2;
	char up1, down1, up2, down2;
	bool quit;
	cBall *ball;
	cPaddle *player1;
	cPaddle *player2;

public:
	cGameManger(int w, int h)
	{
		quit = false;
		up1 = 'w';
		up2 = 'i';
		down1 = 's';
		down2 = 'k';
		score1 = score2 = 0;
		width = w;
		height = h;
		ball = new cBall(w / 2, h / 2);
		player1 = new cPaddle(1, h / 2 - 3);
		player2 = new cPaddle(w - 2, h / 2 - 3);
	}
	~cGameManger()
	{
		delete ball, player1, player2;
	}
	void scoreUp(cPaddle *player)
	{
		if (player == player1)
			score1++;
		else if (player == player2)
			score2++;
		ball->Reset();
		player1->Reset();
		player2->Reset();
	}
	void Draw()
	{
	}
	void Input()
	{
	}
	void Logic()
	{
		int ballx = ball->getX();
		int bally = ball->getY();
		int player1x = player1->getX();
		int player2x = player2->getX();
		int player1y = player1->getY();
		int player2y = player2->getY();
		// Left Paddle
		for (int i = 0; i < 4; i++)
			if (ballx == player1x + 1)
				if (bally == player1y + i)
					ball->changeDirection((eDir)((rand() % 3) + 4));
		// Right Paddle
		for (int i = 0; i < 4; i++)
			if (ballx == player2x - 1)
				if (bally == player2y + i)
					ball->changeDirection((eDir)((rand() % 3) + 1));
		// Bottom Wall
		if (bally == height - 1)
			ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
		// top Wall
		if (bally == 0)
			ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
		// Right Wall
		if (ballx == width - 1)
			scoreUp(player1);
		// Left Wall
		if (ballx == 0)
			scoreUp(player2);
	}
	void Run()
	{
		while (!quit)
		{
			Draw();
			Input();
			Logic();
		}
	}
};
int main()
{
	cGameManger c(40, 20);
	c.Run();
	return 0;
}