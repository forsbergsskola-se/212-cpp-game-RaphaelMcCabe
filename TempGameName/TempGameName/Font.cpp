#include "Font.h"
#include <cstdio>
#include <SDL.h>
#include <SDL_ttf.h>
#include "Image.h"


Font::Font(const char* path, const int size) : success{}
{
    font = TTF_OpenFont( path, size );
    if( font == nullptr )
    {
        printf( "Failed to load font! %s Error: %s\n", path, TTF_GetError() );
        success = false;
    }
    else
    {
        success = true;
    }
}

Font::~Font()
{
    TTF_CloseFont(font);
    font = nullptr;
}

std::unique_ptr<Image> Font::createText(const char* text, SDL_Renderer* renderer)
{
    SDL_Color textColor = {0, 0, 0};
    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, textColor );
    if( textSurface == nullptr )
    {
        printf( "Unable to render text surface! %s Error: %s\n","",TTF_GetError() );
    }
     else
     {
         return std::make_unique<Image>(textSurface);
     }
    return nullptr;
}