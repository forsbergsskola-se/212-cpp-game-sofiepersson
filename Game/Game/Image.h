#pragma once
#include <SDL.h>

class Image
{
	// The image we will load and show on the screen
	SDL_Texture* texture{};

	bool success{};
public:
	int x, y, width, height;

	Image(const char* path, SDL_Renderer* renderer);
	~Image();
	bool wasSuccessful() { return success; }
	SDL_Texture* getResource() { return texture; }
	Image& operator =(Image& other) = delete;
};