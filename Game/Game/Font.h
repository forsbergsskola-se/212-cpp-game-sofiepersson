#pragma once
#include <SDL_ttf.h>
#include <memory>
#include "Image.h"
#include <string>

using namespace std;

class Font
{
	TTF_Font* font{};
	bool success{};
public:
	Font(string path, const int size);
	~Font();
	bool wasSuccessful() { return success; }
	TTF_Font* getResource() { return font; }
	Font& operator =(Font& other) = delete;
	unique_ptr<Image> createText(string text, SDL_Renderer* renderer);
};

