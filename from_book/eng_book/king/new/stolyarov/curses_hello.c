#include<curses.h>
#include<unistd.h>

const char message[] = "Hello, world!";
enum {delay_duration = 5};


int main(void)
{
    /* for rows and colums of our terminal */
    int row, col;
    
    /* initializng ncurses library */    
    initscr();

    /* getting rows and cols of our standart screen(stdscr) terminal */
    getmaxyx(stdscr, row, col);

    /* moving to particular position on the sctreen of terminal (in this case moving to the center) */    
    move(row/2, (col - (sizeof(message) - 1)) / 2);

    /* displaying our message */
    addstr(message);

    /* hidding cursor from user */
    curs_set(0);

    /* making screen available to show our message */
    refresh();
    
    /* sleeping 5 sec */
    sleep(delay_duration);

    /* ending work with ncurses library */
    endwin();

    return 0;
}
