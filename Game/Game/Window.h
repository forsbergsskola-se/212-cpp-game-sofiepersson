#pragma once
#include "Image.h"
class Window
{
	//The window we'll be rendering to
	SDL_Window* window{};

	//The surface contained by the window
	SDL_Surface* screenSurface{};

	bool success;
public:
	Window(int width, int height);
	~Window();
	bool wasSuccessful() { return success; }
	void render(Image& image);
};

