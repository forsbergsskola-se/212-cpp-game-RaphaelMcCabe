/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "Window.h"
#include "Image.h"
#include <map>
#include <string>
#include <SDL_ttf.h>
#include "TextRender.h"



//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

/*
you just load the dog image
it says what animal is this?
you check the input
   if it is a letter
	  add the letter to your string
	  create a text from the string (font tutorial)
	  render the text to the window
  if it is return
	  compare the string to std::string{"dog"}. if it is the same
		  show image: congrats
		  (or just change the string to "Congrats"!
	  if it is not
		  show image: failllll
		  (or just change the string to "Fail"!

*/
const std::map<SDL_KeyCode, const char*> surfaceMap{
	/*{SDL_KeyCode::SDLK_UP, "img/up.bmp"},
	{SDL_KeyCode::SDLK_DOWN, "img/down.bmp"},
	{SDL_KeyCode::SDLK_LEFT, "img/left.bmp"},
	{SDL_KeyCode::SDLK_RIGHT, "img/right.bmp"},
	{SDL_KeyCode::SDLK_a, "img/alpaca.bmp"},
	{SDL_KeyCode::SDLK_b, "img/boar.bmp"},
	{SDL_KeyCode::SDLK_c, "img/crab.bmp"},
	{SDL_KeyCode::SDLK_d, "img/dog.bmp"},*/
};
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

	//Load media
	Image image{ fallbackSurface };
	if (!image.wasSuccessful())
	{
		printf("Failed to load media!\n");
		return -1;
	}

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
					if (userInput.compare("dog") == 0) {
						image = Image{ "img/press.bmp" };
					}
					userInput.clear();
				}
				else {
					
				} break;
			}
			case SDL_TEXTINPUT: {
				userInput += e.text.text;
			}break;
			}
			window.render(renderer);
			window.render(image);
		}
	}
	return 0;
}