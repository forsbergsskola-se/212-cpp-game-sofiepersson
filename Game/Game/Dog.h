#pragma once
#include "GameObject.h"
class Dog :
    public GameObject
{
    int width{ 300 };
    int height{ 300 };

public:
    Dog(Window* window) : GameObject("img/Ludde1.png", window) {
        image->width = width;
        image->height = height;
    }
    void update() override;
};

