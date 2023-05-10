#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

#include "sauvegarde.h"


int main(int argc, char const *argv[])
{
SDL_Surface *menu[2];
int choix=1;


menu[0]=IMG_Load("save0.png");
menu[1]=IMG_Load("save.png");
perso p;
back b;


p.rect.x=200;
p.rect.y=100;
p.possprite.x=1;
p.possprite.y=1;
p.direction=1;
p.X=1;
p.Y=1;
b.pos.y=299;
b.pos.x=1111;
b.pos2.y=299;
b.pos2.x=1111;


  SDL_Init(SDL_INIT_VIDEO);
  SDL_Surface * screen;
  screen = SDL_SetVideoMode(1000, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

  SDL_WM_SetCaption("menu\t1", NULL); 


int continuer=1;
  SDL_Event event;
while (continuer)
{
   while (SDL_PollEvent( & event)) {
       switch (event.type)
       {
       case SDL_QUIT:
           continuer=0;
           break;
       
       case SDL_KEYDOWN:
       if (event.key.keysym.sym== SDLK_RETURN) 
       {
           
          
           switch (choix)
           {
           case 0:
               sauvegarder(p,b);
               break;
            case 1:
                charger(&p,&b);
                printf("\nperso %d -- %d\n",p.rect.x,p.rect.y);
                printf("\nback %d -- %d\n",b.pos.x,b.pos.y);
            break;              
           }
           SDL_Delay(1000);
           continuer=0;
       }
       else
       choix=(choix+1)%2;
       break;
      
       }
   }

   SDL_BlitSurface(menu[choix],NULL,screen,NULL);



SDL_Flip(screen);
SDL_Delay(100);

}


    return 0;
}
