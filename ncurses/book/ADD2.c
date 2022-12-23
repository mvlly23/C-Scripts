#include <ncurses.h>

int main(){
    char text1[] = "I am not going to answer any of your questions.\n";
    char text2[] = "Here is a transmisoginistic comment, self aware jab, self pity.";

    initscr();
    addstr(text1);
    addstr(text2);
    refresh();
    getch();

    endwin();
    return 0;
}