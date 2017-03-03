#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include "Screen.h"

using namespace std;
using namespace particles;

int main() {
  
    Screen screen;

    if(screen.init() == false) {
        cout << "Error initializing SDL." << endl;
    }

    bool quit = false;

    // game loop
    while(true) {
        // update particles
        // draw particles
        // check for messages/events

        if(screen.processEvents() == false) {
            break;
        }
        
    }

    screen.close();

    return 0;
}