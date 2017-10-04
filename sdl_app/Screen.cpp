//
// Created by slava on 01/10/17.
//

#include <SDL.h>
#include "Screen.h"


namespace sdlapp {
    Screen::Screen() : m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer1(NULL), m_buffer2(NULL) {}

    bool Screen::init() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0){
            return false;
        }

        m_window = SDL_CreateWindow(
                "Particle Fire Explosion",
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                SCREEN_WIDTH,
                SCREEN_HEIGHT,
                SDL_WINDOW_SHOWN
        );

        if (m_window == NULL){
            SDL_Quit();
            return false;
        }

        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
        if (m_renderer == NULL) {
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        }

        m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
        if (m_texture == NULL) {
            SDL_DestroyTexture(m_texture);
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        }

        m_buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
        m_buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

        for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH; i++){
            m_buffer1[i] = 0x00000080;
        }

        return true;
    }

    bool Screen::processEvents() {
        SDL_Event event;

        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                return false;
            }
        }

        return true;
    }

    void Screen::close() {
        delete [] m_buffer1;
        delete [] m_buffer2;
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyTexture(m_texture);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
    }


    void Screen::update() {
        SDL_UpdateTexture(m_texture, NULL, m_buffer1, SCREEN_WIDTH * sizeof(Uint32));
        SDL_RenderClear(m_renderer);
        SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
        SDL_RenderPresent(m_renderer);
    }

    void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {

        if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT){
            return;
        }

        Uint32 color = 0;

        color += red;
        color <<= 8;
        color += green;
        color <<= 8;
        color += blue;
        color <<= 8;
        color += 0xFF;

        m_buffer1[(y * SCREEN_WIDTH) + x] = color;
    }

    void Screen::boxBlur() {
        // Swap the buffers, pixel info goes into buffer 2, drawing to buffer 1
        Uint32 * temp = m_buffer1;

        m_buffer1 = m_buffer2;
        m_buffer2 = temp;

        for (int y = 0; y < SCREEN_HEIGHT; y++) {
            for (int x = 0; x < SCREEN_WIDTH; x++) {

                // Blur the pixel colour by averaging RGB values of 8 surrounding pixels
                int redTotal = 0;
                int greenTotal = 0;
                int blueTotal = 0;

                for (int row = -1; row <= 1; row++) {
                    for (int col = -1; col <= 1; col++){
                        int pixelX = x + col;
                        int pixelY = y + row;

                        if (pixelX >= 0 && pixelX < SCREEN_WIDTH && pixelY >= 0 && pixelY < SCREEN_HEIGHT){
                            Uint32 colour = m_buffer2[pixelY * SCREEN_WIDTH + pixelX];

                            Uint8 red = colour >> 24;
                            Uint8 green = colour >> 16;
                            Uint8 blue = colour >> 8;

                            redTotal += red;
                            greenTotal += green;
                            blueTotal += blue;
                        }

                    }
                }

                // Added the averages
                Uint8 red = redTotal / 9;
                Uint8 green = greenTotal / 9;
                Uint8 blue = blueTotal / 9;

                setPixel(x, y, red, green, blue);

            }
        }
    }


}