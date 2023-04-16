#pragma once
#include "GameObject.h"
class Button :
    public GameObject
{
protected:
    //Check if mouse is in button
    bool clickInside{ false };
    bool buttonPressed{ false };
public:
    virtual void update() = 0;
    Button(const char* imgPath, Window* window) : GameObject(imgPath, window) { }
    void setPosition(int x, int y);
    virtual void handleEvent(SDL_Event* e);
};

