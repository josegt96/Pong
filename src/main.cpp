#include <iostream>
#include <SDL2/SDL.h>

#include "ball.h"
#include "paddle.h"

class cGameManger
{
private:
	int width, height, multiplier;
	int score1, score2;
	char up1, down1, up2, down2;
	bool quit;
	cBall *ball;
	cPaddle *player1;
	cPaddle *player2;
	SDL_Window *window;
	SDL_Renderer *renderer;

public:
	cGameManger(int w, int h)
	{
		quit = false;
		up1 = 'w';
		up2 = 'i';
		down1 = 's';
		down2 = 'k';
		score1 = score2 = 0;
		multiplier = 20;
		width = w * multiplier;
		height = h * multiplier;
		ball = new cBall(width / 2, height / 2);
		player1 = new cPaddle(1, height / 2 - 3);
		player2 = new cPaddle(width - multiplier, height / 2 - multiplier / 2);

		// Initialize SDL
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
			quit = true;
			return;
		}

		// Create window and renderer
		window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

		if (!window || !renderer)
		{
			std::cerr << "Window or renderer creation failed: " << SDL_GetError() << std::endl;
			quit = true;
		}
	}

	~cGameManger()
	{
		delete ball, player1, player2;

		// Clean up SDL
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
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
		// Clear the renderer
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		// Draw paddles and ball
		player1->Draw(renderer);
		player2->Draw(renderer);
		ball->Draw(renderer);

		// Present the renderer
		SDL_RenderPresent(renderer);
	}

	void Input()
	{
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_w:
					if (player1->getY() > 0)
						player1->moveUp();
					break;
				case SDLK_i:
					if (player2->getY() > 0)
						player2->moveUp();
					break;
				case SDLK_s:
					if (player1->getY() + 4 < height)
						player1->moveDown();
					break;
				case SDLK_k:
					if (player2->getY() + 4 < height)
						player2->moveDown();
					break;
				case SDLK_q:
					quit = true;
					break;
				}
			}
		}
	}

	void Logic()
	{
		ball->Move();

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
