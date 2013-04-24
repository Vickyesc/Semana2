#ifndef PLAYER_H
#define PLAYER_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include <string>

class Player
{
public:
    int x;
    int y;
    int velocity;
    int acceleration;
    int current_frame;
    SDL_Surface *images[5];
    SDL_Surface *screen;

    Player(SDL_Surface *screen);
    void logic();
    void render();
    void jump();
    virtual ~Player();
};

#endif // PLAYER_H
