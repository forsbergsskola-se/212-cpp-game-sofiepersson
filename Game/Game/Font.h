#pragma once
#include <SDL_ttf.h>
#include <memory>
#include "Image.h"

using namespace std;

class Font
{
	TTF_Font* font{};
	bool success{};
public:
	Font(const char* path, const int size);
	~Font();
	bool wasSuccessful() { return success; }
	TTF_Font* getResource() { return font; }
	Font& operator =(Font& other) = delete;
	unique_ptr<Image> createText(const char* text, SDL_Renderer* renderer);
};

