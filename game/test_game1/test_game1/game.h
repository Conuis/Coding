#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2 //判断边界值时需要用到额外的格子
#define COLS COL+2 //判断边界值时需要用到额外的格子
#define EASY_COUNT 10
void Initboard(char board[ROWS][COLS], int rows, int cols, char set);
void Displayboard(char board[ROWS][COLS], int row, int col);
void Setmine(char mine[ROWS][COLS], int row, int col);
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int Total(char mine[ROWS][COLS], int x, int y);
void DisplayEnd(char mine[ROWS][COLS], char show[ROWS][COLS], int rows, int cols);
void Judgemine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* count);