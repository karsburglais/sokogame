//includes of standard libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//includes of specific libs
#include "sokobanlib.h"
#include "menulib.h"
#include "gamelib.h"
#include "ranklib.h"

int main() {
    int option;
	char screenSize[13], playerName[RANK_MAX_NAME];

	//set console attributes and settings (screen size, buffer size, console title and status of cursor)
    sprintf(screenSize, "mode %d,%d", SCREEN_WIDTH, SCREEN_HEIGHT + 1);
    system(screenSize);
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) {SCREEN_WIDTH, SCREEN_HEIGHT});
    SetConsoleTitle("                                      <--Crazy Random Sokoban-->                                      ");
    hideCursor();
    SokoMap sokomap;
    sokomap = loadMap(HARD);
    printMap(sokomap);
    getch();
}
