#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
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

        swarm.update(elapsed);

        unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
        unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
        unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);

        const Particle * const pParticles = swarm.getParticles();

        for(int i = 0; i < Swarm::NPARTICLES; i++) {
            Particle particle = pParticles[i];

            int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
            int y = particle.m_y * Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2;

            screen.setPixel(x, y, red, green, blue);
        }

        // background color
        // for(int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
        //     for(int x = 0; x < Screen::SCREEN_WIDTH; x++) {
        //         screen.setPixel(x, y, red, green, blue);
        //     }
        // }

        // box blur
        screen.boxBlur();

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