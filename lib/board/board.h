#ifndef _BOARD_H_
#define _BOARD_H_


#include <stdlib.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif


#define BOARD_X_SIZE 10
#define BOARD_Y_SIZE 20


void board_version();
void reset_board(int _board[][BOARD_Y_SIZE]); 
void show_board(int _board[][BOARD_Y_SIZE]);


#endif