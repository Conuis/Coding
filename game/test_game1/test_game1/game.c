#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//初始化棋盘
void Initboard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i;
	int j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
//打印棋盘
void Displayboard(char board[ROWS][COLS], int row, int col)
{
	int i;
	int j;
	for (i = 0; i <= row; i++)
	{
		if (i == 0)
			printf("  ");
		else
			printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
//布置雷
void Setmine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}

	}
}
//统计雷的个数
//int Total(char mine[ROWS][COLS], int x, int y)
//{
//	return mine[x - 1][y - 1]
//		+ mine[x - 1][y]
//		+ mine[x - 1][y + 1]
//		+ mine[x][y - 1]
//		+ mine[x][y + 1]
//		+ mine[x + 1][y - 1]
//		+ mine[x + 1][y]
//		+ mine[x + 1][y + 1]- 8 * '0';
//}

int Total(char mine[ROWS][COLS], int x, int y)
{
	int sum = 0;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (mine[x + i][y + j] == '1')
			{
				sum++;
			}
		}
	}
	return sum;
}
//排查雷
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = row * col - EASY_COUNT;
	while (1)
	{
		printf("请输入一个坐标(排查雷)：");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾你被炸死了！\n");
				//Displayboard(mine, ROW, COL);
				DisplayEnd(mine, show, ROW, COL);
				break;
			}
			else
			{
				//int total = Total(mine, x, y);
				//show[x][y] = total + '0';
				//count--;
				Judgemine(mine, show, x, y,&count);
				Displayboard(show, ROW, COL);
			}
		}
		else
		{
			printf("坐标输入有误！请重新输入！");
		}
		if (count == 0)
		{
			printf("恭喜你！排雷成功！\n");
			DisplayEnd(mine, show, ROW, COL);
			break;
		}
	}
}

//判断周围是否为0
void Judgemine(char mine[ROWS][COLS],char show[ROWS][COLS],int x,int y,int *count)
{
	int i;
	int j;
	if (x >= 1 && x <= 9 && y >= 1 && y <= 9 && mine[x][y] == '0' && show[x][y] == '*')
	{
		//mine[x][y] = '2';
		if (Total(mine, x, y))
		{
			show[x][y] = Total(mine, x, y) + '0';
			(*count)--;
		}
		else
		{
			show[x][y] = ' ';
			(*count)--;
			for (i = -1; i <= 1; i++)
			{
				for (j = -1; j <= 1; j++)
				{
					Judgemine(mine, show, x + i, y + j, count);
				}
			}
		}
	}

}
//打印结局
void DisplayEnd(char mine[ROWS][COLS], char show[ROWS][COLS], int rows, int cols)
{
	{
		int i = 0;
		int j = 0;
		for (i = 0; i <= rows; i++)
		{
			printf("%d ", i);
		}
		printf("\n");
		for (i = 1; i <= rows; i++)
		{
			printf("%d ", i);
			for (j = 1; j <= cols; j++)
			{
				if (mine[i][j] == '1')//如果是雷就打印出来
				{
					mine[i][j] = '@';
					printf("%c ", mine[i][j]);//与打印棋盘唯一不同之处
				}
				else
				{
					printf("%c ", show[i][j]);
				}
			}
			printf("\n");
		}
		printf("\n");
	}
}