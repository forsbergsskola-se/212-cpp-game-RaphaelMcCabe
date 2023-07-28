#pragma once
#include <SDL.h>
#include "Image.h"

extern class TextRenderer;

class Window
{
	//The window we'll be rendering to
	SDL_Window* window{};
	//The surface contained by the window
	SDL_Surface* screenSurface{};
	//Whether windows startup was successful
	bool success;
public:
	SDL_Renderer* renderer;
	Window(int width, int height);
	~Window();
	bool wasSuccessful() {return success;}
	void render(Image* image);
	void render(TextRenderer& image);
};

