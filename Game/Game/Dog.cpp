#include "Dog.h"
#include <iostream>

using namespace std;

void Dog::update() {
	cout << heartCount << endl;
}

void Dog::handleEvent(SDL_Event* e) {
	Button::handleEvent(e);
	if (inside ) {
		heartCount += heartsOnClick;
	}
}
