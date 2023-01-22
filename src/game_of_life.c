// Copyright 2022 shemich

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define NMAX 100
#define M 80
#define N 25
#define clearscreen() printf("\033[H\033[J")
#define ctrl(x) (x & 0x1F)


void draw(int array[][N], int x, int y);
void readfile(int array[][N], int x, int y);
int tick(int array1[][N], int x, int y, int array2[][N]);
int score(int array[][N], int j, int i);
int swap(int array1[][N], int x, int y, int array2[][N]);
void wellcome();
void counter();

int main(int argc, char * argv[]) {
    int f = 0;
    if (argc != 2) {
        printf("n/a");
        f = 0;
    } else {
        int time;
        wellcome();
        counter();
        time = atoi(argv[1]);
        int y = 25;
        int x = 80;
        int array1[x][y];
        int array2[x][y];
        readfile(array1, x, y);
        printf("\n");
        while (1) {
        clearscreen();
        draw(array1, x, y);
        usleep(time);
        tick(array1, x, y, array2);
        swap(array1, x, y, array2);
        }
    }
    return f;
}

int score(int array[][N], int x, int y) {
    int result = 0;
    int j = 80 + x;
    int i = 25 + y;
    if (array[(j - 1) % 80][(i - 1) % 25]) result += 1;
    if (array[(j - 1) % 80][i % 25]) result += 1;
    if (array[(j - 1) % 80][(i + 1) % 25]) result += 1;
    if (array[j % 80][(i - 1) % 25]) result += 1;
    if (array[j % 80][(i + 1) % 25]) result += 1;
    if (array[(j + 1) % 80][(i - 1) % 25]) result += 1;
    if (array[(j + 1) % 80][i % 25]) result += 1;
    if (array[(j + 1) % 80][(i + 1) % 25]) result += 1;
    return result;
}

int tick(int array1[][N], int x, int y, int array2[][N]) {
    int n;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            n = score(array1, j, i);
            if (array1[j][i] == 1 && (n == 2 || n == 3)) {
                array2[j][i] = 1;
            } else if (array1[j][i] == 0 && n == 3) {
                array2[j][i] = 1;
            } else {
                array2[j][i] = 0;
            }
        }
    }
    return 0;
}

int swap(int array1[][N], int x, int y, int array2[][N]) {
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            array1[j][i] = array2[j][i];
        }
    }
    return 0;
}

void readfile(int array1[][N], int x, int y) {
    char str[2024];
    scanf("%2023s", str);
    int n = 0;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (str[n] == '.') {
                array1[j][i] = 0;
            } else if (str[n] == 'O') {
                array1[j][i] = 1;
            } else {
                j--;
            }
            n++;
        }
    }
}

void draw(int array[][N], int x, int y) {
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (array[j][i]) {
                printf("█");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void wellcome() {
    clearscreen();
    printf("\n\n\n");
    printf("          ____                                               ");
    printf(" ___  \n");
    printf("         /\\  _`\\                        ");
    printf("                    /'___\\ \n");
    printf("         \\ \\ \\L\\_\\     __      ___ ___    ");
    printf("  __         ___ /\\ \\__/ \n");
    printf("          \\ \\ \\L_L   /'__`\\  /' __` __`\\  /'__`\\   ");
    printf("   / __`\\ \\ ,__\\\n");
    printf("           \\ \\ \\/, \\/\\ \\L\\.\\_/\\ \\/\\ ");
    printf("\\/\\ \\/\\  __/     /\\ \\L\\ \\ \\ \\_/\n");
    printf("            \\ \\____/\\ \\__/.\\_\\ \\_\\ ");
    printf("\\_\\ \\_\\ \\____\\    \\ \\____/\\ \\_\\ \n");
    printf("             \\/___/  \\/__/\\/_/\\/_/");
    printf("\\/_/\\/_/\\/____/     \\/___/  \\/_/ \n");
    printf("\n");
    printf("                           __              ___         \n");
    printf("                          /\\ \\       __  /'___\\        \n");
    printf("                          \\ \\ \\     /\\_\\/\\ \\__/   __   \n");
    printf("                           \\ \\ \\ ");
    printf(" __\\/\\ \\ \\ ,__\\/'__`\\ \n");
    printf("                            \\ \\ \\L\\ \\");
    printf("\\ \\ \\ \\ \\_/\\  __/ \n");
    printf("                             \\ \\____/ ");
    printf("\\ \\_\\ \\_\\  \\____\\\n");
    printf("                              \\/___/   \\/_/\\/_/ \\/____/\n");
    usleep(1000000);
}

void counter() {
    clearscreen();
    printf("\n\n\n\n\n\n\n");
    printf("                                      __     \n");
    printf("                                    /'__`\\   \n");
    printf("                                   /\\_\\L\\ \\  \n");
    printf("                                   \\/_/_\\_<_ \n");
    printf("                                     /\\ \\L\\ \\\n");
    printf("                                     \\ \\____/\n");
    printf("                                      \\/___/ \n");
    usleep(1000000);
    clearscreen();
    printf("\n\n\n\n\n\n\n");
    printf("                                       ___     \n");
    printf("                                     /'___`\\   \n");
    printf("                                    /\\_\\ /\\ \\  \n");
    printf("                                    \\/_/// /__ \n");
    printf("                                       // /_\\ \\\n");
    printf("                                      /\\______/\n");
    printf("                                      \\/_____/ \n");
    usleep(1000000);
    clearscreen();
    printf("\n\n\n\n\n\n\n");
    printf("                                       _     \n");
    printf("                                     /' \\    \n");
    printf("                                    /\\_, \\   \n");
    printf("                                    \\/_/\\ \\  \n");
    printf("                                       \\ \\ \\ \n");
    printf("                                        \\ \\_\\\n");
    printf("                                         \\/_/\n");
    usleep(1000000);
}
