#ifndef _MENU_
#define _MENU_
#include <stdbool.h>

int currentScreen;
bool gameLoaded;

void displayCurrentScreen();
void selectMainMenu();
void selectRules();
void selectHighScores();
void selectGame();

#endif
