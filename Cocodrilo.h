#ifndef COCODRILO_H
#define COCODRILO_H

#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

class Cocodrilo
{
    public:
    Cocodrilo( SDL_Surface *screen);
    int x;
    int y;
    int velocity;
    int acceleration;
    int current_frame;
    SDL_Surface *images[6];
    SDL_Surface *screen;

    void logic();
    void render();
    void jump();
        virtual ~Cocodrilo();




    protected:
    private:
};

#endif // COCODRILO_H
