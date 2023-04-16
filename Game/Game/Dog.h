#pragma once
#include "Button.h"
#include "GameObject.h"

class Dog : public Button
{
    int width{ 200 };
    int height{ 350 };
    unsigned int heartCount{};
    unsigned int heartsOnClick{ 1 };
public:
    Dog(Window* window) : Button("img/Ludde1.png", window) {
        image->width = width;
        image->height = height;
    }
    void update() override;
    void handleEvent(SDL_Event* e) override;
};

