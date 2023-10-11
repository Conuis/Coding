#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("*****************\n");
	printf("**** 1. play ****\n");
	printf("**** 0. exit ****\n");
	printf("*****************\n");
}
void game()
{
	char board[ROW][COL];
	char ret = 0;
	Initboard(board, ROW, COL);//初始化全部是空格
	Displayboard(board, ROW, COL);//打印棋盘

	while (1)
	{
		Playerboard(board, ROW, COL);//玩家下棋
		Displayboard(board, ROW, COL);//打印棋盘
		ret = Determineboard(board, ROW, COL);//判断
		if (ret != 'C')
		{
			break;
		}
		Computerboard(board, ROW, COL);//电脑下棋
		Displayboard(board, ROW, COL);//打印棋盘
		ret = Determineboard(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家获胜\n");

	}
	else if (ret == '0')
	{
		printf("电脑获胜\n");
	}
	else
	{
		printf("平局！");
	}

}
int main() {
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏结束！\n");
			break;
		default:
			printf("输入错误，请重新输入!\n");
		}
	} while (input);
	return 0;

}