#define RANK_MAX_NAME 50

typedef struct Player {
    char name[RANK_MAX_NAME];
    float score;
}Player;

float calcScore(int moves, int time, int level) {
    return ((1000.0 * pow((float)level, (float)3))/((float)moves + ((float)time/2.0)));
}

void addToRank(Player gamer) {
    FILE* arq;
    Player score;

    arq = fopen("highscore.bin", "ab");                      //open in "ab" to create an empty file if it doesn't exist
    fclose(arq);

    arq = fopen("highscore.bin", "r+b");
    while(fread(&score, sizeof(Player), 1, arq)) {           //read score by score
        if(score.score < gamer.score) {                      //if player score > any score
            fseek(arq, -sizeof(Player), SEEK_CUR);
            fwrite(&gamer, sizeof(Player), 1, arq);          //replace for gamer score
            fflush(arq);
            gamer = score;                                   //and gamer score = old score to move the next scores down
        }
    }
    fwrite(&gamer, sizeof(Player), 1, arq);                  //print last score
    fclose(arq);
}
