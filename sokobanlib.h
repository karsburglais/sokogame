#define DEFAULT_COLOR 0x70    //BG black and text off-white -- standard console settings
#define DEFAULT_BG_COLOR 7    //BG black

#define SCREEN_WIDTH 70       //define size of screen
#define SCREEN_HEIGHT 25

#define GAME_WIDTH 50
#define GAME_HEIGHT 20

#define GAME_WBEG 0
#define GAME_HBEG 5

#define MAP_WIDTH 25          //define size of txt map
#define MAP_HEIGHT 10

#define WALL (Pixel) {'x', 219, 0x07}
#define SPACE (Pixel) {'0', ' ', 0x07}
#define PLAYER (Pixel) {'1', 219, 0x0B}
#define WRONGBLOCK (Pixel) {'2', 219, 0x0C}
#define RIGHTBLOCK (Pixel) {'3', 219, 0x0A}

#define PIXELS {WALL, PLAYER, WRONGBLOCK, RIGHTBLOCK, SPACE}
#define N_PIXELS 5

typedef struct Pixel {
    char id;
    unsigned char c;
    int color;
} Pixel;

void setColor(int color) { //set BG and text colors
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void setBGColor(char c) { //set BG color
    char color[9] = "COLOR 70";        //color BG == off-white, color text == black
    color[6] = c;                      //color BG == c, color text == black
    if(c == '0')          //if BG color == black, change text color to off-white
        color[7] = '7';
    system(color);
}

void resetColor() {       //set BG and text colors to black and off-white (standard)
    setColor(0x07);
}

void printPixel(Pixel p) {  //set color to pixel color and print caracter of print
    setColor(p.color);
    fwrite(&(p.c), 1, 1, stdout);
}

Pixel getPixel(char id) {    //get and int and see which Pixel has this id code
    Pixel pxs[N_PIXELS] = PIXELS;
    int i;

    for(i = 0; i < N_PIXELS; i++)
        if(pxs[i].id == id)
            return pxs[i];
    return SPACE;
}

void setCursor(int x, int y) {
	COORD coordinate = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

void hideCursor() {
   CONSOLE_CURSOR_INFO info = {100, FALSE};
   SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

int toHexadecimal(char c, int error) {    //convert digit from hex to dec
    if('0' <= c && c <= '9') {
        return c - '0';
    } else if('a' <= tolower(c) && tolower(c) <= 'f') {
        return tolower(c) - 'a' + 10;
    }
    return error;
}

void removeNewLine(char *s) {    //remove '\n' of fgets
    int i = 0, k;
    while(*(s + i) != '\0') {
        if(*(s + i) == '\n') {
            k = i;
            while(*(s + k - 1) != '\0') {
                *(s + k) = *(s + k + 1);
                k++;
            }
        }
        i++;
    }
}

void waitVK(int VK) {              //wait a key to be pressed
    while(!GetAsyncKeyState(VK)) {
        Sleep(150);
    }
    Sleep(150);                    //delay because of human delay
}

