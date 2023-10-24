#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define ROW 6
#define COL 6
void Initboard(char board[ROW][COL], int row, int col);
void Displayboard(char board[ROW][COL], int row, int col);
void Playerboard(char board[ROW][COL], int row, int col);
void Computerboard(char board[ROW][COL], int row, int col);
char Determineboard(char board[ROW][COL], int row, int col);
int Fullboard(char board[ROW][COL], int row, int col);