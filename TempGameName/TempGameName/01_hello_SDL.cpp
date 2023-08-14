/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "Window.h"
#include "Image.h"
#include <string>
#include <SDL_ttf.h>
#include "TextRender.h"
#include "Font.h"


//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const char* fallbackSurface{ "img/dog.bmp" };

int main(int argc, char* args[])
{
	Window window{ SCREEN_WIDTH, SCREEN_HEIGHT };
	//Start up SDL and create window
	if (!window.wasSuccessful())
	{
		printf("Failed to initialize!\n");
		return -1;
	}

	//Initialize SDL_ttf
	if( TTF_Init() == -1 )
	{
		printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
		return -1;
	}

	//Load media
	Image image{ fallbackSurface };
	if (!image.wasSuccessful())
	{
		printf("Failed to load media!\n");
		return -1;
	}

	Font font{"font/zesty_ahh_font.ttf", 28};
	auto text = font.createText("What animal is this", window.renderer);

	SDL_Event e; bool quit = false;
	
	
	std::string userInput{""};
	SDL_Color textColor = { 50, 50, 50 };

	TextRenderer renderer{};
	renderer.gFont = TTF_OpenFont("font/zesty_ahh_font.ttf", 28);; // TODO LOAD FONT
	renderer.loadFromRenderedText(userInput, textColor);
	
	while (quit == false)
	{
		while (SDL_PollEvent(&e))
		{
			switch (e.type) {
			case SDL_QUIT: {
				quit = true;
			} break;
			case SDL_KEYDOWN: {
				if (e.key.keysym.sym == SDL_KeyCode::SDLK_RETURN) {
					printf("%s", userInput.c_str());
					if (userInput.compare("dog") == 0 || userInput.compare("Dog") == 0) {
						image = Image{ "img/press.bmp" };
					}
					userInput.clear();
				}
				else {
					
				} break;
			}
			case SDL_TEXTINPUT: {
				userInput += e.text.text;
					text = font.createText(userInput.c_str(), window.renderer);
			}break;
			}
			window.render(renderer);
			window.render(&image);
			window.render(text.get());
		}
	}
	return 0;
}