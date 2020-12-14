#include <board/board.h>


int main()
{
    board_version();

    int board[BOARD_X_SIZE][BOARD_Y_SIZE];
    snake_struct snake;
    HANDLE com_handle = com_open(4);
    int message_size = 0;

    reset_board(&board);

    for(int i = 0; i < 10; i++)
    {
        char *serial_read = com_read(com_handle);
        system("@cls||clear");
    }

    show_board(&board);

    start_game(board);

    CloseHandle(com_handle);

    return 0;
}