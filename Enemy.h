#ifndef ENEMY_H
#define ENEMY_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include <string>

class Enemy
{
public:
    int x;
    int y;
    int velocity;
    int acceleration;
    int current_frame;
    SDL_Surface *images[7];
    SDL_Surface *screen;

    Enemy(SDL_Surface *screen);
    void logic();
    void render();
    void jump();
    virtual ~Enemy();
};

#endif // ENEMY_H
