#include<ncurses.h>

int main(void){
    char text1[] = "Oh give me a clone!\n";
    char text2[] = "Yes a clone of my own!";
    initscr();
    addstr(text1);
    addstr(text2);
    move(2,0);
    addstr("With the Y chromosome changed to the X."); //https://www.youtube.com/watch?v=hAtz2rO-E_0 - "This was very very funny in the 70's I'm assuming", wtaf, nerds are the worst sometimes

    refresh();
    getch();

    endwin();
    return 0;
}

//why is it so easy for me to be pulled out of what im doing and be so utterly reviled
//that i lose all motivation to continue also I know i pirated this book but what the fuck
//wtaf would you think oh this is a funny thing to put in my book -_- Im going on twitch and making some food fuck this