#include "Window.h"
#include <cstdio>
#include <SDL.h>

Window::Window(int width, int height) : success{} {
	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO)) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return;
	}

	// Create window
	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (!window) {
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return;
	}

	// Get window surface
	screenSurface = SDL_GetWindowSurface(window);
	success = true;
}

Window::~Window() {
	//Destroy window
	SDL_DestroyWindow(window);
	window = nullptr;

	// Quit SDL subsystems
	SDL_Quit();
}

void Window::render(Image* image) {
	SDL_Rect targetRectangle{
		image->x,
		image->y,
		image->width,
		image->height
	};
	// Apply the image
	SDL_BlitScaled(image->getResource(), nullptr, screenSurface, &targetRectangle);

	//Update the surface
	SDL_UpdateWindowSurface(window);
}

unique_ptr<Image> Window::loadImage(const char* path) {
	return make_unique<Image>(path, screenSurface->format);
}

void Window::clear() {
	static Uint32 clearColor{ SDL_MapRGB(screenSurface->format, 0, 0, 0) };
	SDL_FillRect(screenSurface, nullptr, clearColor);
}
