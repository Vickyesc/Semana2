#ifndef INICIO_H
#define INICIO_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>

class Inicio
{
    public:
        Inicio(SDL_Surface *screen);
        void logic();
        void render();

        virtual ~Inicio();
    protected:
    private:

        int x;
    SDL_Surface *image;
    SDL_Surface *screen;
};

#endif // INICIO_H
