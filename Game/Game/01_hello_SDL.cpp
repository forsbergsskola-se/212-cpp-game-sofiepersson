/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "Window.h"
#include "Image.h"
#include <map>
#include <memory>
#include <SDL_image.h>
#include <vector>
#include "GameObject.h"
#include "Dog.h"

using namespace std;

void initImage();

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const map<SDL_KeyCode, const char*> surfaceMap = {
	{SDL_KeyCode::SDLK_UP, "img/up.bmp"},
	{SDL_KeyCode::SDLK_DOWN, "img/down.bmp"},
	{SDL_KeyCode::SDLK_LEFT, "img/left.bmp"},
	{SDL_KeyCode::SDLK_RIGHT, "img/right.bmp"},
};

const char* fallbackSurface{ "img/press.bmp" };

const unsigned int FPS{ 30 };
const unsigned int MsPerFrame{ 1000 / FPS };

int main(int argc, char* args[])
{
	initImage();
	// Start up SDL and create window
	Window window{ SCREEN_WIDTH, SCREEN_HEIGHT };
	if (!window.wasSuccessful()) {
		printf("Failed to initialize!\n");
		return -1;
	}

	vector<GameObject*> gameObjects{};
	
	// Load media
	gameObjects.push_back(new Dog{ &window });

	// Get window to stay up
	SDL_Event e{};
	bool quit = false;

	unsigned int frameStartMs {};
	while (quit == false) {
		// start the timer
		frameStartMs = SDL_GetTicks();

		for (auto gameObject : gameObjects) {
			gameObject->update();
		}

		while (SDL_PollEvent(&e)) {
			for (auto gameObject : gameObjects) {
				if (Button* button = dynamic_cast<Button*>(gameObject)) {
					button->handleEvent(&e);
				}
			}
			switch (e.type) {
			case SDL_QUIT: {
				quit = true;
				break;
			}
			}
		}
		window.clear();
		
		for (auto gameObject : gameObjects) {
			gameObject->render(&window);
		}

		window.present();

		// see how long we should wait so we get 30 fps
		// fixed update
		unsigned int frameTimeMs = SDL_GetTicks() - frameStartMs;
		if (frameTimeMs < MsPerFrame) {
			SDL_Delay(MsPerFrame - frameTimeMs);
		}
	}
	return 0;
}

void initImage() {
	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}
}
