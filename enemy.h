#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
typedef enum {
    Waiting,
    Following,
    Attacking
} EnemyState;
struct enemy
{
SDL_Rect position;
SDL_Surface *imgR[11]; 
SDL_Surface *imgL[11];
int direction;
int frame;


};
typedef struct enemy enemy;

struct Ennemi2{
        SDL_Rect positionAbsolue;
	SDL_Rect positionAnimation;
SDL_Rect positionAnimation2;
	SDL_Surface * image;
     	EnemyState state;
	
};
typedef struct Ennemi2 Ennemi2;

void init(enemy *e);

void afficher(enemy *e,SDL_Surface *ecran);
void move1(enemy *e);
void move2(enemy *e);
void destruct(enemy *e);
void blitEnnemi2(Ennemi2 E, SDL_Surface screen);

int loadEnnemiImages2(Ennemi2 * E);
void initEnnemi2(Ennemi2 *E);
void MoveEnnemi1(Ennemi2 *E);
void MoveEnnemi22(Ennemi2 *E);
void freeEnnemi2(Ennemi2 *E);

int collisionBB(SDL_Rect posp, SDL_Rect pose);
void animateEnnemi(Ennemi2* E);
void moveEnnemi(Ennemi* E, SDL_Rect posHero);

void updateEnnemiState(Ennemi* E, int distEH);

#endif // ENEMY_H_INCLUDED
