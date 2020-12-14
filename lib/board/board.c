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
    if (direction == 'U' || direction == 'D' ||direction == 'R' ||direction == 'L')
        snake->direction = direction;
}

void snake_init(snake_struct * snake)
{
    snake->head[0] = 3;
    snake->head[1] = 4;
}

void move_snake_head(snake_struct * snake)
{
    switch (snake->direction)
    {
    case 'U':
        snake->head[0]++;
        break;
    case 'D':
        snake->head[0]--;
        break;
    case 'L':
        snake->head[1]--;
        break;
    case 'R':
        snake->head[1]++;
        break;     
    default:
        break;
    }
}
