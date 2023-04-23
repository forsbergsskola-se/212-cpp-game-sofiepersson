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
#include "BoneUpgrade.h"
#include "ToyUpgrade.h"
#include "Font.h"
#include <string>

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
	Dog* dog = new Dog{ &window };
	gameObjects.push_back(dog);

	BoneUpgrade* boneUpgrade = new BoneUpgrade{ &window, dog };
	gameObjects.push_back(boneUpgrade);

	ToyUpgrade* toyUpgrade = new ToyUpgrade{ &window, dog };
	gameObjects.push_back(toyUpgrade);

	Font font{ "fonts/Oswald-Bold.ttf", 28 };
	auto hearts = dog->getHeartCount();
	auto heartCounterText = font.createText(to_string(hearts), window.getRenderer());

	auto bones = boneUpgrade->getBones();
	auto boneAmountText = font.createText(to_string(bones), window.getRenderer());

	auto toys = toyUpgrade->getToys();
	auto toyAmountText = font.createText(to_string(toys), window.getRenderer());

	auto heartImage = window.loadImage("img/heart.png");
	heartImage->width = 25;
	heartImage->height = 25;
	heartImage->x = 90;
	heartImage->y = 8;

	auto bonePrice = boneUpgrade->getPrice();
	auto bonePriceText = font.createText(to_string(bonePrice), window.getRenderer());

	auto toyPrice = toyUpgrade->getPrice();
	auto toyPriceText = font.createText(to_string(toyPrice), window.getRenderer());

	auto priceText = font.createText("Price:", window.getRenderer());
	priceText->x = 370;
	priceText->y = 40;

	auto priceText2 = font.createText("Price:", window.getRenderer());
	priceText2->x = 370;
	priceText2->y = 220;

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

		// Updates heart counter text
		hearts = dog->getHeartCount();
		heartCounterText = font.createText(to_string(hearts), window.getRenderer());
		heartCounterText->x = 130;

		// Updates owned bones counter text
		bones = boneUpgrade->getBones();
		boneAmountText = font.createText(to_string(bones), window.getRenderer());
		boneAmountText->x = 450;
		boneAmountText->y = 165;

		// Updates owned toys counter text
		toys = toyUpgrade->getToys();
		toyAmountText = font.createText(to_string(toys), window.getRenderer());
		toyAmountText->x = 450;
		toyAmountText->y = 350;

		bonePrice = boneUpgrade->getPrice();
		bonePriceText = font.createText(to_string(bonePrice), window.getRenderer());
		bonePriceText->x = 445;
		bonePriceText->y = 40;

		toyPrice = toyUpgrade->getPrice();
		toyPriceText = font.createText(to_string(toyPrice), window.getRenderer());
		toyPriceText->x = 445;
		toyPriceText->y = 220;

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
		window.render(heartCounterText.get());
		window.render(boneAmountText.get());
		window.render(toyAmountText.get());
		window.render(heartImage.get());
		window.render(bonePriceText.get());
		window.render(toyPriceText.get());
		window.render(priceText.get());
		window.render(priceText2.get());

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

	//Initialize SDL_ttf
	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
	}
}
