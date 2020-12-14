#include <board/board.h>
#include <port/port.h>

int main()
{
    // variuables setup
    int board[BOARD_X_SIZE][BOARD_Y_SIZE];
    snake_struct snake;
    HANDLE com_handle = com_open(4);

    reset_board(board);

    // moves loop
    for(int i = 0; i < 10; i++)
    {
        printf(com_read(com_handle));
        system("@cls||clear");
    }

    CloseHandle(com_handle);

    return 0;
}