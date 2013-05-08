#include "Player.h"

Player::Player(SDL_Surface *screen)
{
    this->screen = screen;
    this->images[0] = IMG_Load( "player/1.png" );
    this->images[1] = IMG_Load( "player/2.png" );
    this->images[2] = IMG_Load( "player/3.png" );
    this->images[3] = IMG_Load( "player/4.png" );
    this->images[4] = IMG_Load( "player/jump.png" );
    this->x = 200;
    this->y = 0;
    this->acceleration=2;
    this->velocity=0;
    this->current_frame=0;
}

Player::~Player()
{
    SDL_FreeSurface( images[0] );
    SDL_FreeSurface( images[1] );
    SDL_FreeSurface( images[2] );
    SDL_FreeSurface( images[3] );
    SDL_FreeSurface( images[4] );
}

void Player::logic()
{
    y+=velocity;
    velocity+=acceleration;
    if(y>=500-images[current_frame]->w/2)
    {
        y=500-images[current_frame]->w/2;
        velocity=0;
    }


}


void Player::jump()
{
    current_frame=3;
    velocity=-30;
}

void Player::render()
{
    SDL_Rect offset;

    offset.x = x - images[current_frame]->w/2;
    offset.y = y - images[current_frame]->h/2;

    SDL_BlitSurface( images[current_frame], NULL, screen, &offset );

    current_frame++;
     if (current_frame > 3 && this->velocity<0){
        this->current_frame = 4;
        offset.x = x - images[current_frame]->w/2;
        offset.y = y - images[current_frame]->h/2;

        SDL_BlitSurface( images[4], NULL, screen, &offset );
        this->velocity++;

    }
    else if(current_frame>3)
            current_frame=0;
}
