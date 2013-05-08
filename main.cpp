/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/

//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "Background.h"
#include "Player.h"
#include "Enemy.h"
#include "Timer.h"
#include <string>
#include "Fire.h"
#include "Inicio.h"

//Screen attributes
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 500;
const int SCREEN_BPP = 32;

SDL_Surface *screen = NULL;
Timer* update;

std::string toString(int number)
{
    if (number == 0)
        return "0";
    std::string temp="";
    std::string returnvalue="";
    while (number>0)
    {
        temp+=number%10+48;
        number/=10;
    }
    for (int i=0;i<(int)temp.length();i++)
        returnvalue+=temp[temp.length()-i-1];
    return returnvalue;
}



bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

       //Initialize SDL_mixer
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;
    }

    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //Set the window caption
    SDL_WM_SetCaption( "SDL Runner Lab Progra 3", NULL );

    //If everything initialized fine
    return true;
}

void frameCap()
{
    int frames_per_seccond = 15;
    if(update->get_ticks() < 1000 / frames_per_seccond)
    {
        //Sleep the remaining frame time
        SDL_Delay( ( 1000 / frames_per_seccond ) - update->get_ticks() );
    }
    update->start();
}

int main( int argc, char* args[] )
{
    //Initialize
    init();
    update=new Timer();
    update->start();

    int nota=0;
    int muerte = 0 ;


    SDL_Surface * explosion= IMG_Load( "perder04.png" );
    SDL_Surface * game_over = IMG_Load( "game_over.png" );


    TTF_Font *font = TTF_OpenFont( "lazy.ttf", 30 );
    SDL_Color textColor = { 0, 0, 0 };
    SDL_Surface * score_surface = NULL;

    Mix_Chunk *jump = Mix_LoadWAV( "jump.ogg" );
     Mix_Chunk *boom = Mix_LoadWAV( "explosion.ogg" );
    Mix_PlayChannel( -1, jump, 0 );
      Mix_PlayChannel( -1, boom, 0 );
    Mix_Music *music = NULL;


    Background background(screen);
    Player player(screen);
    Enemy enemy(screen);
    Fire fire(screen);

    SDL_Event event;
    //Quit flag
    bool quit = false;


     while (quit == false){
            Mix_HaltMusic();
        Mix_FreeMusic(music);
    music = NULL;
      if(music == NULL) {
    music = Mix_LoadMUS("intro.ogg");
      }
      Mix_PlayMusic(music, -1);


    while( quit == false )
    {
        //If there's an event to handle
        if( SDL_PollEvent( &event ) )
        {
            //If a key was pressed
            if( event.type == SDL_KEYDOWN )
            {
                //Set the proper message surface
                switch( event.key.keysym.sym )
                {
                    case SDLK_ESCAPE: quit = true; break;
                    case SDLK_UP:


                          player.jump();


                        break;

                }
            }
            //If the user has Xed out the window
            else if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }

        background.logic();
        player.logic();
        enemy.logic();
        fire.logic();


        SDL_Rect offset;
        offset.x = 0;
        offset.y = 0;
        int score;
        SDL_Surface * score_surface = TTF_RenderText_Solid( font, toString(score+=5).c_str(), textColor );
        SDL_BlitSurface( score_surface, NULL, screen, &offset );
        SDL_Flip( screen );
        SDL_FreeSurface( score_surface );

        if(player.x-enemy.x<50
           && player.x-enemy.x>-50
           && player.y-enemy.y<50
           && player.y-enemy.y>-50
           )
        {
           break;
        }

        if(player.x-fire.x<50
           && player.x-fire.x>-50
           && player.y-fire.y<50
           && player.y-fire.y>-50
           )
        {
           break;
        }

        background.render();
        player.render();
        enemy.render();
        fire.render();

        frameCap();

        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

    }

    while( quit == false )
    {
        //If there's an event to handle
        if( SDL_PollEvent( &event ) )
        {
            //If a key was pressed
            if( event.type == SDL_KEYDOWN )
            {
                //Set the proper message surface
                switch( event.key.keysym.sym )
                {
                    case SDLK_ESCAPE: quit = true; break;
                }
            }
            //If the user has Xed out the window
            else if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }

        SDL_Rect offset;
        offset.x = 0;
        offset.y = 0;

        SDL_BlitSurface( game_over, NULL, screen, &offset );

        frameCap();

        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }
    }

    //SDL_Quit();

    return 0;
}
}
