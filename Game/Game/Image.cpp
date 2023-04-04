#include "Image.h"
#include <cstdio>
#include <SDL.h>

bool Image::loadMedia() {
	// Loading success flag
	bool success = true;

	// Load splash image
	gHelloWorld = SDL_LoadBMP("hello_world.bmp");
	if (!gHelloWorld) {
		printf("Unable to load image %s! SDL Error: %s\n", "hello_world.bmp", SDL_GetError());
		success = false;
	}
	return success;
}

Image::~Image() {
	//Deallocate surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = nullptr;
}