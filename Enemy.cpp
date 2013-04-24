#include "Enemy.h"

Enemy::Enemy(SDL_Surface *screen)
{
    this->screen = screen;
    this->images[0] = IMG_Load( "enemy/1.png" );
    this->images[1] = IMG_Load( "enemy/2.png" );
    this->images[2] = IMG_Load( "enemy/3.png" );
    this->images[4] = IMG_Load( "enemy/llama01.png" );
    this->images[5] = IMG_Load( "enemy/llama02.png");
    this->images[6] = IMG_Load( "enemy/llama03.png" );
    this->x = 1000;
    this->y = 400;
    this->acceleration=2;
    this->velocity=0;
    this->current_frame=0;
}

Enemy::~Enemy()
{
    SDL_FreeSurface( images[0] );
    SDL_FreeSurface( images[1] );
    SDL_FreeSurface( images[2] );
    SDL_FreeSurface( images[3] );
    SDL_FreeSurface( images[4] );
    SDL_FreeSurface( images[5] );
    SDL_FreeSurface( images[6] );

}

void Enemy::logic()
{
    x-=10;
    if(x<-100)
        x=1000;
}

void Enemy::jump()
{
    velocity=-30;
}

void Enemy::render()
{
    SDL_Rect offset;

    offset.x = x - images[current_frame]->w/2;
    offset.y = y - images[current_frame]->h/2;
    SDL_BlitSurface( images[current_frame], NULL, screen, &offset );

    current_frame++;
      if(current_frame>2)
        current_frame=0;
}
