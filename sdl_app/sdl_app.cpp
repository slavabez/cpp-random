//
// Created by slava on 30/09/17.
//
#include <iostream>
#include <SDL.h>
#include <math.h>
#include <stdlib.h>

#include "sdl_app.h"
#include "Screen.h"


using namespace std;
using namespace sdlapp;


int main() {

    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 640;


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
        unsigned char green = (1 + sin(elapsed * 0.0001)) * 128;
        unsigned char red = (1 + sin(elapsed * 0.0002)) * 128;
        unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;

        // Draw pixels
        for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
            for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
                screen.setPixel(x, y, red, green, blue);
            }
        }

        screen.update();

        if (!screen.processEvents()) {
            break;
        }


    }

    screen.close();

    return 0;
}