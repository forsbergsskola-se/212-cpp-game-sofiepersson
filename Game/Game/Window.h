#pragma once
#include "Image.h"
#include <memory>
using namespace std;

class Window
{
	//The window we'll be rendering to
	SDL_Window* window{};

	//The surface contained by the window
	SDL_Surface* screenSurface{};
	SDL_Renderer* renderer{};

	bool success{};
public:
	Window(int width, int height);
	~Window();
	bool wasSuccessful() { return success; }
	void clear();
	void present();
	void render(Image* image);
	unique_ptr<Image> loadImage(const char* path);
	SDL_Renderer* getRenderer() { return renderer; }
};

