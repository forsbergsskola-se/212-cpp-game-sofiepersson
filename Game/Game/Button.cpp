#include "Button.h"
#include <iostream>

using namespace std;

void Button::setPosition(int x, int y) {
    if (image == nullptr) {
        cout << "Image is null." << endl;
        return;
    }
	image->x = x;
	image->y = y;
}

void Button::handleEvent(SDL_Event* e) {
    //If mouse event happened
    if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
    {
        cout << "Mouse event" << endl;
        //Get mouse position
        int x, y;
        SDL_GetMouseState(&x, &y);
        // Check for error
        const char* error = SDL_GetError();
        if (*error != '\0') {
            // Handle the error, for example, by printing an error message or throwing an exception
            cout << "SDL_GetMouseState() failed with error: " << error << endl;
            SDL_ClearError(); // Clear the error string after handling it
            return;
        }
        //Check if mouse is in button
        bool inside = true;

        //Mouse is left of the button
        if (x < image->x)
        {
            inside = false;
            cout << "Left" << endl;
        }
        //Mouse is right of the button
        else if (x > image->x + image->width)
        {
            inside = false;
            cout << "right" << endl;
        }
        //Mouse above the button
        else if (y < image->y)
        {
            inside = false;
            cout << "Above" << endl;
        }
        //Mouse below the button
        else if (y > image->y + image->height)
        {
            inside = false;
            cout << "Below" << endl;
        }
        if (inside) {
            cout << "Pressed Ludde!" << endl;
        }
    }
}
