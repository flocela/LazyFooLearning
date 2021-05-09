#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init();
bool loadMedia();
void close();
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;

bool init()
{
	bool success = true;
	if ( SDL_Init( SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		gScreenSurface = SDL_GetWindowSurface (gWindow);
	}
	return success;
}

bool loadMedia()
{
	bool success = true;
	gHelloWorld = SDL_LoadBMP("./hello_world.bmp");
	if(gHelloWorld == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n",
				"hello_world.bmp", SDL_GetError());
		success =false;
	}
	return success;
}

void close()
{
	SDL_FreeSurface( gHelloWorld);
	gHelloWorld = NULL;
	SDL_DestroyWindow( gWindow);
	gWindow = NULL;
	SDL_Quit;
}

int main(int argc, char* args[]) {
	if(!init())
	{
		printf("Failed to initialize\n");
	}
	else
	{
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
			SDL_UpdateWindowSurface(gWindow);
			SDL_Delay(2000);
		}
		close();
		return 0;
	}
	

	
  
  /*
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n"; */

  return 0;
}