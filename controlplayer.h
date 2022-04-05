/* Manage the keyboard */
#include <stdbool.h>

// isEmptyAfterBeforePlatform:
// Fonction pour savoir s'il y a du vide avant le singe et s'il est sur une plateforme
// et pour savoir s'il y a du vide apres le singe s'il est sur une plateforme
bool isEmptyAfterBeforePlatform();
// isEmptyVertically: Savoir s'il y a du vide sur la case on va aller et en-dessous (si c'est le cas le singe tombe dans le vide)
bool isEmptyVertically();
// testMonkeyJumpAndFall: Test pour voir faire Sauter le Singe et qu'il tombe dans le vide jusqu'a ce
//    qu'il atterrisse sur une plateforme
void testMonkeyJumpAndFall(int posx, int posy);
// testMonkeyJumpAndNotFall: Test pour voir faire Sauter le Singe vers le haut et qu'il monte
//    dans le vide jusqu'a ce qu'il touche une plateforme ou fait moins de 4 pas vers le haut
void testMonkeyJumpAndNotFall(int posx, int posy);
// scrollingScreen: Scrolling horizontal de l'écran suivant si le Singe dépasse la taille de l'écran
void scrollingScreen();
// testMonkeyInsideTheScreen: Test pour voir Si le singe est toujorus dans l'écran
//    si ce n'est pas le cas la fonction renvoie false
void testMonkeyInsideTheScreen(bool *testcollide, int posx, int posy);
// testMonkeyHitThePlatform: Si le singe touche une plateforme on le fait remonter
void testMonkeyHitThePlatform(int posx, int posy);
// testMonkeyHitTheFloor: Si le singe touche le sol cela retourne false
void testMonkeyHitTheFloor(bool *testcollide, int posx, int posy);
// testMonkeyGetCoin: Test pour savoir si le singe prend une pièce et augmente son score de 500 points
//   et disparaitre la pièce du tableau de la map
void testMonkeyGetCoin(int posx, int posy);
// testMonkeyGetBanana: Test pour savoir si le singe prend une banane et augmente son score de 1000 points
//   et disparaitre la banane du tableau de la map
void testMonkeyGetBanana(int posx, int posy);
// sendBubble: Envoie d'une boule (maximum 3) et deplacement en horizontal
void sendBubble();
// resetBubble: Reinitialise la boule avec les paramètres par défaut
void resetBubble(int num);
// testCollideBubble: Test pour savoir si la bulle est active et si c'est le cas voir s'il est dans l'écran (Sauf si elle figée)
void testCollideBubble();
// testCollideEnemy: Test pour savoir si l'ennmi touche le singe si c'est le cas une vie en moins et le singe
//   est repositionner à la position de départ du jeu .
//   Teste pour savoir si l'ennemi touche la bulle également pour être geler.
//   Si le singe va sur la position de la bulle et que l'ennemi est capturer et transformer en banane alors augmentation des points
void testCollideEnemy(bool *testcollide, int posx, int posy);
// testPassCollide: Noyau principal pour les collisions aussi bien du singe avec les autres éléments ainsi que de l'ennemi avec la boule
void testPassCollide();
// monkeyRightMoveOutsideScreen: Voir sir le singe ne dépasse pas la zone de l'écran quand il va vers la droite
bool monkeyRightMoveOutsideScreen();
// monkeyLeftMove: Déplacement du singe vers la gauche
void monkeyLeftMove();
// monkeyRightMove: Déplacement du singe vers la droite
void monkeyRightMove();
// Gestion des touches du clavier
//  Q: gauche| D: droit| spacebar: saut | a: Boule
void keyboard(unsigned	char	key,	int	x,	int	y);
