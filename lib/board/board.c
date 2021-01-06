#include "board.h"
#include <stdio.h>
#include <time.h>

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
            if(is_point_head(snake, i, j)) printf("@ ");
            else if(is_point_body(snake, i, j)) printf("o ");
            else if(is_point_food(snake, i, j)) printf("X ");
            else printf(". ");
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
    snake->head[0] = 0;
    snake->head[1] = 0;
    food_generate_new(snake);
}

void snake_move(snake_struct * snake)
{
    if(!snake_just_eaten(snake)) snake_move_body(snake);

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

void snake_move_body(snake_struct * snake)
{ 

    for(int i = 0; i < snake->size-2; i++)
    {
        snake->body[i][0] = snake->body[i+1][0];
        snake->body[i][1] = snake->body[i+1][0];
    }    
    
    snake->body[snake->size-1][0] = snake->head[0];
    snake->body[snake->size-1][1] = snake->head[1];
}

void snake_print_head_location(snake_struct * snake)
{
    printf("%d  %d\n", snake->head[0], snake->head[1]);
}

BOOL snake_check_collision(snake_struct * snake)
{
    // wall
    if(snake->head[0] < 0 || snake->head[0] >= BOARD_X_SIZE || snake->head[1] < 0  || snake->head[1] >= BOARD_Y_SIZE )
    {
        printf("wall collision detected at head (%d,%d)", snake->head[0], snake->head[1]);
        return TRUE;
    }

    return FALSE;
}

void food_generate_new(snake_struct * snake)
{
    while(TRUE)
    {
        snake->food[0] = rand()%BOARD_X_SIZE;
        snake->food[1] = rand()%BOARD_Y_SIZE;

        if(is_point_available(snake, snake->food[0], snake->food[1])) break;
    }
}

void snake_check_food(snake_struct * snake)
{
    if(snake->head[0] == snake->food[0] && snake->head[1] == snake->food[1])
    {
        snake_increase_size(snake);
        food_generate_new(snake);
    }
}

void snake_increase_size(snake_struct * snake)
{
    snake->body[snake->size][0] = snake->head[0];
    snake->body[snake->size][1] = snake->head[1];
    snake->size++;
}


BOOL is_point_head(snake_struct * snake, int x, int y)
{
    if(x == snake->head[0] && y == snake->head[1]) return TRUE;
    return FALSE;
}

BOOL is_point_food(snake_struct * snake, int x, int y)
{
    if(x == snake->food[0] && y == snake->food[1]) return TRUE;
    return FALSE;
}

BOOL is_point_body(snake_struct * snake, int x, int y)
{
    for(int i = 0; i < snake->size; i++)
    {
        if(x == snake->body[i][0] && y == snake->body[i][1]) return TRUE;
    }    
    return FALSE;
}

BOOL is_point_available(snake_struct * snake, int x, int y)
{
    return !is_point_head(snake, x, y) && !is_point_body(snake, x, y);
}

BOOL snake_just_eaten(snake_struct * snake)
{
    if(snake->head[0] == snake->body[0][0] && snake->head[1] == snake->body[0][1]) return TRUE;      
    return FALSE;
}