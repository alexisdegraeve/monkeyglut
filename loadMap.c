#include <stdio.h>
#include "personnages.h"
#include "controldisplay.h"
#include "controlplayer.h"
#include "game.h"

bool check_show_win_loose = false;

void totalinecolumn(int level) {
  int i=0;
  int j=0;
  char c;
  char filename[100];
  FILE *file;
  sprintf(filename, "maplevel%d.txt", level);
  file = fopen(filename, "r");
  while ((c = fgetc(file)) != EOF) {
      if(c=='\n') {
        i++;
        W = j-1;
        j=0;
      }
      else {
        j++;
      }
  }
  fclose(file);
  H = i;
  maxH = (int)(glutGet(GLUT_SCREEN_WIDTH) / 64);
  maxW = (int)(glutGet(GLUT_SCREEN_HEIGHT) / 64);
}

int read_platform(int level){
  totalinecolumn(level);
  char c;
  char filename[100];
  FILE *file;
  int i=0;
  int j=0;
  platform = malloc(H * sizeof(char *));
  sprintf(filename, "maplevel%d.txt", level);
  file = fopen(filename, "r");
  if(file == NULL)
  {
    return 1;
  }
  platform[i]= malloc(W * sizeof(char *));
  if (file) {
      while ((c = fgetc(file)) != EOF) {
             platform[i][j] = c;
             if(c=='\n') {
               i++;
               platform[i]= malloc(W * sizeof(char *));
               j=0;
             }
             else{
               j++;
             }

      }
      fclose(file);
  }
  return 0;
}

int read_scores(){


    for (int l = 0; l < 10; l++) {
        highscore[l].score = "0";
    }

  int i=0;
  int j=0;
  int tmpnumb = 0;
  int actnumb = 0;
  char c;
  char *score = (char*)malloc(10);
  char *tmpscore = (char*)malloc(10);
  FILE *file;
  file = fopen("scores.txt", "r");
  if(file == NULL)
  {
    return 1;
  }

  while (((c = fgetc(file)) != EOF)) {
      score[j] = c;
      if(c=='\n' &&  c!=EOF) {
        if((actnumb < tmpnumb) && (i>0)){
          tmpscore = highscore[i-1].score;
          highscore[i-1].score = score;
          highscore[i].score = tmpscore;
        }
        highscore[i].score = score;
        i++;
        score = (char*)malloc(10);
        j=0;
        tmpnumb = actnumb;
        actnumb = atoi(score);
      }
      else {
        j++;
      }
  }
  fclose(file);
  return 0;

}

int write_scores(){
  FILE *file;
  file = fopen("scores.txt", "w");
  for (int i = 0; i < 10; i++) {
    fprintf(file, "%s", highscore[i].score);
  }
  fclose(file);
  return 0;
}

void updatescore(int score) {
  int tmpscore = 0;
  int i = 0;
  bool update = false;

  while((i<10) && (update==false)) {
    tmpscore = atoi(highscore[i].score);
    if((score > tmpscore) && (score!=tmpscore)) {
      sprintf(highscore[i].score, "%d\n", score);
      update = true;
    }
    i++;
  }

}

void initializeEnemy(char type, int i, int j){
  Ennemi *enemytmp;
  enemytmp = (Ennemi*) malloc(sizeof(Ennemi));
  enemytmp->position.y = i;
  enemytmp->position.x = j;
  enemytmp->left = true;
  enemytmp->jump = false;
  enemytmp->keyanm = 1;
  enemytmp->capture = false;
  enemytmp->freeze = false;
  enemytmp->nextEnnemi = NULL;
  enemytmp->currentspeed = 0;
  if(humanplayer.currentlevel == 1)
  {
      enemytmp->speed = 3.0;
  } else {
      enemytmp->speed = 1.5;
  }

  enemytmp->banane = false;
  enemytmp->type = type;
  if(ennemis == NULL)
  {
    ennemis = enemytmp;
  } else {
    Ennemi *enemysearch, *endenemy;
    enemysearch=(Ennemi*)ennemis;
    while(enemysearch!=NULL) {
      endenemy = enemysearch;
      enemysearch = enemysearch->nextEnnemi;
    }
    endenemy->nextEnnemi = enemytmp;
  }
}

void initializeCocoSinge() {
  cocoSinge.position.x = 0;
  cocoSinge.position.y = 10;
  cocoSinge.vies = 3;
  cocoSinge.right = true;
  cocoSinge.jump = false;
  cocoSinge.keyanm = 1;
  cocoSinge.points = 0;
}

void initializeBubble() {
  // Initiaize Bulle
  for (int i = 0; i < 3; i++) {
      resetBubble(i);
  }
}

void initialize_platform(int level)
{
  read_platform(level);
  ennemis = NULL;
  totalbananes = 0;
  initializeCocoSinge();

  for(int i=0; i < H; i++)
  {
    for(int j=0; j<W; j++)
    {
      if(platform[i][j]=='M') {
        cocoSinge.position.x = j;
        cocoSinge.position.y = i;
        cocoSinge.posorigin.x = j;
        cocoSinge.posorigin.y = i;
        platform[i][j]='-';
      }

      if( platform[i][j]=='E') {
        initializeEnemy('E', i, j);
      }

      if( platform[i][j]=='F') {
        initializeEnemy('F', i, j);
      }

      if( platform[i][j]=='B') {
        totalbananes += 1;
      }

    }
  }

  initializeBubble();
}

void animateBulle() {
  for (int i = 0; i < 3; i++) {

      if(bulle[i].active && bulle[i].move) {
        if(cocoSinge.right) {
          bulle[i].position.x+=1;
        } else {
          bulle[i].position.x-=1;
        }
      }

  }
}

void animateEnemy() {
  Ennemi *enemytmp;
  enemytmp = ennemis;
  while(enemytmp!=NULL) {
    if ((!enemytmp->freeze) && (enemytmp->currentspeed > enemytmp->speed)) {
      enemytmp->currentspeed = 0;
      if(enemytmp->left) {
          enemytmp->position.x-=1;
      } else {
          enemytmp->position.x+=1;
      }

      if (enemytmp->keyanm  < 5) {
        enemytmp->keyanm += 1;
      }
      else {
       enemytmp->keyanm = 1;
      }

      int posx = (int)(enemytmp->position.x);
      int posy = (int)(enemytmp->position.y);
       if((platform[posy+1][posx]=='-') || (posx == -1) || (posx > W-1)){
         if(enemytmp->left) {
           enemytmp->position.x+=1;
           enemytmp->left = false;
         } else {
           enemytmp->position.x-=1;
           enemytmp->left = true;
         }
       }
     } else {
       enemytmp->currentspeed += 0.45;
     }
        enemytmp=enemytmp->nextEnnemi;

  }

}

void animateMonkey() {

  if (cocoSinge.keyanm  < 6) {
   cocoSinge.keyanm += 1;
  }
  else {
   cocoSinge.keyanm = 1;
  }
}

 void show_platform(){
   testPassCollide();
   animateMonkey();
   testPassCollide();
   animateBulle();
   testPassCollide();
   animateEnemy();
   testPassCollide();
   displayBackground();

   for(int i=0; i < H; i++)
   {
     for(int j=0; j<W; j++)
     {

       if(platform[i][j]=='P') {
         displayGrass(j, i);
       }

       if(platform[i][j]=='S') {
         displayFloor(j, i);
       }

       if(platform[i][j]=='B') {
         displayBananas(j, i);
       }

       if(platform[i][j]=='C') {
         displayCoinGold(j, i);
       }

     }

   }

   displayMonkey(cocoSinge.position.x, cocoSinge.position.y, cocoSinge.right, cocoSinge.jump, cocoSinge.keyanm);

   // LOOP SNAKE
   Ennemi *enemytmp;
   enemytmp = ennemis;
   while(enemytmp!=NULL) {
     displayEnnemy(enemytmp->type, enemytmp->position.x, enemytmp->position.y, enemytmp->left, enemytmp->keyanm, enemytmp->capture);
     enemytmp=enemytmp->nextEnnemi;
   }

   // LOOP bulle
   for (int i = 0; i < 3; i++) {
       if(bulle[i].active) {
           displayBubble(bulle[i].position.x, bulle[i].position.y, bulle[i].left, bulle[i].keyanm);
       }
   }

   glPushMatrix();
   glLoadIdentity();
   displayHeader(cocoSinge.points, cocoSinge.vies, humanplayer.currentlevel);
   glPopMatrix();
   glutSwapBuffers();
 }

 bool show_win_loose(bool *check){
   if(*check == true) {
     if(totalbananes==0 || cocoSinge.vies == 0) {
         if (cocoSinge.vies == 0) {
           *check = false;
           glLoadIdentity();
           displayYouLose();
         }
         if((cocoSinge.vies >0) && totalbananes == 0) {
           *check = false;

           if(humanplayer.currentlevel==3) {
             humanplayer.currentlevel = 1;
           } else {
             humanplayer.currentlevel += 1;
           }

           humanplayer.score += cocoSinge.points;
           humanplayer.startagain = true;
           glLoadIdentity();
           displayYouWin();

           initialize_platform(humanplayer.currentlevel);
           gameLoaded = true;
         }
         return true;
     }
     else {
         return false;
     }
   } else {
     return false;
   }
 }

  void loading_level(bool refresh) {
    if(!refresh) {
      initialize_platform(humanplayer.currentlevel);
      gameLoaded = true;
      check_show_win_loose = true;
    }

      if(!show_win_loose(&check_show_win_loose) && check_show_win_loose ) {
          show_platform();
      }

  }
