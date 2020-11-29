#ifndef _BOARD_H_
#define _BOARD_H_

#define BOARD_X_SIZE 10
#define BOARD_Y_SIZE 20

void board_version();
int reset_board(int _board[][BOARD_Y_SIZE]); 
void show_board(int _board[][BOARD_Y_SIZE]);

#endif