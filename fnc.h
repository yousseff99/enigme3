#ifndef FNC_H_
#define FNC_H_

typedef struct image
{
	SDL_Surface *background;
	SDL_Rect posPicture;
}image;
typedef struct
{
    char schema[500][500];
    int nb;
}annimation;



image init_image(char nameofpicture[100],int x,int y);
void affichage(SDL_Surface *ecran,image img);
void Music_enigme();
void sound_door();
void sound_clock();
void sound_win();
void sound_correct();
void sound_wrong();
int verif_enigme();
void librer_image(image img);

annimation init_annimation(annimation image,int j,char schema[400]);
void afficher_annimation(annimation image,SDL_Surface *ecran);
#endif
