#ifndef FIRE_H
#define FIRE_H
#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"


class Fire
{
    public:

    int x;
    int y;
    int velocity;
    int acceleration;
    int current_frame;
    SDL_Surface *images[3];
    SDL_Surface *screen;

  Fire(SDL_Surface *screen);

    void logic();
    void render();
    void jump();

        virtual ~Fire();

};

#endif // FIRE_H
