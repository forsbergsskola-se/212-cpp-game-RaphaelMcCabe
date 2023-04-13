#pragma once
#include <SDL.h>
class Image
{
	//The image we will load and show on the screen
	SDL_Surface* gHelloWorld{};
	bool loadMedia(const char* path);
	bool success;
	public:
public:
	Image(const char* path){
		success = loadMedia(path);
	}
	~Image();
	bool wasSuccessful() { return success; }
	SDL_Surface* getResource()
	{
		return gHelloWorld;
	}
};

