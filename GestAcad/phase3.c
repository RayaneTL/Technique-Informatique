
#include <stdio.h>
#include <string.h>

#define MAX_ETU 10
#define MAX_NOM 30
#define MAX_NOTES 3

void run_phase3(void) {
    char prenoms[MAX_ETU][MAX_NOM] = {{0}};
    char noms[MAX_ETU][MAX_NOM] = {{0}};
    float notes[MAX_ETU][MAX_NOTES] = {{0}};
    int nb = 0;
    int choix;

    while (1) {
        printf("\nPhase 3 - Tableaux & chaines\n");
        printf("1) Ajouter etudiant\n");
        printf("2) Afficher\n");
        printf("3) Trier par prenom (bonus)\n");
        printf("4) Quitter\n");
        printf("Choix: ");
        if (scanf("%d", &choix) != 1) { return; }

        if (choix == 1) {
            if (nb >= MAX_ETU) { printf("Max atteint.\n"); continue; }
            printf("Prenom: "); scanf("%29s", prenoms[nb]);
            printf("Nom: ");    scanf("%29s", noms[nb]);
            for (int j=0;j<MAX_NOTES;j++) {
                printf("Note %d /20: ", j+1);
                scanf("%f", &notes[nb][j]);
            }
            nb++;
        } else if (choix == 2) {
            for (int i=0;i<nb;i++) {
                float s=0; for (int j=0;j<MAX_NOTES;j++) s+=notes[i][j];
                printf("%s %s | moy=%.2f\n", prenoms[i], noms[i], s/3.f);
            }
        } else if (choix == 3) {
            for (int i=0;i<nb-1;i++) {
                for (int k=i+1;k<nb;k++) {
                    if (strcmp(prenoms[i], prenoms[k])>0) {
                        char tp[MAX_NOM], tn[MAX_NOM];
                        float tnotes[MAX_NOTES];
                        strcpy(tp, prenoms[i]); strcpy(prenoms[i], prenoms[k]); strcpy(prenoms[k], tp);
                        strcpy(tn, noms[i]);    strcpy(noms[i], noms[k]);       strcpy(noms[k], tn);
                        for (int j=0;j<MAX_NOTES;j++){ tnotes[j]=notes[i][j]; notes[i][j]=notes[k][j]; notes[k][j]=tnotes[j]; }
                    }
                }
            }
            printf("Trie par prenom effectue.\n");
        } else if (choix == 4) break;
    }
}
