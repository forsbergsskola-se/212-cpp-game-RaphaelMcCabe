#pragma once
#include <SDL.h>
class Image
{
	//The image we will load and show on the screen
	SDL_Surface* imageSurface{};
	bool success;
	public:
public:
	Image(const char* path);
	~Image();
	SDL_Rect rect { 0, 0, 640, 480 };
	bool wasSuccessful() { return success; }
	SDL_Surface* getResource()
	{
		return imageSurface;
	}
};

