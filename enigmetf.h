#ifndef ENIGMETF_H_INCLUDED
#define ENIGMETF_H_INCLUDED

#include <stdio.h> 
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <SDL/SDL_mixer.h>
typedef struct{ 

        SDL_Surface *background;
	SDL_Surface *question;
	SDL_Surface *reponses[4]; 
	SDL_Surface *button;
	SDL_Surface *button_s;

        SDL_Rect pos1; 
        SDL_Surface *img;

	int pos_selected; 
	SDL_Rect pos_question; 
	SDL_Rect pos_reponse1;
	SDL_Rect pos_reponse2;
	SDL_Rect pos_reponse3;
	int num_question;
	Mix_Music* bgmusic;
	SDL_Rect pos_reponse1txt;
	SDL_Rect pos_reponse2txt; 
	SDL_Rect pos_reponse3txt;
	int vrai_reponse;
	int positionVraiReponse; 
	TTF_Font *police; 
	TTF_Font *police1;

}enigmetf;

void InitEnigme(enigmetf *e,char *nomfichier[]);
void afficherEnigme(enigmetf e,SDL_Surface *ecran);
void verify_enigme(enigmetf *e,SDL_Surface*ecran);
void animer(enigmetf *e, char path[], float x, float y, SDL_Surface *ecran);
void free_Surface_enigme(enigmetf e);

#endif
