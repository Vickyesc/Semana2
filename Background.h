#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>

class Background
{
    public:
        Background(SDL_Surface *screen);
        void logic();
        void render();
        void setInicio(int i);
        int getInicio();
        int numPantalla;
        virtual ~Background();
    protected:
    private:
    int x;
    SDL_Surface *background[2];
    SDL_Surface *screen;
};

#endif // BACKGROUND_H
