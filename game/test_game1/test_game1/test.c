#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("***********************\n");
	printf("*****   1.play   ******\n");
	printf("*****   0.exit   ******\n");
	printf("***********************\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	Initboard(mine, ROWS, COLS,'0');//初始化隐藏棋盘
	Initboard(show, ROWS, COLS, '*');//初始化可视棋盘
	//Displayboard(mine, ROW, COL);
	Setmine(mine, ROW, COL);//布置雷
	//Displayboard(mine, ROW, COL);
	Displayboard(show, ROW, COL);
	Findmine(mine, show, ROW, COL);
}
int main() {
	srand((unsigned int)time(NULL));
	int input = 0;
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
			printf("游戏结束！");
			break;
		default:
			printf("输入有误！请重新输入.");
			break;

		}

	} while (input);

	return 0;

}