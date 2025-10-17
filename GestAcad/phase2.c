
#include <stdio.h>

#define MAX_NOTES 3

static void vider_buffer(void) {
    int c; while ((c = getchar()) != '\n' && c != EOF) {}
}

void run_phase2(void) {
    float notes[MAX_NOTES];
    int nb = 0;
    int choix;

    do {
        printf("\nPhase 2 - Menu (1 etudiant)\n");
        printf("1) Ajouter une note\n");
        printf("2) Voir statistiques\n");
        printf("3) Quitter\n");
        printf("Choix: ");
        if (scanf("%d", &choix) != 1) { vider_buffer(); continue; }

        if (choix == 1) {
            if (nb >= MAX_NOTES) {
                printf("Vous avez deja saisi %d notes.\n", MAX_NOTES);
            } else {
                float n;
                printf("Note /20: ");
                if (scanf("%f", &n) == 1) {
                    notes[nb++] = n;
                } else {
                    vider_buffer();
                }
            }
        } else if (choix == 2) {
            if (nb == 0) {
                printf("Aucune note saisie.\n");
            } else {
                float min = notes[0], max = notes[0], somme = 0.f;
                for (int i=0;i<nb;i++) {
                    if (notes[i] < min) min = notes[i];
                    if (notes[i] > max) max = notes[i];
                    somme += notes[i];
                }
                printf("Statistiques: nb=%d, min=%.2f, max=%.2f, moy=%.2f\n",
                       nb, min, max, somme/nb);
            }
        }
    } while (choix != 3);
}
