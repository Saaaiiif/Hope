#ifndef FONCTIONS_H_
#define FONCTIONS_H_
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
//les structs a importer pas a declarer
typedef struct perso
{


SDL_Surface *personnage; //taswirt joueur
SDL_Rect rect;//position mtaa joueur
SDL_Rect possprite; // position d frame dans le spritesheet
int direction; // 0 droite ,,, 1 gauche
float X,Y;//vitesse horizontale et verticale

}perso;

typedef struct back
{
  SDL_Surface *img ;
  SDL_Rect pos,pos2 ; 

}back;




void sauvegarder (perso p,back b) ; 
int charger (perso *p,back *b );


#endif
