#include <iostream>
#include <vector>
#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h> // srand, rand
#include <time.h>



struct point {
    char player;
    int posx;
    int posy;
};

struct player {
    char id;
    int posx;
    int posy;
};

char turn_manager (char turn, char p1_id, char p2_id){
    if (turn == p1_id){
        turn = p2_id;
    } else {
        turn = p1_id;
    }
    return turn;
}

int calc_dim(int cell_number, int cell_size){
    return cell_number*cell_size;
}

std::vector<point> make_points(int dim, int cell_size){
    std::vector<point> points;
    for(int y = 0; y <= dim; y++) {
        for(int x = 0; x <= dim; x++){
            if (x%(cell_size/2) == 0 && y%(cell_size/2) == 0
                    && x%cell_size != 0 && y%cell_size != 0){
                //point p;
                point p = {' ', x, y};
                points.push_back(p);
            }
        }
    }
    return points;
}

struct player controller (struct player p, char input, int cell_size, int dim){
    if (input == 'w' && p.posy >= cell_size)
        p.posy -= cell_size;
    else if(input == 's' && p.posy <= dim + cell_size)
        p.posy += cell_size;
    else if (input == 'a' && p.posx >= cell_size)
        p.posx -= cell_size;
    else if (input == 'd' && p.posx <= dim+ + cell_size)
        p.posx += cell_size;
    
    return p;
}

std::vector<point> points_manager(std::vector<point> points, struct player p){
    for (int i = 0; i < points.size(); i++){
        if (points[i].posx == p.posx && points[i].posy == p.posy
                && points[i].player == ' ') {
            points[i].player = p.id;
        }
        else {
            printw("Something went wrong");
        }
    }
    return points;
}

void draw(std::vector<point> points, char turn, struct player p1,
            struct player p2, int dim, int cell_size, bool game_over){

    int point_index = 0;

    for (int y = 0; y <= dim; y++){
        for (int x = 0; x <= dim; x++){
            if (y%cell_size == 0){
                printw("#");
            }
            else if (x%cell_size == 0){
                printw("#");
            }

            // Player position
            else if (x%(cell_size/2) == 0 && y%(cell_size/2) == 0){
                // if cell empty, print the player instead else print
                if (y == p1.posy && x == p1.posx && turn == p1.id && !game_over){
                    printw("1");
                    point_index++;
                } 
                else if (y == p2.posy && x == p2.posx && turn == p2.id && !game_over){
                    printw("2");
                    point_index++;
                }
                else {
                    printw("%c", points[point_index].player | A_BLINK);
                    point_index++;
                }
            }

            else {
                printw(" ");
            }
        }
        printw("\n");
    }
}

void print_vstate(std::vector<point> points){
    for (int i = 0; i < points.size(); i++){
        printw("C: %c, Y: %d, X: %d\n", points[i].player, points[i].posy, points[i].posx);
        //printw("X: %i\n", points[i].posx);
        //printw("Y: %i\n\n", points[i].posy);
    }
}

bool is_game_over(std::vector<point> points){
    for (int i = 0; i < points.size(); i++){
        if (points[i].player == ' ')
            return false;
    }
    return true;
}

std::vector<point> ai_controller(std::vector<point> points, struct player p){
    // init random seed
    srand(time(NULL));

    int placed = 0;

    do {
        int rand_index = rand() % points.size() + 0;
        printw("points.size(): %i", points.size());
        printw("rand_index: %i\n", rand_index);
        refresh();
        if (points[rand_index].player == ' ') {
            points[rand_index].player = p.id;
            placed = 1;
        }
    } while (placed == 0);
    return points;
}

int main() {
    int width = 9;
    int height = 9;
    int cell_size = 4;
    int cell_num = 3;
    int dim = calc_dim(cell_num, cell_size);
    bool game_over = false;

    char turn;

    std::vector<point> points = make_points(dim, cell_size);
    // print vector data
    // Initialize data for game.
    player p1 = {'X', cell_size/2, cell_size/2};
    player p2 = {'O', cell_size/2, cell_size/2};

    turn = turn_manager(turn, p1.id, p2.id);
    
    initscr();
    printw("Player 1 is X\n");
    printw("Player 2 is O\n\n");
    draw(points, turn, p1, p2, dim, cell_size, game_over);
    refresh();

    while(!game_over){
        //getch();

        print_vstate(points);
        char input;
        if (turn == p1.id){
            input = getch();
            if (input == 'p') {
                points = points_manager(points, p1);
                turn = turn_manager(turn, p1.id, p2.id);
            }
            else {
                p1 = controller(p1, input, cell_size, cell_num);
            }
        } 
        else if (turn == p2.id){
            //points = points_manager(points, p2);
            points = ai_controller(points, p2);
            turn = turn_manager(turn, p1.id, p2.id);
        }
        //else {
            //if (turn == p1.id){
            //}
        //}

        clear();
        printw("Player 1 is X\n");
        printw("Player 2 is O\n\n");
        draw(points, turn, p1, p2, dim, cell_size, game_over);
        game_over = is_game_over(points);
        refresh();
        //getch();
    }

    if (game_over){
        clear();
        draw(points, turn, p1, p2, dim, cell_size, game_over);
        getch();
    }

    endwin();
    return 0;
}
