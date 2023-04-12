#include "Image.h"
#include <cstdio>
#include <SDL.h>

Image::Image(const char* path) : success{} {
	// Load splash image
	imageSurface = SDL_LoadBMP(path);
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