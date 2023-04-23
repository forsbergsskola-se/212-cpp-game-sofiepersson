#pragma once
#include "Button.h"
#include "Dog.h"
class BoneUpgrade :
    public Button
{
    int x{400}, y{25}, width{100}, height{100};
    Dog* dog;
    unsigned int upgradeCost{ 50 };
    unsigned int owned{};
    unsigned int upgradePerClick{ 2 };
    int autoClickSlowdown{ 0 };
    unsigned int autoClickPerSecond{ 1 + owned };
public:
    BoneUpgrade(Window* window, Dog* dog) : Button("img/bone.png", window), dog{ dog } {
        image->width = width;
        image->height = height;
        image->x = x;
        image->y = y;
    }
    void update() override;
    void handleEvent(SDL_Event* e) override;
    int getBones() { return owned; }
};

