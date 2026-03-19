#include <ncurses.h>

#define GAME_WIDTH 50
#define GAME_HEIGHT 20

// Snake segment
typedef struct {
    int x, y;
} Body;

int main(void)
{
    // Setup
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    timeout(100);

    // Setup colors
    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        init_pair(2, COLOR_CYAN, COLOR_BLACK);
    }

    Body snake[100];
    int size = 5;

    // Init head
    snake[0].x = GAME_WIDTH / 2;
    snake[0].y = GAME_HEIGHT / 2;

    // Init body
    for (int i = 1; i < size; i++)
    {
        snake[i].x = snake[0].x - i;
        snake[i].y = snake[0].y;
    }

    int direction = KEY_RIGHT;

    // Game loop
    while (1)
    {
        clear();

        // Render Border
        attron(COLOR_PAIR(2));
        for (int i = 0; i <= GAME_WIDTH; i++) {
            mvprintw(0, i, "#");          
            mvprintw(GAME_HEIGHT, i, "#");
        }
        for (int i = 0; i <= GAME_HEIGHT; i++) {
            mvprintw(i, 0, "#");
            mvprintw(i, GAME_WIDTH, "#");
        }
        attroff(COLOR_PAIR(2));

        // Render Snake
        attron(COLOR_PAIR(1));
        for (int i = 0; i < size; i++) {
            if (i == 0) {
                mvprintw(snake[i].y, snake[i].x, "@");
            } else {
                mvprintw(snake[i].y, snake[i].x, "o");
            }
        }
        attroff(COLOR_PAIR(1));

        refresh();

        // Input
        int key = getch();
        if (key != ERR)
        {
            if (key == 'q' || key == 'Q')
            {
                break;
            }
            direction = key;
        }

        // Update body
        for (int i = size - 1; i > 0; i--) {
            snake[i] = snake[i - 1];
        }

        // Update head
        switch (direction) {
            case KEY_UP:    snake[0].y--; break;
            case KEY_DOWN:  snake[0].y++; break;
            case KEY_LEFT:  snake[0].x--; break;
            case KEY_RIGHT: snake[0].x++; break;
        }
    }

    // Exit
    endwin();
    return 0;
}