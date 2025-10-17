#include <stdio.h>
#include <math.h>

void run_phase1(void) {
    char prenom_input[64];
    char initiale;
    int age;
    float n1, n2, n3;

    printf("Phase 1 - Saisie et calculs\n");


    printf("Initiale du prenom : ");
    if (scanf(" %63s", prenom_input) != 1) return;
    initiale = prenom_input[0];

    printf("Age (entier) : ");
    if (scanf("%d", &age) != 1) return;

    printf("Note 1  /20 : ");
    if (scanf("%f", &n1) != 1) return;
    printf("Note 2  /20 : ");
    if (scanf("%f", &n2) != 1) return;
    printf("Note 3  /20 : ");
    if (scanf("%f", &n3) != 1) return;

    float p1 = (n1 / 20.f) * 100.f;
    float p2 = (n2 / 20.f) * 100.f;
    float p3 = (n3 / 20.f) * 100.f;

    float d1 = roundf((n1 / 20.f) * 10.f * 10.f) / 10.f;
    float d2 = roundf((n2 / 20.f) * 10.f * 10.f) / 10.f;
    float d3 = roundf((n3 / 20.f) * 10.f * 10.f) / 10.f;

    float moyenne = (n1 + n2 + n3) / 3.f;
    int moyenne_arr = (int)lrintf(moyenne);

    printf("\n--- Récapitulatif ---\n");
    printf("Initiale : %c | Age : %d\n", initiale, age);
    printf("Notes /20 : %.2f, %.2f, %.2f\n", n1, n2, n3);
    printf("Pourcentages : %.1f%%, %.1f%%, %.1f%%\n", p1, p2, p3);
    printf("Notes /10 (1 decimale) : %.1f, %.1f, %.1f\n", d1, d2, d3);
    printf("Moyenne /20 : %.2f -> arrondie : %d\n", moyenne, moyenne_arr);
}
