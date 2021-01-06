#ifndef _BOARD_H_
#define _BOARD_H_


#include <stdlib.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif


#define BOARD_X_SIZE 5
#define BOARD_Y_SIZE 5

typedef struct
{
    char direction;
    int head[2];
    int body[BOARD_X_SIZE*BOARD_Y_SIZE][2];
    int size;
    int food[2];
}snake_struct;


void board_version();
void show_board(snake_struct * snake);
void snake_set_direction(snake_struct * snake, char direction);
void snake_init(snake_struct * snake);
void snake_move(snake_struct * snake);
void snake_move_body(snake_struct * snake);
void snake_print_head_location(snake_struct * snake);
BOOL snake_check_collision(snake_struct * snake);
void food_generate_new(snake_struct * snake);
void snake_check_food(snake_struct * snake);
void snake_increase_size(snake_struct * snake);

BOOL is_point_head(snake_struct * snake, int x, int y);
BOOL is_point_food(snake_struct * snake, int x, int y);
BOOL is_point_body(snake_struct * snake, int x, int y);
BOOL is_point_available(snake_struct * snake, int x, int y);
BOOL snake_just_eaten(snake_struct * snake);

#endif