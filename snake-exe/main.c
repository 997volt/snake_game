#include <board/board.h>



int main()
{
    board_version();

    int board[BOARD_X_SIZE][BOARD_Y_SIZE];
    start_game(board);
    
    return 0;
}