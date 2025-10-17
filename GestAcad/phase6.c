
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOM 30
#define MAX_NOTES 3

typedef struct {
    char prenom[MAX_NOM];
    char nom[MAX_NOM];
    float notes[MAX_NOTES];
} Etudiant;

static float moyenne(const Etudiant* e){ return (e->notes[0]+e->notes[1]+e->notes[2])/3.f; }

static void charger(const char* file, Etudiant** tab, int* nb, int* cap) {
    FILE* f = fopen(file, "r");
    *nb = 0; *cap = 0; *tab = NULL;
    if (!f) return;
    while (1) {
        Etudiant e; 
        int r = fscanf(f, "%29s %29s %f %f %f", e.prenom, e.nom,
                       &e.notes[0], &e.notes[1], &e.notes[2]);
        if (r != 5) break;
        if (*nb >= *cap) {
            *cap = (*cap==0)? 4 : (*cap*2);
            *tab = (Etudiant*)realloc(*tab, (*cap)*sizeof(Etudiant));
            if (!*tab) { fclose(f); fprintf(stderr,"Memoire insuffisante\n"); exit(1); }
        }
        (*tab)[*nb] = e;
        (*nb)++;
    }
    fclose(f);
}

static void sauvegarder(const char* file, const Etudiant* tab, int nb) {
    FILE* f = fopen(file, "w");
    if (!f) { printf("Impossible d'ecrire %s\n", file); return; }
    for (int i=0;i<nb;i++)
        fprintf(f, "%s %s %.2f %.2f %.2f\n", tab[i].prenom, tab[i].nom,
                tab[i].notes[0], tab[i].notes[1], tab[i].notes[2]);
    fclose(f);
}

void run_phase6(void) {
    const char* fichier = "etudiants.txt";
    Etudiant* tab = NULL;
    int nb=0, cap=0, choix;

    charger(fichier, &tab, &nb, &cap);
    printf("Charges: %d etudiants (cap=%d)\n", nb, cap);

    while (1) {
        printf("\nPhase 6 - Memoire dynamique\n");
        printf("1) Ajouter\n2) Afficher\n3) Sauvegarder\n4) Quitter\nChoix: ");
        if (scanf("%d", &choix) != 1) break;
        if (choix==1) {
            if (nb >= cap) {
                cap = (cap==0)? 4 : cap*2;
                tab = (Etudiant*)realloc(tab, cap*sizeof(Etudiant));
                if (!tab) { fprintf(stderr,"realloc echoue\n"); exit(1); }
            }
            printf("Prenom: "); scanf("%29s", tab[nb].prenom);
            printf("Nom: ");    scanf("%29s", tab[nb].nom);
            for (int j=0;j<MAX_NOTES;j++){ printf("Note %d /20: ", j+1); scanf("%f",&tab[nb].notes[j]); }
            nb++;
        } else if (choix==2) {
            for (int i=0;i<nb;i++) printf("%s %s | moy=%.2f\n", tab[i].prenom, tab[i].nom, moyenne(&tab[i]));
        } else if (choix==3) {
            sauvegarder(fichier, tab, nb);
            printf("Sauvegarde effectuee dans %s\n", fichier);
        } else if (choix==4) {
            sauvegarder(fichier, tab, nb);
            break;
        }
    }
    free(tab);
}
