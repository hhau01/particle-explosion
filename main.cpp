#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include "Screen.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Particle.h"
#include "Swarm.h"

using namespace std;
using namespace particles;

int main() {
  
    srand(time(NULL));
    
    Screen screen;

    if(screen.init() == false) {
        cout << "Error initializing SDL." << endl;
    }

    Swarm swarm;

    // game loop
    while(true) {
        // update particles

        // draw particles

        int elapsed = SDL_GetTicks();

        unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0007)) * 128);
        unsigned char green = (unsigned char)((1 + cos(elapsed * 0.0008)) * 128);
        unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0009)) * 128);

        const Particle * const pParticles = swarm.getParticles();

        for(int i = 0; i < Swarm::NPARTICLES; i++) {
            Particle particle = pParticles[i];

            int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
            int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT/2;

            screen.setPixel(x, y, red, green, blue);
        }

        // for(int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
        //     for(int x = 0; x < Screen::SCREEN_WIDTH; x++) {
        //         screen.setPixel(x, y, red, green, blue);
        //     }
        // }

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