#include <board/board.h>


int main()
{
    board_version();

    int board[B_SIZE][B_SIZE];

    reset_board(board);
    show_board(board);

    return 0;
}