#pragma once
#include "Button.h"
#include "Dog.h"
class BoneUpgrade :
    public Button
{
    int x{370}, y{75}, width{180}, height{90};
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

