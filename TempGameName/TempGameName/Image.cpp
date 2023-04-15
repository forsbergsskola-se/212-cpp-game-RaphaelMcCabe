#include "Image.h"
#include "SDL.h"
#include <cstdio>
Image::Image(const char* path) : success{}
{

	//Load splash image
	auto tmpSurface = SDL_LoadBMP(path);
	if (!tmpSurface)
	{
		printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
		return;
	}

	imageSurface = tmpSurface; // SDL_CreateTextureFromSurface
	
	success = true;
}

Image::~Image()
{
	//Deallocate surface
	//SDL_FreeSurface(imageSurface);
	//imageSurface = nullptr;
}
