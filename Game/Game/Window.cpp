#include "Window.h"
#include <cstdio>
#include <SDL.h>
#include <SDL_ttf.h>

Window::Window(int width, int height) : success{} {
	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO)) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return;
	}

	// Create window and renderer
	SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, &window, &renderer);
	if (!window) {
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return;
	}
	if (!renderer) {
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		return;
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear"); // make the scaled rendering look smoother
	SDL_RenderSetLogicalSize(renderer, width, height);

	success = true;
}

Window::~Window() {
	//Destroy window
	SDL_DestroyWindow(window);
	window = nullptr;

	// Quit SDL subsystems
	SDL_Quit();

	// Quit SDL2_ttf
	TTF_Quit();
}

void Window::render(Image* image) {
	SDL_Rect targetRectangle{
		image->x,
		image->y,
		image->width,
		image->height
	};
	// Apply the image
	SDL_RenderCopy(renderer, image->getResource(), nullptr, &targetRectangle);
}

unique_ptr<Image> Window::loadImage(const char* path) {
	return make_unique<Image>(path, renderer);
}

void Window::clear() {
	SDL_SetRenderDrawColor(renderer, 150, 99, 5, 255);
	SDL_RenderClear(renderer);
}

void Window::present() {
	SDL_RenderPresent(renderer);
}