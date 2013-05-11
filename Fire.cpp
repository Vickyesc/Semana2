#include "Fire.h"

Fire::Fire(SDL_Surface *screen)
{
    this->screen = screen;
    this->images[0] = IMG_Load( "assets/llama01.png" );
    this->images[1] = IMG_Load( "assets/llama02.png" );
    this->images[2] = IMG_Load( "assets/llama03.png" );
    this->x = 1500;
    this->y = 350;
    this->acceleration=2;
    this->velocity=0;
    this->current_frame=0;
}

Fire::~Fire()
{
    SDL_FreeSurface( images[0] );
    SDL_FreeSurface( images[1] );
    SDL_FreeSurface( images[2] );
    SDL_FreeSurface( images[3] );
}

void Fire::logic(){
      x-=10;
    if(x<-100)
        x=1000;

}

void Fire::jump(){

    velocity=-300;
}

void Fire::render(){

    SDL_Rect offset;

    offset.x = x - images[current_frame]->w/2;
    offset.y = y - images[current_frame]->h/2;

    SDL_BlitSurface( images[current_frame], NULL, screen, &offset );

    current_frame++;
    if(current_frame>2)
        current_frame=0;
}
