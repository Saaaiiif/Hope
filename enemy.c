#include "enemy.h"

void init(enemy *e)
{
e->imgR[0]=IMG_Load("1r.png");
e->imgR[1]=IMG_Load("2r.png");
e->imgR[2]=IMG_Load("3r.png");
e->imgR[3]=IMG_Load("4r.png");
e->imgR[4]=IMG_Load("5r.png");
e->imgR[5]=IMG_Load("6r.png");

e->imgL[0]=IMG_Load("1l.png");
e->imgL[1]=IMG_Load("2l.png");
e->imgL[2]=IMG_Load("3l.png");
e->imgL[3]=IMG_Load("4l.png");
e->imgL[4]=IMG_Load("5l.png");
e->imgL[5]=IMG_Load("6l.png");

e->position.x=580;
e->position.y=150;
e->direction=0;
e->frame=0;
}

/*int loadEnnemiImages2(Ennemi2 * E)
{
	E->image = IMG_Load("mini_map/ennemi_mini.png");

	if(E->image == NULL) {
		printf("Unable to load Ennemi :%s\n", SDL_GetError());
		return (-1);
	}

	

	return (0);
}*/

void initEnnemi2(Ennemi2* E)
{
	E->positionAbsolue.x = 500;
	E->positionAbsolue.y = 320;
	E->positionAbsolue.w = 270;
	E->positionAbsolue.h = 200;

}

void blitEnnemi2(Ennemi2 E, SDL_Surface screen)
{
	SDL_BlitSurface(E->image, NULL, screen, &(E->positionAbsolue));
}
void afficher(enemy *e,SDL_Surface *ecran)
{
SDL_Surface *img=NULL;
if(e->direction==1)
{

SDL_BlitSurface(e->imgR[e->frame],NULL,ecran,&(e->position));
//SDL_Flip(ecran);
//SDL_Delay(150);

e->frame++;
if(e->frame==6)
{
e->frame=0;
}

}
else
{
//SDL_BlitSurface(fond,NULL,ecran,&posfond);
SDL_BlitSurface(e->imgL[e->frame],NULL,ecran,&(e->position));
//SDL_Flip(ecran);
//SDL_Delay(150);
e->frame++;
if(e->frame==6)
{
e->frame=0;
}
}
}
	

/*void MoveEnnemi22(Ennemi2 *E)
{
       E->positionAbsolue.x -=0.0005;    
          if(E->positionAbsolue.x<=10)
            {
             
                E->positionAbsolue.x=10;
            }      
}
void MoveEnnemi1(Ennemi2 *E)
{
     E->positionAbsolue.x +=1;  
 if(E->positionAbsolue.x>=500)
            {
             
                E->positionAbsolue.x=500;
            }   
}*/

void move1(enemy *e)
{

	   e->direction=1;
e->position.x=e->position.x+1;
 if(e->position.x>=580)
            {
                e->direction=2;
                e->position.x=580;
            }
}


void move2(enemy *e)
{

e->position.x=e->position.x-1;
 if(e->position.x<300)
            {
                e->direction=1;
                move1(e);
            }

}
void freeEnnemi2(Ennemi2 *E)
{
	SDL_FreeSurface(E->image);
}
void destruct(enemy *e)
{
int i;
for(i=0;i<3;i++)
{
SDL_FreeSurface(e->imgR[i]);
SDL_FreeSurface(e->imgL[i]);
}
}
int collisionBB(SDL_Rect posp, SDL_Rect pose) {
    if (posp.x < pose.x + pose.w &&
        posp.x + posp.w > pose.x &&
        posp.y < pose.y + pose.h &&
        posp.y + posp.h > pose.y) {
        return 1;
    } else {
        return 0;
    }
}
int collisionBB(SDL_Rect posp, SDL_Rect pose) {
    if (posp.x < pose.x + pose.w &&
        posp.x + posp.w > pose.x &&
        posp.y < pose.y + pose.h &&
        posp.y + posp.h > pose.y) {
        return 1;
    } else {
        return 0;
    }
}
void animateEnnemi(Ennemi2* E) {
    int speed = 1;
    int frameIndex;
    switch (E->state) {
        case Waiting:
            frameIndex = 0;
            break;
        case Following:
            if (E->positionAbsolue.x > E->positionAnimation.x) {
                frameIndex = (E->positionAnimation.y == 0) ? 1 : 2;
            } else {
                frameIndex = (E->positionAnimation.y == 3) ? 10 : 9;
            }
            break;
        case Attacking:
            if (E->positionAbsolue.x > E->positionAnimation.x) {
                frameIndex = (E->positionAnimation.y == 2) ? 3 : 4;
            } else {
                frameIndex = (E->positionAnimation.y == 5) ? 8 : 7;
            }
            break;
        default:
            frameIndex = 0;
            break;
    }
    if (E->positionAbsolue.x > E->positionAnimation.x) {
        E->image = E->imgR[frameIndex];
    } else {
        E->image = E->imgL[frameIndex];
    }
    E->positionAnimation.x += speed;
    if (E->positionAnimation.x >= E->image->w) {
        E->positionAnimation.x = 0;
        E->positionAnimation.y++;
        if (E->positionAnimation.y >= 6) {
            E->positionAnimation.y = 0;
        }
    }
}
void moveEnnemi(Ennemi* E, SDL_Rect posHero) {
    int distanceThreshold = 100;
    int xEnnemi = E->position.x + E->position.w / 2;
    int xPerso = posHero.x + posHero.w / 2;
    int yEnnemi = E->position.y + E->position.h / 2;
    int yPerso = posHero.y + posHero.h / 2;
    float a = (float)(yPerso - yEnnemi) / (xPerso - xEnnemi);
    float b = yEnnemi - (a * xEnnemi);
    if (abs(xPerso - xEnnemi) <= distanceThreshold) {
        if (xPerso > xEnnemi) {
            E->position.x++;
            E->direction = 1;
        } else {
            E->position.x--;
            E->direction = 0;
        }
    }
}
void updateEnnemiState(Ennemi* E, int distEH) {
    int s1 = 200; // Seuil de transition de l'état Waiting à Following
    int s2 = 100; // Seuil de transition de l'état Following à Attacking
    
    switch (E->state) {
        case Waiting:
            if (distEH > s1) {
                E->state = Waiting;
            } else if (distEH > s2 && distEH <= s1) {
                E->state = Following;
            }
            break;
        case Following:
            if (distEH > s2 && distEH <= s1) {
                E->state = Following;
            } else if (distEH > 0 && distEH <= s2) {
                E->state = Attacking;
            }
            break;
        case Attacking:
            if (distEH > 0 && distEH <= s2) {
                E->state = Attacking;
            } else if (distEH <= 0) {
                E->state = Waiting;
            }
            break;
    }
}


