
#include <stdio.h>

#ifndef ACTIVE_PHASE
#define ACTIVE_PHASE 1
#endif

void run_phase1(void);
void run_phase2(void);
void run_phase3(void);
void run_phase4(void);
void run_phase5(void);
void run_phase6(void);

int main(void) {
    printf("GestAcad - Projet C (Phase %d)\n\n", ACTIVE_PHASE);
#if   ACTIVE_PHASE == 1
    run_phase1();
#elif ACTIVE_PHASE == 2
    run_phase2();
#elif ACTIVE_PHASE == 3
    run_phase3();
#elif ACTIVE_PHASE == 4
    run_phase4();
#elif ACTIVE_PHASE == 5
    run_phase5();
#elif ACTIVE_PHASE == 6
    run_phase6();
#else
    printf("ACTIVE_PHASE invalide. Utilisez 1..6.\n");
#endif
    return 0;
}
