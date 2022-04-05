
#include <GL/gl.h>
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
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SOIL.h"

void soilloadTex(char *c, GLuint textid) {
  int width, height;
  glBindTexture(GL_TEXTURE_2D, textid);
  unsigned char* image = SOIL_load_image(c, &width, &height, 0, SOIL_LOAD_AUTO);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
  SOIL_free_image_data(image);
  glBindTexture(GL_TEXTURE_2D, 0);
}

void soilloadTexOpaque(char *c, GLuint textid) {
  int width, height;
  glBindTexture(GL_TEXTURE_2D, textid);
  unsigned char* image = SOIL_load_image(c, &width, &height, 0, SOIL_LOAD_AUTO);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
  SOIL_free_image_data(image);
  glBindTexture(GL_TEXTURE_2D, 0);
}
