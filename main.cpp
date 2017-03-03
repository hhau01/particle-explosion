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

    int max = 0;

    // game loop
    while(true) {
        // update particles

        // draw particles
        for(int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
            for(int x = 0; x < Screen::SCREEN_WIDTH; x++) {
                screen.setPixel(x, y, 128, 0, 255);
            }
        }

        // screen.setPixel(400, 300, 255, 255, 255);

        // draw screen
        screen.update();
        
        // check for messages/events
        if(screen.processEvents() == false) {
            break;
        }
    }

    screen.close();

    return 0;
}