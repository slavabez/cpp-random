//
// Created by slava on 01/10/17.
//

#ifndef PROJECT_SCREEN_H
#define PROJECT_SCREEN_H


namespace sdlapp {

    class Screen {

    public:
        const static int SCREEN_WIDTH = 800;
        const static int SCREEN_HEIGHT = 640;

    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Texture *m_texture;
        Uint32 *m_buffer1;
        Uint32 *m_buffer2;


    public:
        Screen();
        bool init();
        bool processEvents();
        void close();
        void update();
        void boxBlur();
        void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);

    };


}


#endif //PROJECT_SCREEN_H
