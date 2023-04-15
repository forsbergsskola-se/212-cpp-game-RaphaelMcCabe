#include "Window.h"
#include <cstdio>
#include <SDL.h>

Window::Window(int width, int height) : success{}
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return;
	}
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		if (!window)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			return;
		}

		//Get window surface
		screenSurface = SDL_GetWindowSurface(window);
		success = true;
}

Window::~Window()
{
	//Destroy window
	SDL_DestroyWindow(window);
	window = nullptr;

	//Quit SDL subsystems
	SDL_Quit();
}

void Window::render(Image& image)
{
	//Apply the image
	SDL_BlitScaled(image.getResource(), nullptr, screenSurface, &image.rect);
	//Update the surface
	SDL_UpdateWindowSurface(window);
}

// NOT NECESSARY:
// DO NOT DO: Switch to Textures (Chapter 7)
// Window constructor: CreateRenderer insteade of GetWindowSurface
// Window render: replace SDL_BLitSurface with SDL_RenderCOpy and SDL_UPdateWIndowSUrface with SDL_RenderPResent
// Image: replace imageSurface with newTexture SDL_CreateTextureFromSurface







// STEP 1: Follow Font Tutorial
// https://lazyfoo.net/tutorials/SDL/16_true_type_fonts/index.php
// CHeck out how I added SDL2_Image to the project on Loom (From Surface to Texture)
// do the text tutorial, but only do SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
// do not create a texture
// instead