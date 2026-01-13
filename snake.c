#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define WIDTH 40
#define HEIGHT 20
#define MAX_LENGTH 100

typedef struct
{
    int x[MAX_LENGTH];
    int y[MAX_LENGTH];
    int length;
    int directionx;
    int directiony;
} Snake;

Snake snake;
bool gameOver = FALSE;

char screenBuffer[HEIGHT][WIDTH];

void inicialize();

int main(void)
{
    inicialize();

}

void inicialize()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    start_color();

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);

    snake.length = 1;
    snake.x[0] = WIDTH / 2;
    snake.y[0] = HEIGHT / 2;
    snake.directionx = 1;
    snake.directiony = 0;

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1)
            {
                screenBuffer[i][j] = '#';
            }
            else
            {
                screenBuffer[i][j] = ' ';
            }
        }
    }
}