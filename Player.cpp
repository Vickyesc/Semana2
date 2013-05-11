#include "Player.h"

Player::Player(SDL_Surface *screen)
{
    this->screen = screen;
    this->images[0] = IMG_Load( "player/1.png" );
    this->images[1] = IMG_Load( "player/2.png" );
    this->images[2] = IMG_Load( "player/3.png" );
    this->images[3] = IMG_Load( "player/4.png" );
    this->images[4] = IMG_Load( "player/jump.png" );
    this->images[5] = IMG_Load( "perder01.png" );
    this->images[6] = IMG_Load( "perder02.png" );
    this->images[7] = IMG_Load( "perder03.png" );
    this->images[8] = IMG_Load( "perder04.png" );
    this->images[9] = IMG_Load( "perder05.png" );
    this->x = 200;
    this->y = 0;
    this->acceleration=2;
    this->velocity=0;
    this->current_frame=0;
    this->isJump=false;
}

Player::~Player()
{
    SDL_FreeSurface( images[0] );
    SDL_FreeSurface( images[1] );
    SDL_FreeSurface( images[2] );
    SDL_FreeSurface( images[3] );
    SDL_FreeSurface( images[4] );
    SDL_FreeSurface( images[5] );
    SDL_FreeSurface( images[6] );
    SDL_FreeSurface( images[7] );
    SDL_FreeSurface( images[8] );
    SDL_FreeSurface( images[9] );
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
    current_frame=4;
    velocity=-30;
}

void Player::render(){
    SDL_Rect offset;

    offset.x = x - images[current_frame]->w/2;
    offset.y = y - images[current_frame]->h/2;

    SDL_BlitSurface( images[current_frame], NULL, screen, &offset );

    if (current_frame >4){

            this->current_frame++;


        }else if ( (current_frame == 4 && this->velocity<0)||(current_frame == 4 && this->y<372)){
            this->current_frame--;
            this->isJump = true;

    }else if(current_frame>3){
            current_frame=0;
            isJump=false;
    }

        current_frame++;
      if (current_frame>=5){
             current_frame=9;
            this->seMurio = true;

       }


}

void Player::perder(){
    current_frame=5;

}

void Player::choco(int x, int y){
      if(this->x-x<50 && this->x-x>-50 && this->y-y<50 && this->y-y>-50)
        this->perder();

}


