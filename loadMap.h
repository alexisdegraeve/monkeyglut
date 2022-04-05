#ifndef _LOADMAP_
#define _LOADMAP_
#include <stdbool.h>

typedef struct Highscore {
 char *score;
}Highscore ;

// totalinecolumn: Function to calculate the number of rows and columns in the maplevel.txt
void totalinecolumn(int level);
// read_platform: Read the file maplevel.txt and put to the double pointer platform of char
int read_platform(int level);
// read_scores: Lire les scores du fichier scores.txt (Utiliser pour le Highscore)
int read_scores();
// write_scores: Ecrire les scores dans le fichier scores.txt (Utiliser pour le Highscore)
int write_scores();
// initializeEnemy: Parcours tous les ennemis (Liste chainée de structure Ennemi) et leurs affectent des valeurs par défault
void initializeEnemy(char type, int i, int j);
// initializeBubble: Initialize le tableau de bulle par défaut non actif
void initializeBubble();
// initialize_platform: Charge la map de la plateforme, Initialize la platforme en placant le singe au bon endroit,
//   les ennemis au bon endroit et initialize les bulles
void initialize_platform(int level);
// animateBulle: Animation des bulles
void animateBulle();
// animateEnemy: Animation de l'ennemi avec gestion de la vitesse et changement de sens s'il arrive au bord d'une plate-forme
void animateEnemy();
// animateMonkey: Animation du singe
void animateMonkey();
// show_platform: Montre la plateforme du jeu en affichant tout les elements (Singe, Ennemi, Pièce, Bananes, score, arrière plan, vie)
void show_platform();
// show_win_loose: Montre l'ecran perdu ou gagné suivant que le singe a pris toutes les bananes et ou perdu toutes ses vies
bool show_win_loose(bool *check);
// loading_level: Chargement du niveau
void loading_level(bool refresh);

// Array de 10 Highscore struct
Highscore highscore[10];

#endif
