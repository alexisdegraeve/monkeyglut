#ifndef _GAME_
#define _GAME_

struct Player {
  char *name;
  int currentlevel;
  int score;
  bool startagain;
};

struct Player humanplayer = {
  .name = "human",
  .currentlevel = 1,
  .score = 0,
  .startagain = false
};

#endif
