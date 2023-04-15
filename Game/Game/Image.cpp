#include "Image.h"
#include <cstdio>
#include <SDL.h>
#include <SDL_image.h>

Image::Image(const char* path, const SDL_PixelFormat* pixelFormat) :
	success{},
	x{},
	y{},
	width{ 100 },
	height{ 100 } {
	// Load splash image
	auto tempSurface = IMG_Load(path);
	if (!tempSurface) {
		printf("Unable to load image %s! SDL Error: %s\n", path, IMG_GetError());
		return;
	}

	imageSurface = SDL_ConvertSurface(tempSurface, pixelFormat, 0);
	SDL_FreeSurface(tempSurface);
	if (!imageSurface) {
		printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
		return;
	}

	success = true;
}

Image::~Image() {
	//Deallocate surface
	SDL_FreeSurface(imageSurface);
	imageSurface = nullptr;
}