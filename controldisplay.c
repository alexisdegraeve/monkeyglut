#include "controldisplay.h"
#ifndef H_READIMAGE
#define H_READIMAGE
  #include "readimage.h"
#endif

int lissage=GL_NEAREST;
unsigned	int	delay	=	1000/10	;	/*	milliseconds	*/
GLuint textGame[33];

struct glcoord {
  GLfloat x1;
  GLfloat y1;
  GLfloat x2;
  GLfloat y2;
};

/* Coordonnée de l'écran */
struct glcoord coordfullscreen = { .x1=-1.0, .x2=8.0, .y1=1.0, .y2=-1.0};

struct glcoord coordToGlcoord(GLfloat objposx, GLfloat objposy, GLfloat objwidth, GLfloat objheight) {
   struct glcoord temp = {
      .x1 = -1.0 + (objposx * objwidth),
      .y1 = 1.0 - (objposy * objheight),
      .x2 = -1.0 + (objposx * objwidth) +  objwidth,
      .y2 = 1.0 - (objposy * objheight) - objheight
    };
   return temp;
}

void drawObjPolygonBack(struct glcoord coord,bool transparency) {
    glClearColor(1.0,1.0,1.0,0.0);
    glColor4f(1.0, 1.0, 1.0, 0.7);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex2f(coord.x1, coord.y1);
    glTexCoord2f(0, 2);
    glVertex2f(coord.x1, coord.y2);
    glTexCoord2f(8, 2);
    glVertex2f(coord.x2, coord.y2);
    glTexCoord2f(8, 0);
    glVertex2f(coord.x2, coord.y1);
    glEnd();
}

void drawObjPolygon(struct glcoord coord,bool transparency) {
    glClearColor(0.0,0.0,0.0,0.0);
    if(!transparency) {
        glColor3f(1.0, 1.0, 1.0);
    }
    else {
        glColor4f(1.0, 1.0, 1.0, 0.5);
    }
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glBegin(GL_POLYGON);
    glTexCoord3f(0.0, 0.0, 0);
    glVertex3f(coord.x1, coord.y1, 0);
    glTexCoord3f(0.0, 1, 0);
    glVertex3f(coord.x1, coord.y2,0);
    glTexCoord3f(1, 1, 0);
    glVertex3f(coord.x2, coord.y2, 0);
    glTexCoord3f(1, 0.0, 0);
    glVertex3f(coord.x2, coord.y1, 0);
    glEnd();
}

void drawObjPolygonFlip(struct glcoord coord, bool right, bool transparency) {
    if(right) {
        drawObjPolygon(coord, false);
    } else {
      glClearColor(0.0,0.0,0.0,0.0);
      if(!transparency) {
          glColor3f(1.0, 1.0, 1.0);
      }
      else {
          glColor4f(1.0, 1.0, 1.0, 0.5);
      }
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
      glBegin(GL_POLYGON);
      glTexCoord3f(0.0, 0.0, 0);
      glVertex3f(coord.x2, coord.y1, 0);
      glTexCoord3f(0.0, 1, 0);
      glVertex3f(coord.x2, coord.y2,0);
      glTexCoord3f(1, 1, 0);
      glVertex3f(coord.x1, coord.y2, 0);
      glTexCoord3f(1, 0.0, 0);
      glVertex3f(coord.x1, coord.y1, 0);
      glEnd();
    }
}

void drawFlatPolygon(struct glcoord coord) {
  glBegin(GL_QUADS);
    glVertex3f(coord.x1, coord.y1, 0);
    glVertex3f(coord.x1, coord.y2,0);
    glVertex3f(coord.x2, coord.y2, 0);
    glVertex3f(coord.x2, coord.y1, 0);
  glEnd();
}

void drawBitmapText(char *string,float x,float y,float z, bool bigsize)
{
	char *c;
	glRasterPos3f(x, y,z);

	for (c=string; *c != '\0'; c++)
	{
		if(bigsize) {
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    } else {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
	}
}

void displayMonkeyWalk(int keyanm) {
  if(keyanm==1) {
      glBindTexture(GL_TEXTURE_2D, textGame[1]);
  } else if (keyanm==2) {
      glBindTexture(GL_TEXTURE_2D, textGame[2]);
  } else if (keyanm==3) {
      glBindTexture(GL_TEXTURE_2D, textGame[3]);
  } else if (keyanm==4) {
      glBindTexture(GL_TEXTURE_2D, textGame[4]);
  } else if (keyanm==5) {
      glBindTexture(GL_TEXTURE_2D, textGame[5]);
  } else if (keyanm==6) {
      glBindTexture(GL_TEXTURE_2D, textGame[6]);
  }
}

void displayMonkeyJump(int keyanm) {
  if(keyanm==1) {
      glBindTexture(GL_TEXTURE_2D, textGame[7]);
  } else if (keyanm==2) {
      glBindTexture(GL_TEXTURE_2D, textGame[8]);
  } else if (keyanm==3) {
      glBindTexture(GL_TEXTURE_2D, textGame[9]);
  } else if (keyanm==4) {
      glBindTexture(GL_TEXTURE_2D, textGame[10]);
  } else if (keyanm==5) {
      glBindTexture(GL_TEXTURE_2D, textGame[11]);
  } else if (keyanm==6) {
      glBindTexture(GL_TEXTURE_2D, textGame[12]);
  }
}

void displayMonkey(GLfloat posMonkeyX, GLfloat posMonkeyY, bool right, bool jump, int keyanm)
{
  glEnable(GL_BLEND);
  if(jump == false) {
    displayMonkeyWalk(keyanm);
  } else {
    displayMonkeyJump(keyanm);
  }
  int totalCaseW = glutGet(GLUT_WINDOW_WIDTH) / 64;
  int totalCaseH = glutGet(GLUT_WINDOW_HEIGHT) / 64;
  GLfloat sizeSpriteW = 1.0 / (totalCaseW / 2.0);
  GLfloat sizeSpriteH = 1.0 / (totalCaseH / 2.0);
  struct glcoord coordsinge = coordToGlcoord(posMonkeyX, posMonkeyY, sizeSpriteW, sizeSpriteH);
  drawObjPolygonFlip(coordsinge, right, false);
}

void displayMonkeySmall(GLfloat posMonkeyX, GLfloat posMonkeyY)
{
  glBindTexture(GL_TEXTURE_2D, textGame[13]);
  struct glcoord coordsinge = { .x1=posMonkeyX, .x2=posMonkeyX+0.08, .y1=posMonkeyY, .y2=posMonkeyY-0.08};
  drawObjPolygon(coordsinge, false);
}

void displaySnakeWalk(int keyanm) {
  if(keyanm==1) {
      glBindTexture(GL_TEXTURE_2D, textGame[14]);
  } else if (keyanm==2) {
      glBindTexture(GL_TEXTURE_2D, textGame[15]);
  } else if (keyanm==3) {
      glBindTexture(GL_TEXTURE_2D, textGame[16]);
  } else if (keyanm==4) {
      glBindTexture(GL_TEXTURE_2D, textGame[17]);
  } else if (keyanm==5) {
      glBindTexture(GL_TEXTURE_2D, textGame[18]);
  }
}


void displayHedgeHogWalk(int keyanm) {
  if(keyanm==1) {
      glBindTexture(GL_TEXTURE_2D, textGame[29]);
  } else if (keyanm==2) {
      glBindTexture(GL_TEXTURE_2D, textGame[30]);
  } else if (keyanm==3) {
      glBindTexture(GL_TEXTURE_2D, textGame[31]);
  } else if (keyanm==4) {
      glBindTexture(GL_TEXTURE_2D, textGame[32]);
  } else if (keyanm==5) {
      glBindTexture(GL_TEXTURE_2D, textGame[32]);
  }
}


void displayEnnemy(char type, int posEnemyX, int posEnemyY, bool left, int keyanm, bool capture) {
    if(capture == false) {
      if(type=='E') {
        displaySnakeWalk(keyanm);
      }
      if(type=='F') {
        displayHedgeHogWalk(keyanm);
      }
    } else {
      glBindTexture(GL_TEXTURE_2D, textGame[19]);

    }

  int totalCaseW = glutGet(GLUT_WINDOW_WIDTH) / 64;
  int totalCaseH = glutGet(GLUT_WINDOW_HEIGHT) / 64;

  GLfloat sizeSpriteW = 1.0 / (totalCaseW / 2.0);
  GLfloat sizeSpriteH = 1.0 / (totalCaseH / 2.0);
  struct glcoord coordenemy = coordToGlcoord(posEnemyX, posEnemyY, sizeSpriteW, sizeSpriteH);
  drawObjPolygonFlip(coordenemy, left, false);
}

void displayBubble(int posBubbleX, int posBubbleY, bool left, int keyanm) {
    if(keyanm==1) {
        glBindTexture(GL_TEXTURE_2D, textGame[24]);
    }
    if (keyanm==2) {
       glBindTexture(GL_TEXTURE_2D, textGame[25]);
    }

  int totalCaseW = glutGet(GLUT_WINDOW_WIDTH) / 64;
  int totalCaseH = glutGet(GLUT_WINDOW_HEIGHT) / 64;
  GLfloat sizeSpriteW = 1.0 / (totalCaseW / 2.0);
  GLfloat sizeSpriteH = 1.0 / (totalCaseH / 2.0);
  struct glcoord coordbubble = coordToGlcoord(posBubbleX, posBubbleY, sizeSpriteW, sizeSpriteH);
  drawObjPolygonFlip(coordbubble, left, true);
}

void displayFloor(int posFloorX, int posFloorY)
{
  glDisable(GL_BLEND);
  glBindTexture(GL_TEXTURE_2D, textGame[20]);
  int totalCaseW = glutGet(GLUT_WINDOW_WIDTH) / 64;
  int totalCaseH = glutGet(GLUT_WINDOW_HEIGHT) / 64;
  GLfloat sizeSpriteW = 1.0 / (totalCaseW / 2.0);
  GLfloat sizeSpriteH = 1.0 / (totalCaseH / 2.0);
  struct glcoord coordfloor = coordToGlcoord(posFloorX, posFloorY, sizeSpriteW, sizeSpriteH);
  drawObjPolygon(coordfloor, false);
  glEnable(GL_BLEND);
}

void displayGrass(int posGrassX, int posGrassY)
{
  glBindTexture(GL_TEXTURE_2D, textGame[21]);
  int totalCaseW = glutGet(GLUT_WINDOW_WIDTH) / 64;
  int totalCaseH = glutGet(GLUT_WINDOW_HEIGHT) / 64;
  GLfloat sizeSpriteW = 1.0 / (totalCaseW / 2.0);
  GLfloat sizeSpriteH = 1.0 / (totalCaseH / 2.0);
  struct glcoord coordgrass = coordToGlcoord(posGrassX, posGrassY, sizeSpriteW, sizeSpriteH);
  drawObjPolygon(coordgrass, false);
}

void displayBananas(int posBananaX, int posBananaY)
{
  glBindTexture(GL_TEXTURE_2D, textGame[19]);
  int totalCaseW = glutGet(GLUT_WINDOW_WIDTH) / 64;
  int totalCaseH = glutGet(GLUT_WINDOW_HEIGHT) / 64;
  GLfloat sizeSpriteW = 1.0 / (totalCaseW / 2.0);
  GLfloat sizeSpriteH = 1.0 / (totalCaseH / 2.0);
  struct glcoord coordbananas = coordToGlcoord(posBananaX, posBananaY, sizeSpriteW, sizeSpriteH);
  drawObjPolygon(coordbananas, false);
}

void displayCoinSilver(int posCoinSilverX, int posCoinSilverY)
{
  glBindTexture(GL_TEXTURE_2D, textGame[22]);
  int totalCaseW = glutGet(GLUT_WINDOW_WIDTH) / 64;
  int totalCaseH = glutGet(GLUT_WINDOW_HEIGHT) / 64;
  GLfloat sizeSpriteW = 1.0 / (totalCaseW / 2.0);
  GLfloat sizeSpriteH = 1.0 / (totalCaseH / 2.0);
  struct glcoord coordcoin = coordToGlcoord(posCoinSilverX, posCoinSilverX, sizeSpriteW, sizeSpriteH);
  drawObjPolygon(coordcoin, false);
}

void displayCoinGold(int posCoinGoldX, int posCoinGoldY)
{
  glBindTexture(GL_TEXTURE_2D, textGame[23]);
  int totalCaseW = glutGet(GLUT_WINDOW_WIDTH) / 64;
  int totalCaseH = glutGet(GLUT_WINDOW_HEIGHT) / 64;
  GLfloat sizeSpriteW = 1.0 / (totalCaseW / 2.0);
  GLfloat sizeSpriteH = 1.0 / (totalCaseH / 2.0);
  struct glcoord coordcoingold = coordToGlcoord(posCoinGoldX, posCoinGoldY, sizeSpriteW, sizeSpriteH);
  drawObjPolygon(coordcoingold, false);
}

void displayBackground()  {
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_BLEND);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glBindTexture(GL_TEXTURE_2D, textGame[0]);
  drawObjPolygonBack(coordfullscreen, false);
}

void displayHeader(int score, int life, int level) {
  glDisable(GL_BLEND);
  struct glcoord coordRect = { .x1=-1.0f, .x2=1.0f, .y1=1.0f, .y2=0.9f};
  glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
  drawFlatPolygon(coordRect);
  glColor3f(1.0, 1.0, 1.0);
  char mscore[10];
  char * text="SCORE:";
  sprintf(mscore, "%i", score);  //Convertir un int pour afficher en chaine de caractères
  drawBitmapText(text,-0.98f, 0.93f,0.0f, false);
  drawBitmapText(mscore,-0.80f, 0.93f,0.0f, false);

  char mlevel[10];
  sprintf(mlevel, "%i", level);
  text="LEVEL";
  drawBitmapText(text, -0.10f, 0.93f,0.0f, false);
  drawBitmapText(mlevel, 0.08f, 0.93f,0.0f, false);

  text="LIFE: ";
  drawBitmapText(text,0.62f, 0.93f,0.0f, false);
  glEnable(GL_BLEND);
  for (int i = 0; i < life; i++) {
   displayMonkeySmall(0.75+(i * 0.08), 1.0f);
  }
}

void displayTitle(GLfloat posTitleX, GLfloat posTitleY)
{
  glBindTexture(GL_TEXTURE_2D, textGame[26]);
  struct glcoord coordpostitle = coordToGlcoord(posTitleX, posTitleY, 1, 0.25);
  drawObjPolygon(coordpostitle, false);
}

void displayMainMenu() {
  displayBackground();
  struct glcoord coordRect = { .x1=-0.5f, .x2=0.5f, .y1=0.5f, .y2=-0.5f};
  glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
  drawFlatPolygon(coordRect);
  displayTitle(0.5,2.0);
  displayMonkey(4.0f, 8.0f, true, true, 2);
  glDisable(GL_TEXTURE_2D);
  glColor3f(1.0f, 1.0f, 1.0f);
  char * text="N - Nouveau Jeu";
  drawBitmapText(text, -0.15f, 0.15f,0.0f, true);
  text="H - HighScores";
  drawBitmapText(text, -0.15f, 0.05f,0.0f, true);
  text="R - Regle du  Jeu";
  drawBitmapText(text, -0.15f, -0.05f,0.0f, true);
  text="Esc - Sortir du Jeu";
  drawBitmapText(text, -0.15f, -0.15f,0.0f, true);
  glEnable(GL_TEXTURE_2D);
  glutSwapBuffers();
}

void displayRules() {
  displayBackground();
  struct glcoord coordRect = { .x1=-0.5f, .x2=0.5f, .y1=0.5f, .y2=-0.5f};
  glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
  drawFlatPolygon(coordRect);
  displayTitle(0.5,2.0);
  displayMonkey(4.0f, 8.0f, true, true, 2);
  glDisable(GL_TEXTURE_2D);
  glColor3f(1.0f, 1.0f, 1.0f);
  char * text="Regle du jeu";
  drawBitmapText(text, -0.45f, 0.15f,0.0f, true);
  text="But du jeu: Ramasser toutes les bananes et pieces";
  drawBitmapText(text, -0.45f, 0.05f,0.0f, true);
  text="Pour vous deplacer: Q (Gauche), D (Droite)";
  drawBitmapText(text, -0.45f, -0.05f,0.0f, true);
  text=" Barre d'espace (SAUT)";
  drawBitmapText(text, -0.45f, -0.15f,0.0f, true);
  text="Immobiliser un ennemi en appuyant sur la touche A";
  drawBitmapText(text, -0.45f, -0.25f,0.0f, true);
  glEnable(GL_TEXTURE_2D);
  glutSwapBuffers();
}

void displayHighScores() {
  displayBackground();
  struct glcoord coordRect = { .x1=-0.5f, .x2=0.5f, .y1=0.5f, .y2=-0.5f};
  glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
  drawFlatPolygon(coordRect);
  displayTitle(0.5,2.0);
  displayMonkey(4.0f, 8.0f, true, true, 2);
  glDisable(GL_TEXTURE_2D);
  glColor3f(1.0f, 1.0f, 1.0f);
  char * text="HIGHSCORES";
  drawBitmapText(text, -0.45f, 0.20f,0.0f, true);

  for (int i = 0; i < 10; i++) {
    drawBitmapText(highscore[i].score, -0.45f, -0.30+(i * 0.05),0.0f, true);
  }

  glEnable(GL_TEXTURE_2D);
  glutSwapBuffers();
}


void displayYouWin() {
  displayBackground();
  struct glcoord coordRect = { .x1=-0.5f, .x2=0.5f, .y1=0.5f, .y2=-0.5f};
  glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
  drawFlatPolygon(coordRect);
  glBindTexture(GL_TEXTURE_2D, textGame[28]);
  int totalCaseW = glutGet(GLUT_WINDOW_WIDTH) / 400;
  int totalCaseH = glutGet(GLUT_WINDOW_HEIGHT) / 300;
  GLfloat sizeSpriteW = 1.0 / (totalCaseW / 2.0);
  GLfloat sizeSpriteH = 1.0 / (totalCaseH / 2.0);
  struct glcoord coordyouwin = coordToGlcoord(0.5, 0.5, sizeSpriteW, sizeSpriteH);
  drawObjPolygonFlip(coordyouwin, true, false);
  glutSwapBuffers();
}

void displayYouLose() {
  displayBackground();
  struct glcoord coordRect = { .x1=-0.5f, .x2=0.5f, .y1=0.5f, .y2=-0.5f};
  glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
  drawFlatPolygon(coordRect);
  glBindTexture(GL_TEXTURE_2D, textGame[27]);
  int totalCaseW = glutGet(GLUT_WINDOW_WIDTH) / 400;
  int totalCaseH = glutGet(GLUT_WINDOW_HEIGHT) / 300;
  GLfloat sizeSpriteW = 1.0 / (totalCaseW / 2.0);
  GLfloat sizeSpriteH = 1.0 / (totalCaseH / 2.0);
  struct glcoord coordyouwin = coordToGlcoord(0.5, 0.5, sizeSpriteW, sizeSpriteH);
  drawObjPolygonFlip(coordyouwin, true, false);
  glutSwapBuffers();
}

void timer(int id) {
   glutTimerFunc(delay,	timer,	0);
   glutPostRedisplay();
}

void preloadpictures() {
    glGenTextures(33, textGame);
    soilloadTexOpaque("img/jungle_background.bmp", textGame[0]);
    soilloadTex("img/monkey_walk_01.png", textGame[1]);
    soilloadTex("img/monkey_walk_02.png", textGame[2]);
    soilloadTex("img/monkey_walk_03.png", textGame[3]);
    soilloadTex("img/monkey_walk_04.png", textGame[4]);
    soilloadTex("img/monkey_walk_05.png", textGame[5]);
    soilloadTex("img/monkey_walk_06.png", textGame[6]);
    soilloadTex("img/monkey_jump_01.png", textGame[7]);
    soilloadTex("img/monkey_jump_02.png", textGame[8]);
    soilloadTex("img/monkey_jump_03.png", textGame[9]);
    soilloadTex("img/monkey_jump_04.png", textGame[10]);
    soilloadTex("img/monkey_jump_05.png", textGame[11]);
    soilloadTex("img/monkey_jump_06.png", textGame[12]);
    soilloadTex("img/monkey_walking_small.png", textGame[13]);
    soilloadTex("img/snake_walk_01.png", textGame[14]);
    soilloadTex("img/snake_walk_02.png", textGame[15]);
    soilloadTex("img/snake_walk_03.png", textGame[16]);
    soilloadTex("img/snake_walk_04.png", textGame[17]);
    soilloadTex("img/snake_walk_05.png", textGame[18]);
    soilloadTex("img/sprite_banana_small.png", textGame[19]);
    soilloadTex("img/sprite_floor_small.png", textGame[20]);
    soilloadTex("img/sprite_grass_small.png", textGame[21]);
    soilloadTex("img/spritecoinbananagray.png", textGame[22]);
    soilloadTex("img/spritecoinbanana.png", textGame[23]);
    soilloadTex("img/sprite_bubble.png", textGame[24]);
    soilloadTex("img/sprite_bubble_yellow.png", textGame[25]);
    soilloadTex("img/title.png", textGame[26]);
    soilloadTex("img/screen_you_lose.png", textGame[27]);
    soilloadTex("img/screen_you_win.png", textGame[28]);
    soilloadTex("img/herisson_walk_01.png", textGame[29]);
    soilloadTex("img/herisson_walk_02.png", textGame[30]);
    soilloadTex("img/herisson_walk_03.png", textGame[31]);
    soilloadTex("img/herisson_walk_04.png", textGame[32]);
}
