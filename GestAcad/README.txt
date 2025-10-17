GestAcad (Code::Blocks - un seul projet)

Contenu :
- GestAcad.cbp : projet Code::Blocks
- main.c       : point d'entrée, sélection de la phase via la macro ACTIVE_PHASE
- phase1.c..phase6.c : implémentations des différentes phases

Comment changer de phase :
1) Ouvrez main.c
2) Modifiez la ligne : #define ACTIVE_PHASE 1  (mettez 1..6)
3) F9 (Build & Run)

Notes :
- Les fichiers phase*.c ne contiennent PAS de main(); chacun expose run_phaseX().
- Les données de la phase 5/6 sont sauvegardées dans etudiants.txt (même dossier).
