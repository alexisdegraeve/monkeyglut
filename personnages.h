#ifndef _PERSONNAGES_
#define _PERSONNAGES_
#include <stdbool.h>

int H;
int W;
int maxH;
int maxW;

struct Coord {
  GLfloat x;
  GLfloat y;
};

struct Singe {
  struct Coord position;
  struct Coord posorigin;
  int vies;
  int points;
  bool right;
  bool jump;
  int keyanm;
};

struct Singe cocoSinge = {
  {
   .x = 0,
   .y = 10
  },
  .vies = 3,
  .points = 0,
  .right = true,
  .jump = false,
  .keyanm = 1
};

typedef struct Ennemi {
  struct Coord position;
  bool capture;
  bool left;
  bool jump;
  int keyanm;
  bool freeze;
  float currentspeed;
  float speed;
  bool banane;
  char type; // Type of ennemi 'E' => Serpent , 'F' => Herisson
  struct Ennemi *nextEnnemi;
}Ennemi ;


typedef struct Bulle {
  struct Coord position;
  int state;
  int keyanm;
  bool active;
  bool move;
  bool left;
  int timer;
}Bulle ;

char **platform;
void *ennemis;
Bulle bulle[3];
int totalbananes;

#endif
