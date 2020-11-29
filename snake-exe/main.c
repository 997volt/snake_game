#include <board/board.h>


int main()
{
    board_version();

    int board[BOARD_X_SIZE][BOARD_Y_SIZE];

    reset_board(board);
    show_board(board);

    return 0;
}