#include "board.h"
#include <stdio.h>

void board_version()
{
    printf("board library version = %.1f\n", BOARD_VERSION);
}

void show_board(snake_struct * snake)
{
    printf("\n");
    for(int i = 0; i < BOARD_X_SIZE; i++)
    {
        for(int j = 0; j < BOARD_Y_SIZE; j++)
        {
            if(snake->head[0] == i && snake->head[1] == j)
                printf("x ");
            else
                printf("o ");
        }
        printf("\n");
    }
    printf("\n");
}

void snake_set_direction(snake_struct * snake, char direction)
{
    if (direction == 'U' || direction == 'D' ||direction == 'R' ||direction == 'L')
        snake->direction = direction;
}

void snake_init(snake_struct * snake)
{
    snake->head[0] = 3;
    snake->head[1] = 4;
}

void snake_move_head(snake_struct * snake)
{
    switch (snake->direction)
    {
    case 'U':
        snake->head[0]--;
        break;
    case 'D':
        snake->head[0]++;
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

void snake_print_head_location(snake_struct * snake)
{
    printf("%d  %d\n", snake->head[0], snake->head[1]);
}

BOOL snake_check_wall_collision(snake_struct * snake)
{
    if(snake->head[0] < 0 || snake->head[0] >= BOARD_X_SIZE || snake->head[1] < 0  || snake->head[1] >= BOARD_Y_SIZE )
    {
        printf("wall collision detected at head (%d,%d)", snake->head[0], snake->head[1]);
        return TRUE;
    }

    return FALSE;
}
