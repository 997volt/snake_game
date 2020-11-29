#ifndef _BOARD_H_
#define _BOARD_H_

#define B_SIZE 12

void board_version();
int reset_board(int _board[][B_SIZE]); 
void show_board(int _board[][B_SIZE]);

#endif