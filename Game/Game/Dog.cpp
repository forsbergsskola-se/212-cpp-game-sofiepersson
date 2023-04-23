#include "Dog.h"
#include <iostream>

using namespace std;

void Dog::update() {
}

void Dog::handleEvent(SDL_Event* e) {
	Button::handleEvent(e);
	if (clickInside) {
		heartCount += heartsOnClick;
	}
}
