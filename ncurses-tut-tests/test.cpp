#include <iostream>
#include <ncurses.h>

int main(){
    char input;

    initscr();
    printw("Hello world");
    input = getch();
    //std::cout << std::endl;
    //std::cout << "custom input: " << input << std::endl;
    refresh();
    endwin();
    return 0;
}
