#include "board.h"
#include <stdio.h>

void board_version()
{
    printf("board library version = %.1f\n", BOARD_VERSION);
}

void reset_board(int _board[][BOARD_Y_SIZE])
{
    for(int i = 0; i < BOARD_X_SIZE; i++)
    {
        for(int j = 0; j < BOARD_Y_SIZE; j++)
        {
            _board[i][j] = 0;
        }
    }
}

void show_board(int _board[][BOARD_Y_SIZE])
{
    printf("\n");
    for(int i = 0; i < BOARD_X_SIZE; i++)
    {
        for(int j = 0; j < BOARD_Y_SIZE; j++)
        {
            printf("%d ", _board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void set_snake_direction(snake_struct * snake, char direction)
{
    snake->direction = direction;
}
