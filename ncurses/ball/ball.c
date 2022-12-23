#include <ncurses.h>
#include <unistd.h>

#define DELAY 30000

int main(int argc, char *argv[]) {
    int x = 0, y = 0, max_x = 0, max_y = 0, next = 0, dir = 1;

    initscr();
    noecho();
    curs_set(FALSE);


    while(1){
        getmaxyx(stdscr, max_y, max_x);
        clear();
        mvprintw(y, x, "o");
        refresh();

        usleep(DELAY);

        next += dir;
        if(next >= max_x || next <= 0){
            dir *= -1;
        }
        x += dir;
    }

    endwin(); // Restore normal terminal behavior
    return 0;
}