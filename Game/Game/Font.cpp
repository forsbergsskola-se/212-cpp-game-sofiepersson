#include "Font.h"

#include <cstdio>
#include <SDL_ttf.h>
#include "Image.h"

Font::Font(string path, const int size) :
	success{} {
	//Open the font
	font = TTF_OpenFont(path.c_str(), size);
	if (font == nullptr)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	success = true;
}

Font::~Font() {
	//Deallocate surface
	TTF_CloseFont(font);
	font = nullptr;
}

unique_ptr<Image> Font::createText(string text, SDL_Renderer* renderer)
{
    SDL_Color textColor{ 0, 0, 0 };
    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
    if (textSurface == nullptr)
    {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    }
    else
    {
        //Create texture from surface pixels
        auto mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        if (mTexture == nullptr)
        {
            printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        }
        else
        {
            //Get image dimensions
            auto width = textSurface->w;
            auto height = textSurface->h;
            auto image = std::make_unique<Image>(mTexture);
            image->width = width;
            image->height = height;
            return std::move(image);
        }
    }
    return nullptr;
}
