#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "fnc.h"

image init_image(char nameofpicture[100],int x,int y)
{
image image;
image.background=IMG_Load(nameofpicture);
image.posPicture.x=x;
image.posPicture.y=y;
return image;
}
void affichage(SDL_Surface *ecran,image image)
{
SDL_BlitSurface(image.background,NULL,ecran,&image.posPicture);
}

void librer_image(image image)
{
 SDL_FreeSurface(image.background);//Liberer memoire
}


annimation init_annimation(annimation image,int j,char schema[400])
{
    image.nb=j;
    int i;

    for(i=1; i<=j; i++)
    {
        strcpy(image.schema[i],schema);//21 photo copie chemin de chaque photo dans le tab
    }
    return image;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void afficher_annimation(annimation image,SDL_Surface *ecran)
{
    SDL_Surface *Menu_[500];
    int j;
    char menu[400];

    for (j=1; j<=image.nb; j++)
    {
        sprintf(menu,"%s/%d.png",image.schema[j]/*chemin images/clock*/,j);
        Menu_[j]=IMG_Load(menu);
        SDL_BlitSurface(Menu_[j],NULL,ecran,NULL);
        SDL_Flip(ecran);
        SDL_FreeSurface(Menu_[j]);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sound_clock()
{
Mix_Chunk *clock;
clock = Mix_LoadWAV("sound/clock.wav"); 
Mix_PlayChannel(1,clock,0);  
}

void sound_door()
{
Mix_Chunk *door;
door = Mix_LoadWAV("sound/door.wav"); 
Mix_PlayChannel(1,door,0);
}

void sound_correct()
{
Mix_Chunk *correct;
correct = Mix_LoadWAV("sound/correct.wav"); 
Mix_PlayChannel(1,correct,0);
}

void sound_wrong()
{
Mix_Chunk *wrong; 
    
    wrong = Mix_LoadWAV("sound/wrong.wav");
Mix_PlayChannel(1,wrong,0);

}

void sound_win()
{
Mix_Chunk *soundwin; 
soundwin= Mix_LoadWAV("sound/win.wav");
Mix_PlayChannel(1,soundwin,0);

}


