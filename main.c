#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fnc.h"

int main()
{
    char *phrase,* mot;
    int continuer=1,clic=0,win=0;
    SDL_Event event;
    SDL_Init(SDL_INIT_VIDEO); 
    SDL_Surface *ecran =NULL,*zoneSaisie=NULL;
    TTF_Font *police = NULL;
    SDL_Color blanc = {255, 255, 255};//couleur blancrgb
    TTF_Init();
    police = TTF_OpenFont("font/font.ttf",50);
    ecran=SDL_SetVideoMode(562, 903, 32, SDL_HWSURFACE); 
    SDL_Rect poszoneSaisie;
    poszoneSaisie.x=220;
    poszoneSaisie.y=260;
    SDL_WM_SetCaption("Enigme Youssef", NULL); 
    mot=calloc(6,sizeof(char));
    phrase=calloc(20,sizeof(char));
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)==-1){printf("%s",Mix_GetError());}
////////////////////////////////////////////////////
    image background,clock23;
    background=init_image("images/clock/1.png",0,0);
    affichage(ecran,background);
    clock23=init_image("images/clock/21.png",0,0);

    annimation clock,door;
    clock=init_annimation(clock,21,"images/clock");
    door=init_annimation(door,23,"images/door");
    //////////////////////////////////
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT)
            {

                if((event.button.x >415 && event.button.y >280 && event.button.x <517 && event.button.y <376)&&clic==0)
                {
                clic=1;
                printf("click clock !\n");
                sound_clock();
                afficher_annimation(clock,ecran);
                }

                if((event.button.x >415 && event.button.y >180 && event.button.x <484 && event.button.y <250)&&clic==1)
                {
                clic=0;
                affichage(ecran,background); 
                printf("Exit clock !\n");
                }
            }break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_RETURN:
            {
            if(win==0&&clic==1)
            {  
                if(strcmp(phrase,"732541")==0)//732541
                {
                sound_correct();printf("win\n");win=1;
                }
              else{sound_wrong();memset(phrase,0,sizeof(char));phrase=calloc(20,sizeof(char));printf("False Enigme 1\n");}
            }
            }break;
            case SDLK_BACKSPACE:
                printf("Effacer\n");
                int casee = 0,longeur;
                longeur=strlen(phrase);
                longeur--;
                while(phrase[casee] != '\0')
                {
                    if(casee >=longeur)
                    {
                        phrase[casee] = phrase[casee+1];
                    }
                    casee++;
                }
                break;
            case SDLK_KP0:
                strcpy(mot,"0");
                if(strlen(phrase)<6){strcat(phrase,mot);printf("0\n");}
                break;
            case SDLK_KP1:
                strcpy(mot,"1");
                if(strlen(phrase)<6){strcat(phrase,mot);printf("1\n");}
                break;
            case SDLK_KP2:
                strcpy(mot,"2");
                if(strlen(phrase)<6){strcat(phrase,mot);printf("2\n");}
                break;
            case SDLK_KP3:
                strcpy(mot,"3");
                if(strlen(phrase)<6){strcat(phrase,mot);printf("3\n");}
                break;
            case SDLK_KP4:
                strcpy(mot,"4");
                if(strlen(phrase)<6){strcat(phrase,mot);printf("4\n");}
                break;
            case SDLK_KP5:
                strcpy(mot,"5");
                if(strlen(phrase)<6){strcat(phrase,mot);printf("5\n");}
                break;
            case SDLK_KP6:
                strcpy(mot,"6");
                if(strlen(phrase)<6){strcat(phrase,mot);printf("6\n");}
                break;
            case SDLK_KP7:
                strcpy(mot,"7");
                if(strlen(phrase)<6){strcat(phrase,mot);printf("7\n");}
                break;
            case SDLK_KP8:
                strcpy(mot,"8");
                if(strlen(phrase)<6){strcat(phrase,mot);printf("8\n");}
                break;
            case SDLK_KP9:
                strcpy(mot,"9");
                if(strlen(phrase)<6){strcat(phrase,mot);printf("9\n");}
                break;
                //////////alphabet//////////
            case SDLK_c:
                strcpy(mot,"c");
                if(strlen(phrase)<6){strcat(phrase,mot);printf("c\n");}
                break;
         }
     }
            if(clic==1&&win==0)
            {
            //affichage(ecran,clock23);
            zoneSaisie=TTF_RenderText_Blended(police,phrase,blanc);
            SDL_BlitSurface(zoneSaisie,NULL,ecran,&poszoneSaisie);
            SDL_Flip(ecran); 
            }
            if(win==1)
             {
              sound_door();
              afficher_annimation(door,ecran);
              win=2;
             }
            SDL_Flip(ecran);                  
    } 
    TTF_CloseFont(police);
    SDL_Quit(); // Arrêt de la SDL
    librer_image(background);
    SDL_FreeSurface(zoneSaisie);
   
    return win; 
}
//awil jeuw win=0
//és7i7 win ==1 animation porte
// on est dans boucle while la porte to93d tt7al alor on fait win==2






