/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "Window.h"
#include "Image.h"
#include <map>
#include <string>


//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


const std::map<SDL_KeyCode, const char*> surfaceMap{
	{SDL_KeyCode::SDLK_UP, "img/up.bmp"},
	{SDL_KeyCode::SDLK_DOWN, "img/down.bmp"},
	{SDL_KeyCode::SDLK_LEFT, "img/left.bmp"},
	{SDL_KeyCode::SDLK_RIGHT, "img/right.bmp"},
	{SDL_KeyCode::SDLK_a, "img/alpaca.bmp"},
	{SDL_KeyCode::SDLK_b, "img/boar.bmp"},
	{SDL_KeyCode::SDLK_c, "img/crab.bmp"},
	{SDL_KeyCode::SDLK_d, "img/dog.bmp"},
};
const char* fallbackSurface{ "img/press.bmp" };

int main(int argc, char* args[])
{
	Window window{ SCREEN_WIDTH, SCREEN_HEIGHT };
	//Start up SDL and create window
	if (!window.wasSuccessful())
	{
		printf("Failed to initialize!\n");
		return -1;
	}

	//Load media
	Image image{ fallbackSurface };
	if (!image.wasSuccessful())
	{
		printf("Failed to load media!\n");
		return -1;
	}
	//Hack to get window to stay up
	SDL_Event e; bool quit = false;
	std::string userInput{};
	while (quit == false)
	{
		while (SDL_PollEvent(&e))
		{
			switch (e.type) {
			case SDL_QUIT: {
				quit = true;
			} break;
			case SDL_KEYDOWN: {
				if (e.key.keysym.sym == SDL_KeyCode::SDLK_a) {
					userInput += "a";
				}
				if (e.key.keysym.sym == SDL_KeyCode::SDLK_RETURN) {
					printf("%s", userInput.c_str());
				}
				if (auto result = surfaceMap.find((SDL_KeyCode)e.key.keysym.sym); result != surfaceMap.end()) {
					auto value = *result;
					auto imageName = value.second;
					image = Image{ imageName };
				}
				else {
					image = Image{ fallbackSurface };
				} break;
			}
			}
			window.render(image);
		}	
	}
	return 0;
}