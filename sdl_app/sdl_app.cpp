//
// Created by slava on 30/09/17.
//
#include <iostream>
#include <SDL.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "sdl_app.h"
#include "Screen.h"
#include "Swarm.h"


using namespace std;
using namespace sdlapp;


int main() {

    srand(time(NULL));

    Swarm swarm;


    Screen screen;
    if (!screen.init()) {
        cout << "Error initialising SDL." << endl;
    };


    bool quit = false;

    SDL_Event event;

    while (true) {
        // Game loop
        // Update particles
        // Draw particles
        // Check for messages/events

        int elapsed = SDL_GetTicks();

        swarm.update(elapsed);


        unsigned char green = (1 + sin(elapsed * 0.0001)) * 128;
        unsigned char red = (1 + sin(elapsed * 0.0002)) * 128;
        unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;

        const Particle * const particles = swarm.getParticles();



        // Draw the particles
        for (int i = 0; i < Swarm::N_PARTICLES; i++) {
            Particle p_particle = particles[i];

            int x = (p_particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
            int y = (p_particle.m_y * Screen::SCREEN_WIDTH / 2) + Screen::SCREEN_HEIGHT / 2;

            screen.setPixel(x, y, red, green, blue);

        }

        screen.boxBlur();

        screen.update();

        if (!screen.processEvents()) {
            break;
        }


    }

    screen.close();

    return 0;
}