#include "Image.h"
#include <cstdio>
#include <SDL.h>
#include <SDL_image.h>

Image::Image(const char* path, SDL_Renderer* renderer) :
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

	auto texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	if (!texture) {
		printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
		return;
	}

	success = true;
}

Image::~Image() {
	//Deallocate surface
	SDL_DestroyTexture(texture);
	texture = nullptr;
}