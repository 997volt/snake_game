#include <board/board.h>
#include <port/port.h>

int main()
{
    // variables setup
    snake_struct snake;
    HANDLE com_handle = com_open(4);

    snake_init(&snake);

    // moves loop
    for(int i = 0; i < 100; i++)
    {
        char dir = * com_read(com_handle);
        if(i%2 == 0)
        {
            snake_set_direction(&snake, dir);
            snake_move_head(&snake);
            show_board(&snake);
        }
    }

    CloseHandle(com_handle);

    return 0;
}