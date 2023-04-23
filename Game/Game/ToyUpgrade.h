#pragma once
#include "Button.h"
#include "Dog.h"
class ToyUpgrade :
    public Button
{
    int x{ 370 }, y{ 255 }, width{ 180 }, height{ 90 };
    Dog* dog;
    unsigned int upgradeCost{ 75 };
    unsigned int owned{};
    unsigned int upgradePerClick{ 5 };
    int autoClickSlowdown{ 0 };
    unsigned int autoClickPerSecond{ 3 + owned };
public:
    ToyUpgrade(Window* window, Dog* dog) : Button("img/toys.png", window), dog{ dog } {
        image->width = width;
        image->height = height;
        image->x = x;
        image->y = y;
    }
    void update() override;
    void handleEvent(SDL_Event* e) override;
    int getToys() { return owned; }
    int getPrice() { return upgradeCost; }
};

