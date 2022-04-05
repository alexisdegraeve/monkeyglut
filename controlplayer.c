/* Manage the keyboard */
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
#include "personnages.h"
#include "menu.h"
#include "loadMap.c"

bool leftmove = false;
bool rightmove = false;
bool presskeyleftright = false;
bool fall = false;
float cptjump = 0;
bool activatescrollleft=false;
float scrollxleft = 0;
bool activatescrollright=false;
float scrollxright = 0;

bool isEmptyAfterBeforePlatform() {
    bool result = false;

    if(fall==false) {
      int posx = (int)(cocoSinge.position.x+0.5);
      int posy = (int)(cocoSinge.position.y+0.5);

      if(posx > 0) {
        if((platform[posy+1][posx-1]=='P' && platform[posy+1][posx]=='-' ) ||
           (platform[posy+1][posx+1]=='P' && platform[posy+1][posx]=='-'  ) )
        {
          result = true;
        }
      }
    }
    return result;
}

bool isEmptyVertically(){
  int posx = (int)(cocoSinge.position.x+0.5);
  int posy = (int)(cocoSinge.position.y+0.5);

  if((platform[posy][posx]=='-' && platform[posy+1][posx]=='-' )) {
    return  true;
  } else {
    return false;
  }

}

void testMonkeyJumpAndFall(int posx, int posy) {
  if (cocoSinge.jump==true && fall == true) {
    cocoSinge.position.y = cocoSinge.position.y + 0.5;
    cptjump -=0.5;

    if(platform[posy][posx]=='S' || platform[posy][posx]=='P')
    {
      cocoSinge.position.y = cocoSinge.position.y - 1;
      cptjump = 0;
      cocoSinge.jump = false;
      fall = false;
    }
  }
}

void testMonkeyJumpAndNotFall(int posx, int posy) {
  if (cocoSinge.jump==true && fall == false) {
    if(cptjump < 4) {
      if(platform[posy][posx]=='S' || platform[posy][posx]=='P' || cocoSinge.position.y < 0)
      {
        fall = true;
      }else {
        cptjump +=0.5;
        cocoSinge.position.y = cocoSinge.position.y - 0.5;
      }

    }
    else {
      fall = true;
    }
  }
}

void scrollingScreen() {

      if(cocoSinge.right){
        if(activatescrollright)
        {
          if(scrollxright > -0.200)
          {
            scrollxright -= 0.01;
            glTranslatef(-0.1,0,0);
          }
          else {
            activatescrollright = false;
          }

        } else {
          if (((int)cocoSinge.position.x % (maxW+1) == 0) &&  activatescrollright==false){
            activatescrollright = true;
          } else {
            scrollxright = 0;
          }
        }
      } else {
        if(activatescrollleft)
        {
          if(scrollxleft < 0.200)
          {
            scrollxleft += 0.01;
            glTranslatef(0.1,0,0);
          }
          else {
            activatescrollleft = false;
          }

        } else {
          if (((int)cocoSinge.position.x % (maxW+1) == 0) &&  activatescrollleft==false){
            activatescrollleft = true;
          } else {
            scrollxleft = 0;
          }
        }

      }
}

void testMonkeyInsideTheScreen(bool *testcollide, int posx, int posy) {
    if ((cocoSinge.position.x  < 0) || (cocoSinge.position.x  > W))
    {
      *testcollide=false;
    }
    else {
        // Multiple Screen
        if (W>(maxW+1)) {
          // Nombre total d'écrans
          int totalscreen = W % maxW;
          // Teste si le le singe n'est pas dans le dernier écran
          if(cocoSinge.position.x < (W-(totalscreen * 2))) {
            if ((cocoSinge.position.x  >= 1) && (cocoSinge.position.x  <= W-0.5)) {
             scrollingScreen();
            }
          }
        }
   }
}

void testMonkeyHitThePlatform(int posx, int posy) {
  if(platform[posy][posx]=='P') {
    if(cocoSinge.jump==true) {
      cocoSinge.position.y= cocoSinge.position.y + 0.5;
      fall = true;
    }
  }
}


void testMonkeyHitTheFloor(bool *testcollide, int posx, int posy) {
      if(platform[posy][posx]=='S') {
        *testcollide = false;
      }
}

void testMonkeyGetCoin(int posx, int posy) {
  if(platform[posy][posx]=='C') {
    cocoSinge.points += 500;
    platform[posy][posx]='-';
  }
}

void testMonkeyGetBanana(int posx, int posy) {
    if(platform[posy][posx]=='B') {
      cocoSinge.points += 1000;
      platform[posy][posx]='-';
      totalbananes-=1;
    }
}

void sendBubble() {
  int i = 0;
  bool foundbullelibre = false;
  while ((i<3)  && (!foundbullelibre)){
    if((!bulle[i].move) && (!bulle[i].active)) {
      resetBubble(i);
      bulle[i].active = true;
      bulle[i].move = true;
      foundbullelibre = true;
    }
    i++;
  }
}

void resetBubble(int num) {
    bulle[num].active = false;
    bulle[num].move = false;
    bulle[num].keyanm = 1;
    bulle[num].timer = 600;
    bulle[num].position.y = cocoSinge.position.y;
    if( cocoSinge.right) {
      bulle[num].position.x = cocoSinge.position.x + 1;
    } else {
      bulle[num].position.x = cocoSinge.position.x - 1;
    }
}

void testCollideBubble() {
  for (int i = 0; i < 3; i++) {
    if(bulle[i].active && ((bulle[i].position.x < 0) || (bulle[i].position.x > W -1)))
    {
      resetBubble(i);
    }

  }
}

void testCollideEnemy(bool *testcollide, int posx, int posy) {
  // Detect collision with the snake
    Ennemi *enemytmp, *enemyprec;
    bool touchebulle = false;
    bool supprimeallenemy = false;
    enemytmp = ennemis;
    enemyprec = NULL;
  // printf("testCollideEnemy \n");
    while(enemytmp!=NULL) {
      int enemyPosX = (int)enemytmp->position.x;
      int enemyPosY = (int)enemytmp->position.y;

      //Bulle
      for (int i = 0; i < 3; i++) {
        //  printf("boucle for %d \n", i);
        int bullePosX = (int)bulle[i].position.x;
        int bullePosY = (int)bulle[i].position.y;
        if(bulle[i].active && bullePosX==enemyPosX &&  bullePosY==enemyPosY && bulle[i].timer > 0) {
          bulle[i].keyanm = 2;
          bulle[i].move = false;
          enemytmp->freeze = true;
          bulle[i].timer -=1;
        }
        if(bulle[i].active && bullePosX==enemyPosX &&  bullePosY==enemyPosY && bulle[i].timer == 0) {
          // Reset de la bulle
          touchebulle = false;
          enemytmp->freeze = false;
          enemytmp->capture = false;
          resetBubble(i);
        }

        if(bulle[i].active &&  bullePosX==enemyPosX &&  bullePosY==enemyPosY && posx==enemyPosX &&  posy ==enemyPosY && cocoSinge.jump && bulle[i].timer > 0) {
          bulle[i].active = false;
          touchebulle = true;
          enemytmp->capture = true;
          totalbananes+=1;
        }

      }


      if(!touchebulle && !enemytmp->capture && posx==enemyPosX &&  posy==enemyPosY && !enemytmp->freeze) {
        cocoSinge.vies--;
        cocoSinge.position.x = cocoSinge.posorigin.x;
        cocoSinge.position.y = cocoSinge.posorigin.y;
        glLoadIdentity(); // Reset Scrolling;
        *testcollide = true;
      }

      // Si l'ennemi est capture et devenu une banane alors on supprime
      if(!touchebulle && enemytmp->banane && enemytmp->capture && posx==enemyPosX &&  posy==enemyPosY) {
        cocoSinge.points += 3000;
        totalbananes-=1;
        //supprime l'ennemi

        // Suppresion de l'ennemi dans liste chainée
        // Il est unique
        if (enemyprec == NULL  && (enemytmp->nextEnnemi == NULL))
        {
          supprimeallenemy = true;
        } else {
          // S'il y a pas d'élement précédent et un seul ennemi
          if((enemyprec == NULL) && (enemytmp != NULL)) {
            ennemis = enemytmp->nextEnnemi;
          } else {

            if ((enemyprec->nextEnnemi == NULL) && (enemytmp->nextEnnemi == NULL)) {
              supprimeallenemy = true;
            } else {
             // Il y a juste un ennemi precedent
              if((enemyprec->nextEnnemi != NULL) && (enemytmp->nextEnnemi == NULL)){
                enemyprec->nextEnnemi = NULL;
              }
              else {
                  // Il y a un ennemi avant et apres
                  enemyprec->nextEnnemi = enemytmp->nextEnnemi;
              }
            }
          }

        }

      }

      // Si l'ennemi est capture alors augmente score et supprime l'ennemi
      if(!touchebulle && !enemytmp->banane && enemytmp->capture && posx==enemyPosX &&  posy==enemyPosY) {
        enemytmp->banane = true;
        if (cocoSinge.right) {
          cocoSinge.position.x -= 1;
        } else {
          cocoSinge.position.x += 1;
        }
      }

      if(enemytmp != NULL) {
        enemyprec = enemytmp;
        enemytmp=enemytmp->nextEnnemi;
      }
    }

    if(supprimeallenemy) {
      free(ennemis);
      ennemis = NULL;
    }
}

void testPassCollide() {
  bool testcollide = true;
  int posx = (int)(cocoSinge.position.x+0.5);
  int posy = (int)(cocoSinge.position.y+0.5);
  testMonkeyInsideTheScreen(&testcollide, posx, posy);

  if(testcollide == true )
  {
    if(isEmptyAfterBeforePlatform()) {
      cocoSinge.jump=true;
      fall = true;
    }

    if(fall==false && cocoSinge.jump==false && isEmptyVertically()) {
      cocoSinge.jump=true;
      fall = true;
    }

    testMonkeyJumpAndFall(posx, posy);
    testMonkeyJumpAndNotFall(posx, posy);
    testMonkeyHitThePlatform(posx, posy);
    testMonkeyHitTheFloor(&testcollide, posx, posy);
    testMonkeyGetCoin(posx, posy);
    testMonkeyGetBanana(posx, posy);

  }

  testCollideBubble();
  testCollideEnemy(&testcollide, posx, posy);
}

bool monkeyRightMoveOutsideScreen() {
  bool outsidescreen = false;
  // Cas ou il y a pas de scrolling
  if(cocoSinge.position.x >= (W-1)) {
    outsidescreen = true;
  }
  return outsidescreen;
}

bool monkeyLeftMoveOutsideScreen() {
  bool outsidescreen = false;
  // Cas ou il y a pas de scrolling
    if(cocoSinge.position.x < 0.5) {
      outsidescreen = true;
    }

  return outsidescreen;
}

void monkeyLeftMove() {
  if(!fall && !monkeyLeftMoveOutsideScreen()) {
    leftmove = true;
    cocoSinge.right = false;
    cocoSinge.position.x=cocoSinge.position.x-0.5;
    presskeyleftright = true;
   }
}

void monkeyRightMove() {
  if(!fall && !monkeyRightMoveOutsideScreen()) {
    rightmove = true;
    cocoSinge.right = true;
    cocoSinge.position.x=cocoSinge.position.x+0.5;
    presskeyleftright = true;
  }
}


void keyboardGame(unsigned char key) {
  switch (key)	{
    /* Spacebar to jump */
    case 'a':
      sendBubble();
      break;
    case ' ':
      cocoSinge.jump = true;
      break;
    case 'q':
      monkeyLeftMove();
      break;
    case 'd':
      monkeyRightMove();
      break;
    case 13:
      if(humanplayer.startagain) {
        humanplayer.startagain = false;
        gameLoaded = false;
      }
      break;
    case 27 /* Esc */:
      currentScreen = 0;
      break;
  }
}

void keyboardMainMenu(unsigned char key) {
  switch (key)	{
    /* Spacebar to jump */
    case 'n':
      gameLoaded = false;
      currentScreen = 1;
      break;
    case 'r':
      currentScreen = 2;
      break;
    case 'h':
      currentScreen = 3;
      break;
    case 27 /* Esc */:
      write_scores(); // Write Highscore before exit
      exit(1);
      break;
  }
}

void keyboardView(unsigned char key) {
  switch (key)	{
    case 10: // enter
      currentScreen = 0;
      break;
    case 27 /* Esc */:
      currentScreen = 0;
      break;
  }
}

void keyboard(unsigned	char	key,	int	x,	int	y)	{
  if(currentScreen == 0)
  {
    keyboardMainMenu(key);
  }
  if(currentScreen == 1)
  {
    keyboardGame(key);
  }
  if((currentScreen == 2) || (currentScreen == 3 ))
  {
    keyboardView(key);
  }
}
