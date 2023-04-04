/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "Window.h"

// Loads media
bool loadMedia();

// Frees media and shuts down SDL
void close();

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// The image we will load and show on the screen
SDL_Surface* gHelloWorld{};

int main(int argc, char* args[])
{
	Window window{ SCREEN_WIDTH, SCREEN_HEIGHT };
	// Start up SDL and create window
	if (!window.wasSuccessful()) {
		printf("Failed to initialize!\n");
		return -1;
	}
	// Load media
	if (!loadMedia()) {
		printf("Failed to load media!\n");
	}
	else {
		// Apply the image
		//SDL_BlitSurface(gHelloWorld, nullptr, gScreenSurface, nullptr);

		//Update the surface
		//SDL_UpdateWindowSurface(gWindow);

		// Get window to stay up
		SDL_Event e{};
		bool quit = false;
		while (quit == false) {
			while (SDL_PollEvent(&e)) {
				if (e.type == SDL_QUIT) {
					quit = true;
				}
			}
		}
	}
	// Free resources and close SDL
	close();

	return 0;
}

bool loadMedia() {
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

void close() {
	//Deallocate surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = nullptr;
}
