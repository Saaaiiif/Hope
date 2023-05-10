#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "enigmetf.h"

int main()
{
	
	SDL_Surface * ecran=NULL;
	ecran = SDL_SetVideoMode(1200,1000, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	int continuer=1;
	SDL_Event event;
	char *nomfichier[100];
        int a=0;
	enigmetf e;
    
	InitEnigme(&e,&nomfichier[100]);


	while(continuer){	
       a = (clock() / 100000) % 4;
        afficherEnigme(e,ecran);
      
		while (SDL_PollEvent(&event)) 
		{
			switch (event.type)
			{
				case SDL_QUIT:
				{	
					free_Surface_enigme(e);

				}
				case SDL_MOUSEMOTION:
				{
					printf("Souris en position %d %d\n",event.motion.x, event.motion.y);
				}
				case SDL_MOUSEBUTTONUP:
				{
					if((event.motion.x>375 && event.motion.x<615)&&(event.motion.y>520 && event.motion.y<610))
					{
						e.pos_selected=1;
						if (event.button.button == SDL_BUTTON_LEFT)
						{
							verify_enigme(&e,ecran); 
							return 0;
						} 	 
					}
					else if((event.motion.x>178 && event.motion.x<411)&&(event.motion.y>649 && event.motion.y<734))
					{
						e.pos_selected=2;
						if (event.button.button == SDL_BUTTON_LEFT)
						{
							verify_enigme(&e,ecran); 
							return 0;
						} 
					}
					else if((event.motion.x>568 && event.motion.x<800)&&(event.motion.y>656 && event.motion.y<731))
					{
						e.pos_selected=3;
						if (event.button.button == SDL_BUTTON_LEFT)
						{
							verify_enigme(&e,ecran); 
							return 0;
						} 					
					}
				}
				break;
			}
		}
	}
}



