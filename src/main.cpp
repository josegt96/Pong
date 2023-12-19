#include <iostream>
#include <SDL2/SDL.h>
#include <chrono>
#include <thread>
#include <list>

#include "entity/pong/pong.h"

class cGameManger
{
private:
	int multiplier;
	char up1, down1, up2, down2;
	bool quit;
	cPong *pongGame;
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
		multiplier = 20;

		pongGame = new cPong(w, h);

		// Initialize SDL
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
			quit = true;
			return;
		}

		// Create window and renderer
		window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w * multiplier, h * multiplier + multiplier, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

		if (!window || !renderer)
		{
			std::cerr << "Window or renderer creation failed: " << SDL_GetError() << std::endl;
			quit = true;
		}
	}

	~cGameManger()
	{
		// Clean up SDL
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	void Draw()
	{
		std::list<PointWithColor> pixels = pongGame->getPixels();

		// Clear the renderer
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		for (const auto &pixel : pixels)
		{
			// Set the drawing color to white
			SDL_SetRenderDrawColor(renderer,
								   pixel.color.red,
								   pixel.color.green,
								   pixel.color.blue,
								   255);
			// Draw the paddle using SDL_RenderDrawRect
			SDL_Rect rect = {pixel.point.x * multiplier,
							 pixel.point.y * multiplier,
							 multiplier,
							 multiplier};
			// Set the drawing color to white

			SDL_RenderDrawRect(renderer, &rect);
		}

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
					pongGame->movePlayer(0, 1);
					break;
				case SDLK_s:
					pongGame->movePlayer(0, 0);
					break;
				case SDLK_i:
					pongGame->movePlayer(1, 1);
					break;
				case SDLK_k:
					pongGame->movePlayer(1, 0);
					break;
				case SDLK_q:
					quit = true;
					break;
				}
			}
		}
	}

	void Run()
	{
		while (!quit)
		{
			Draw();
			Input();
			pongGame->nextTick();
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}
	}
};

int main()
{
	cGameManger c(40, 20);
	c.Run();
	return 0;
}
