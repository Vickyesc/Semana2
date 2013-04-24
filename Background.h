#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include <string>

class Background
{
    public:
        Background(SDL_Surface *screen);
        void logic();
        void render();
        virtual ~Background();
    protected:
    private:
    int x;
    SDL_Surface *image;
    SDL_Surface *screen;
};

#endif // BACKGROUND_H
