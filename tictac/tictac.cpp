#include <iostream>
#include <stdio.h>

class Player {
    int posx, posy;
public:
    Player(int,int);
};

Player::Player(int x, int y){
    posx = x;
    posy = y;
}

void clear_scr(){
    printf("\033c");
}

int calc_dim(int cell_number, int cell_size){
    return cell_number*cell_size;
}

void draw(){
    clear_scr();

    int cell_size = 4;
    int cell_num = 3;
    int dim = calc_dim(cell_num, cell_size);
    for (int y = 0; y < dim+1; y++){
        for (int x = 0; x < dim+1; x++){
            if (y%cell_size == 0){
                printf("#");
            }
            //else if (y%(cell_size/2) == 0){
                //printf("p");
            //}
            else if (x%cell_size == 0){
                printf("#");
            }

            // Player position
            else if (x%(cell_size/2) == 0 && y%(cell_size/2) == 0){
                printf("p");
            }

            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}


int main() {
    Player p1(5, 3);
    Player p2(3, 5);
    int width = 9;
    int height = 9;
    bool game_over = false;

    // We only want to draw each time a move (movement/place o or x) is made
    draw();
}
