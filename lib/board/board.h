#ifndef _BOARD_H_
#define _BOARD_H_


#include <stdlib.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif


#define BOARD_X_SIZE 10
#define BOARD_Y_SIZE 20


void board_version();
void reset_board(int _board[][BOARD_Y_SIZE]); 
void show_board(int _board[][BOARD_Y_SIZE]);

typedef struct
{
    char direction;
    int head[2];
    int body[BOARD_X_SIZE*BOARD_Y_SIZE][2];
}snake_struct;

void snake_set_direction(snake_struct * snake, char direction);
void snake_init(snake_struct * snake);
void snake_move_head(snake_struct * snake);

#endif