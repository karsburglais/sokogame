#define MAP_MAX_NAME 50

#define EASY (Level) {"nivel1.txt", 1}
#define MEDIUM (Level) {"nivel2.txt", 2}
#define HARD (Level) {"nivel3.txt", 3}

typedef struct Level {
    char mapName[MAP_MAX_NAME];
    int difficulty;
} Level;

typedef struct SokoMap {
    Level gameLevel;
    Pixel* gameMap;
}SokoMap;

SokoMap loadMap(Level level) {
    SokoMap sokoMap;
    sokoMap.gameLevel = level;
    FILE* arq;
    char line[MAP_WIDTH + 2];
    int l, c;
    sokoMap.gameMap = malloc(sizeof(Pixel) * GAME_WIDTH * GAME_HEIGHT);

    arq = fopen(level.mapName, "r");
    if(!arq) {
        printf("Erro ao carregar mapa!");
        return (SokoMap) {};
    }

    for(l = 0; l < MAP_HEIGHT; l++) {
        if(fgets(line, MAP_WIDTH + 2, arq)) {
            removeNewLine(line);
            for(c = 0; c < MAP_WIDTH; c++) {         ///VER MANIPULAÇAO ALGEBRICA
                *(sokoMap.gameMap) = getPixel(line[c]);
                *(sokoMap.gameMap) = getPixel(line[c]);
                *(sokoMap.gameMap) = getPixel(line[c]);
                *(sokoMap.gameMap) = getPixel(line[c]);
            }
        } else {
            printf("Erro ao carregar mapa!");
            return (SokoMap) {};
        }
    }
    return sokoMap;
}

void printMap(SokoMap sokoMap) {
    Pixel pix;
    unsigned char screenMap[SCREEN_WIDTH * SCREEN_HEIGHT + 1];
    int i, j, k, l;

    for(i = 0, j = 0, k = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++, j++, k++) {
        if (i == 5 * SCREEN_WIDTH)
            k = 0;
        if (j == SCREEN_WIDTH)
            j = 0;
        if (i < 5 * SCREEN_WIDTH) {
            screenMap[i] = ' ';
        } else {
            if(j < GAME_WIDTH) {
                screenMap[i] = sokoMap.gameMap[k].c;
            } else {
                k--;
                screenMap[i] = ' ';
            }
        }
    }
    screenMap[i] = '\0';
    printf(screenMap);
}
