#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include "loadMap.h"
#include "controldisplay.h"

bool gameLoaded = false;

void displayCurrentScreen() {
  switch (currentScreen)	{
    case 0:
      selectMainMenu();
      break;
    case 1:
      selectGame();
      break;
    case 2:
      selectRules();
      break;
    case 3:
      selectHighScores();
      break;
    case 27 /* Esc */:
      exit(1);
      break;
  }
}

void selectMainMenu() {
  glLoadIdentity();
  displayMainMenu();
}

void selectGame() {
  loading_level(gameLoaded);
}

void selectRules() {
  displayRules();
}

void selectHighScores() {
  displayHighScores(highscore);
}
