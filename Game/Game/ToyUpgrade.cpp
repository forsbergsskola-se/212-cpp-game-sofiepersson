#include "ToyUpgrade.h"

#include <iostream>

using namespace std;

void ToyUpgrade::update() {
	if (owned > 0) {
		if (autoClickSlowdown > 5) {
			dog->setHeartCount(dog->getHeartCount() + autoClickPerSecond);
			autoClickSlowdown = 0;
		}
		else
			++autoClickSlowdown;
	}
}

void ToyUpgrade::handleEvent(SDL_Event* e) {
	Button::handleEvent(e);
	if (int heartCount = dog->getHeartCount(); heartCount >= upgradeCost && clickInside) {
		++owned;
		dog->setHeartCount(heartCount - upgradeCost);
		dog->setHeartsOnClick(dog->getHeartsOnClick() + upgradePerClick);
		upgradeCost *= 0.8f + owned;
	}
}