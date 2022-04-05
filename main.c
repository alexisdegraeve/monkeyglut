/*
* GAME:  Jumping Bananas
* --------------------
* Author: Alexis Degraeve
* Version 1.0
*/

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
#include <stdlib.h>
#include <stdio.h>
#include "controlplayer.h"
#include "controldisplay.h"
#include "loadMap.h"
#include "menu.h"

void initGlutWindow() {
  glutInitDisplayMode(GLUT_RGB| GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(1024,768);
  //Avec cette méthode glutInitWindowPosition on va postionner la feneêtre au milieu
  // de l'écran
  glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-1024)/2,
                         (glutGet(GLUT_SCREEN_HEIGHT)-768)/2);
  glutCreateWindow("Jumping Bananas");
}

int main(int argc, char **argv) {
  read_scores();
  glutInit(&argc,	argv);
  initGlutWindow();
  preloadpictures();
  glutDisplayFunc(displayCurrentScreen);
  glutTimerFunc(delay,	timer,	0);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
