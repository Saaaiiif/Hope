prog: main.o sauvegarde.o
	gcc  main.o sauvegarde.o -o prog -lSDL -lSDL_ttf -lSDL_mixer -lSDL_image 
main.o:main.c
	gcc -c main.c
sauvegarde.o: sauvegarde.c
	gcc -c sauvegarde.c
