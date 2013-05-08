#include "Inicio.h"

Inicio::Inicio(SDL_Surface *screen)
{
   this->screen = screen;
    this->image = IMG_Load( "menu.png" );
    this->x = 0;
}

Inicio::~Inicio()
{
   SDL_FreeSurface( image );
}

void Inicio::logic(){
      x--;
}

void Inicio::render(){

     SDL_Rect offset;

    if(x<-image->w)
        x=0;
    offset.x = x;
    offset.y = 0;

    SDL_BlitSurface( image, NULL, screen, &offset );

    offset.x = x+image->w;
    offset.y = 0;

    SDL_BlitSurface( image, NULL, screen, &offset );

}
