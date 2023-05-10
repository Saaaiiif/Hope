#include "sauvegarde.h"
void sauvegarder(perso p, back b) {
    FILE* fichier;
    
    // Sauvegarde du personnage
    fichier = fopen("../save_perso.txt", "w");
    if (fichier != NULL) {
        fprintf(fichier, "%d,%d,%d,%d,%f,%f\n", p.rect.x, p.rect.y, p.possprite.x, p.possprite.y, p.X, p.Y);
        fclose(fichier);
        printf("Personnage sauvegardé.\n");
    }
    else {
        printf("Impossible de sauvegarder le personnage.\n");
    }
    
    // Sauvegarde du fond
    fichier = fopen("../save_back.txt", "w");
    if (fichier != NULL) {
        fprintf(fichier, "%d,%d,%d,%d\n", b.pos.x, b.pos.y, b.pos2.x, b.pos2.y);
        fclose(fichier);
        printf("Fond sauvegardé.\n");
    }
    else {
        printf("Impossible de sauvegarder le fond.\n");
    }
}

int charger(perso* p, back* b) {
    FILE* fichier;
    
    // Chargement du personnage
    fichier = fopen("../save_perso.txt", "r");
    if (fichier != NULL) {
        fscanf(fichier, "%d,%d,%d,%d,%f,%f", &(p->rect.x), &(p->rect.y), &(p->possprite.x), &(p->possprite.y), &(p->X), &(p->Y));
        fclose(fichier);
        printf("Personnage chargé.\n");
    }
    else {
        printf("Impossible de charger le personnage.\n");
        return 0;
    }
    
    // Chargement du fond
    fichier = fopen("../save_back.txt", "r");
    if (fichier != NULL) {
        fscanf(fichier, "%d,%d,%d,%d", &(b->pos.x), &(b->pos.y), &(b->pos2.x), &(b->pos2.y));
        fclose(fichier);
        printf("Fond chargé.\n");
    }
    else {
        printf("Impossible de charger le fond.\n");
        return 0;
    }
    
    return 1;
}





