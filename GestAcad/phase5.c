
#include <stdio.h>
#include <string.h>

#define MAX_ETU 100
#define MAX_NOM 30
#define MAX_NOTES 3

typedef struct {
    char prenom[MAX_NOM];
    char nom[MAX_NOM];
    float notes[MAX_NOTES];
} Etudiant;

static void charger(const char* file, Etudiant tab[], int* nb) {
    FILE* f = fopen(file, "r");
    *nb = 0;
    if (!f) return;
    while (fscanf(f, "%29s %29s %f %f %f", tab[*nb].prenom, tab[*nb].nom,
                  &tab[*nb].notes[0], &tab[*nb].notes[1], &tab[*nb].notes[2]) == 5) {
        (*nb)++;
        if (*nb >= MAX_ETU) break;
    }
    fclose(f);
}

static void sauvegarder(const char* file, const Etudiant tab[], int nb) {
    FILE* f = fopen(file, "w");
    if (!f) { printf("Impossible d'ecrire %s\n", file); return; }
    for (int i=0;i<nb;i++)
        fprintf(f, "%s %s %.2f %.2f %.2f\n", tab[i].prenom, tab[i].nom,
                tab[i].notes[0], tab[i].notes[1], tab[i].notes[2]);
    fclose(f);
}

static float moyenne(const Etudiant* e){ return (e->notes[0]+e->notes[1]+e->notes[2])/3.f; }

void run_phase5(void) {
    const char* fichier = "etudiants.txt";
    Etudiant tab[MAX_ETU];
    int nb=0, choix;

    charger(fichier, tab, &nb);
    printf("Charges: %d etudiants.\n", nb);

    while (1) {
        printf("\nPhase 5 - Struct & fichiers\n");
        printf("1) Ajouter\n2) Afficher\n3) Sauvegarder\n4) Quitter\nChoix: ");
        if (scanf("%d", &choix) != 1) return;
        if (choix==1) {
            if (nb >= MAX_ETU) { printf("Max atteint.\n"); continue; }
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
}
