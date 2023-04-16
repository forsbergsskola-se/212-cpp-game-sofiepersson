#pragma once
#include "Button.h"
#include "GameObject.h"

class Dog : public Button
{
    int width{ 200 };
    int height{ 350 };
    int x{ 25 }, y{ 40 };
    unsigned int heartCount{};
    unsigned int heartsOnClick{ 1 };
public:
    Dog(Window* window) : Button("img/Ludde1.png", window) {
        image->width = width;
        image->height = height;
        image->x = x;
        image->y = y;
    }
    void update() override;
    void handleEvent(SDL_Event* e) override;
    int getHeartCount() { return heartCount; }
    int getHeartsOnClick() { return heartsOnClick; }
    void setHeartCount(unsigned int hearts) { heartCount = hearts; }
    void setHeartsOnClick(unsigned int hearts) { heartsOnClick = hearts; }
};

