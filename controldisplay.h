#include <stdio.h>
#include <stdbool.h>
#ifdef	__APPLE_CC__
  #ifndef H_GLUT
  #define H_GLUT
   #include <GLUT/glut.h>
  #endif
#else
  #ifndef H_GLUT
  #define H_GLUT
   #include <GL/glut.h>
  #endif
#endif
#include "loadMap.h"

unsigned	int	delay;	/*	milliseconds	*/

struct glcoord;
/* coordToGlcoord : converti les coordoonnées d'un objet à l'écran  */
struct glcoord coordToGlcoord(GLfloat objposx, GLfloat objposy, GLfloat objwidth, GLfloat objheight);
/* drawObjPolygon: Dessine un Polygone avec une texture à partir des coordonnées de points pour l'arrière plan */
void drawObjPolygonBack(struct glcoord coord,bool transparency);
/* drawObjPolygon: Dessine un Polygone avec une texture à partir des coordonnées de points */
void drawObjPolygon(struct glcoord coord,bool transparency);
/* drawObjPolygonFlip: Dessine un Polygone vers la direction droite ou gauche */
void drawObjPolygonFlip(struct glcoord coord, bool right, bool transparency);
/* drawFlatPolygon: Dessine un Polygone dans une seule couleur */
void drawFlatPolygon(struct glcoord coord);
/* drawBitmapText: Dessine une chaine de caractère sous forme de Pixel à une position x, y, z*/
void drawBitmapText(char *string,float x,float y,float z, bool bigsize);
/* displayMonkeyWalk: Affiche une image de l'animation du singe qui marche suivant le keyanm */
void displayMonkeyWalk(int keyanm);
/* displayMonkeyJump: Affiche une image de l'animation du singe qui saute suivant le keyanm */
void displayMonkeyJump(int keyanm);
/* displayMonkey: Affiche le singe avec l'animation approprié ainsi que le sens droite ou gauche */
void displayMonkey(GLfloat posMonkeyX, GLfloat posMonkeyY, bool right, bool jump, int keyanm);
/* displayMonkeySmall: Affiche un singe en petit pour l'afficher dans la barre des vies */
void displayMonkeySmall(GLfloat posMonkeyX, GLfloat posMonkeyY);
/* displaySnakeWalk: Affiche une image du  serpent qui bouge suivant le keynam */
void displaySnakeWalk(int keyanm);
/* displayHedgeHogWalk: Affiche une image de l'herisson qui bouge suivant le keynam */
void displayHedgeHogWalk(int keyanm);
/* displaySnake: Affiche l'ennemi avec l'animation approprié ainsi que le sens droite ou gauche */
void displayEnnemy(char type, int posEnemyX, int posEnemyY, bool left, int keyanm, bool capture);
/* displayBubble: Affiche la bulle ou alors en jaune si l'ennemi est capturé */
void displayBubble(int posBubbleX, int posBubbleY, bool left, int keyanm);
/* displayFloor: Affiche la plate-forme */
void displayFloor(int posFloorX, int posFloorY);
/* displayGrass: Affiche l'herbe */
void displayGrass(int posGrassX, int posGrassY);
/* displayBananas: Affiche la banane */
void displayBananas(int posBananaX, int posBananaY);
/* displayCoinSilver: Affiche une pièce d'argent */
void displayCoinSilver(int posCoinSilverX, int posCoinSilverY);
/* displayCoinGold: Affiche une pièce d'or */
void displayCoinGold(int posCoinGoldX, int posCoinGoldY);
/* displayBackground: Affiche l'arrière plan */
void displayBackground();
/* displayHeader: Affiche l'en-tête */
void displayHeader(int score, int life, int level);
/* displayMainMenu: Affiche l'écran principal */
void displayMainMenu();
/* displayRules: Affiche les règles du jeu */
void displayRules();
/* displayHighScores: Affiche les plus haut score */
void displayHighScores();
/* displayYouWin: Affiche l'écran gagné */
void displayYouWin();
/* displayYouLose: Affiche l'écran perdu */
void displayYouLose();
/* timer: Reaffiche l'écran */
void timer(int id);
/* preloadpictures: Chargement de toutes les images en mémoire */
void preloadpictures();
