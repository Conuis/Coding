#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void Initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void Displayboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

void Playerboard(char board[ROW][COL], int row, int col)
{
	int a;
	int b;
	while (1)
	{
		printf("请玩家输入坐标：");
		scanf("%d%d", &a, &b);
		if (a >= 1 && a <= row && b >= 1 && b <= row)
		{
			if (board[a - 1][b - 1] == ' ')
			{
				board[a - 1][b - 1] = '*';

				break;
			}
			else
			{
				printf("坐标已被占用，请重新输入！\n");
			}
		}
		else
			printf("坐标输入非法！请重新输入！\n");

	}
}
void Computerboard(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋\n");
	int a;
	int b;
	while (1)
	{
		a = rand() % row;
		b = rand() % col;
		if (board[a][b] == ' ')
		{
			board[a][b] = '0';
			break;
		}
	}

}
//判断是否满棋子
int Fullboard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
//判断棋子
char Determineboard(char board[ROW][COL], int row, int col)
{
	//返回C -- 继续
	//返回* -- 玩家赢
	//返回O -- 电脑赢
	//返回P -- 平局
	int i;
	int j;
	//判断行
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j] != ' ')
			{
				return board[i][j];
			}

		}
		/*if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1]!=' ')
		{
			return board[i][1];
		}*/

	}
	//判断列
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < row; j++)
		{
			if (board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j] && board[i][j] != ' ')
			{
				return board[i][j];
			}

		}
		/*if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}*/

	}
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < row; j++)
		{
			if (i < col - 2 && j < row - 2)
			{
				if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] && board[i][j] != ' ')
				{
					return board[i][j];
				}
			}
		}
		/*if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		{
			return board[1][1];
		}*/

	}
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < row; j++)
		{
			if (i < col - 2 && j > row - 2)
			{
				if (board[i][j] == board[i + 1][j - 1] && board[i + 1][j - 1] == board[i + 2][j - 2] && board[i][j] != ' ')
				{
					return board[i][j];
				}
			}
		}
		/*	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
			{
				return board[1][1];
			}*/

	}
	if (Fullboard(board, ROW, COL))
	{
		return 'P';
	}
	return 'C';
}