#pragma once

#include <memory>
#include "Image.h"

extern class Window;

using namespace std;

class GameObject
{
protected:
	unique_ptr<Image> image;
public:
	GameObject(const char* imagePath, Window* window);
	virtual void update() = 0;
	void render(Window* window);
};

