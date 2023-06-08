# Puppy Petter
Puppy Petter is a cookie clicker inspired game written in C++ and created using SDL2. In Puppy Petter your goal is to collect as many hearts as possible. You get hearts by petting (clicking on) your puppy, and with the hearts you can purchase upgrades in the form of bones and toys, which increase the amount of hearts you get per click, as well as producing hearts automatically. 

## Screenshots

##### The game when owning 1 of each upgrade
![image](https://user-images.githubusercontent.com/112477846/234026848-cafe04a8-a666-494d-8113-c8fa56a4e099.png)

##### The game when owning 3 of each upgrade
![image](https://user-images.githubusercontent.com/112477846/234027341-16989328-88af-4295-a2e0-813b25188172.png)

## Video

### DISCLAIMER: The video recording software moves the window to the corner so it looks like I am clicking outside of the game, which I am not.
https://user-images.githubusercontent.com/112477846/234028369-2e51d84f-6c3d-42c2-a9fa-d79ed8428d63.mp4

The game could be improved by adding more upgrades, adding sound, adding more effects, such as heart animation when petting your puppy. 

## Design Patterns used

### Double buffer Pattern
Used when rendering to make sure that rendering isn't glitchy, for example so that textures on the screen don't flicker. This is done by rendering everything to another screen before presenting it so that everything is rendered properly when it is shown.

### Update method Pattern
Used in each game object class to take away responsibilty and reduce the size of the main function by giving each class their own update function. The main function then only has to keep track of all game objects and then call the update function for each of them. It is also then easier to change the update logic for a class as it is all encapsulated in it's own class. 

### Game loop Pattern
Used in the main function in the form of a fixed update which causes a delay after having updated 30 times in one second to make the game act the same way regardless of the computer that is running it.

## Advanced C++ Features used

### Collections, specifically vector
Used in main function to keep track of all game object instances because it is needed for updating all game objects.

### Runtime Polymorphism, specifically dynamic cast
Used to check if click events are the player pressing a button because then the button logic needs to be called.
