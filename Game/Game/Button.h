#pragma once
#include "GameObject.h"
class Button :
    public GameObject
{
public:
    virtual void update() = 0;
    Button(const char* imgPath, Window* window) : GameObject("img/Ludde1.png", window) { }
    void setPosition(int x, int y);
    void handleEvent(SDL_Event* e);
};

