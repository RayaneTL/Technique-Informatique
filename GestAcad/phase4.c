
#include <stdio.h>
#include <string.h>

#define MAX_ETU 10
#define MAX_NOM 30
#define MAX_NOTES 3

static void ajouter(char prenoms[][MAX_NOM], char noms[][MAX_NOM], float notes[][MAX_NOTES], int *nb) {
    if (*nb >= MAX_ETU) { printf("Max atteint.\n"); return; }
    printf("Prenom: "); scanf("%29s", prenoms[*nb]);
    printf("Nom: ");    scanf("%29s", noms[*nb]);
    for (int j=0;j<MAX_NOTES;j++) { printf("Note %d /20: ", j+1); scanf("%f", &notes[*nb][j]); }
    (*nb)++;
}

static float calculer_moyenne(float notes[MAX_NOTES]) {
    float s=0; for (int j=0;j<MAX_NOTES;j++) s+=notes[j]; return s/3.f;
}

static void afficher(const char prenoms[][MAX_NOM], const char noms[][MAX_NOM], float notes[][MAX_NOTES], int nb) {
    for (int i=0;i<nb;i++) printf("%s %s | moy=%.2f\n", prenoms[i], noms[i], calculer_moyenne(notes[i]));
}

static void trier_prenom(char prenoms[][MAX_NOM], char noms[][MAX_NOM], float notes[][MAX_NOTES], int nb) {
    for (int i=0;i<nb-1;i++)
        for (int k=i+1;k<nb;k++)
            if (strcmp(prenoms[i], prenoms[k])>0) {
                char tp[MAX_NOM], tn[MAX_NOM]; float tnotes[MAX_NOTES];
                strcpy(tp, prenoms[i]); strcpy(prenoms[i], prenoms[k]); strcpy(prenoms[k], tp);
                strcpy(tn, noms[i]);    strcpy(noms[i], noms[k]);       strcpy(noms[k], tn);
                for (int j=0;j<MAX_NOTES;j++){ tnotes[j]=notes[i][j]; notes[i][j]=notes[k][j]; notes[k][j]=tnotes[j]; }
            }
}

void run_phase4(void) {
    char prenoms[MAX_ETU][MAX_NOM] = {{0}};
    char noms[MAX_ETU][MAX_NOM] = {{0}};
    float notes[MAX_ETU][MAX_NOTES] = {{0}};
    int nb=0, choix;

    while (1) {
        printf("\nPhase 4 - Modularisation & pointeurs\n");
        printf("1) Ajouter\n2) Afficher\n3) Trier prenom\n4) Quitter\nChoix: ");
        if (scanf("%d", &choix) != 1) return;
        if (choix==1) ajouter(prenoms,noms,notes,&nb);
        else if (choix==2) afficher(prenoms,noms,notes,nb);
        else if (choix==3) trier_prenom(prenoms,noms,notes,nb);
        else if (choix==4) break;
    }
}
