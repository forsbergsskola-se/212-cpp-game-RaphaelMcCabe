#pragma once
#include <SDL.h>
#include "Image.h"

class Window
{
	//The window we'll be rendering to
	SDL_Window* gWindow{};
	//The surface contained by the window
	SDL_Surface* gScreenSurface{};
	//Whether windows startup was successful
	bool success;

	bool init(int width,int height);
public:
	Window(int width, int height){
		success = init(width, height);
	}
	~Window();
	bool wasSuccessful() {return success;}
	void render(Image& image);
};

