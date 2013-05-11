#include "Background.h"

Background::Background(SDL_Surface *screen)
{
    this->screen = screen;
   this->background[0] = IMG_Load( "menu.png" );
    this->background[1] = IMG_Load( "Fondo/background.png" );
    this->x = 0;
    this->numPantalla=0;
}

Background::~Background()
{
    SDL_FreeSurface( background[0] );
    SDL_FreeSurface( background[1] );
}

void Background::logic()
{
    x--;
}

void Background::setInicio(int i){
    this->numPantalla=i;

}

int Background::getInicio(){

    return numPantalla;
}

void Background::render()
{
    SDL_Rect offset;

    if(getInicio()==0){
            if(x<-background[0]->w)
            x=0;
            offset.x = x;
            offset.y = 0;

            SDL_BlitSurface( background[0], NULL, screen, &offset );

            offset.x = x+background[0]->w;
            offset.y = 0;

            SDL_BlitSurface( background[0], NULL, screen, &offset );

    }else if(getInicio()==1){

            if(x<-background[1]->w)
            x=0;
            offset.x = x;
            offset.y = 0;

            SDL_BlitSurface( background[1], NULL, screen, &offset );

            offset.x = x+background[1]->w;
            offset.y = 0;

            SDL_BlitSurface(background[1], NULL, screen, &offset );
    }


}
