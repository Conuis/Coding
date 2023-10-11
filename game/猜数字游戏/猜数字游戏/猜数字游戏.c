#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
void game()
{
	int number = rand()%100 + 1;
	int s;
	while (1)
	{
		printf("请输入一个数字：");
		scanf("%d", &s);
		if (s > number)
			printf("猜大了\n");
		if (s < number)
			printf("猜小了\n");
		if (s == number)
		{
			printf("猜对了！恭喜你！\n");
			break;
		}


	}
}
void print()
{
	printf("********************************\n");
	printf("********* 猜数字游戏 ***********\n");
	printf("*********   1.play  ************\n");
	printf("*********   0.exit  ************\n");
	printf("********************************\n");
	printf("请输入：");
}
int main()
{
	while (1)
	{
		int a;
		int flag = 1;
		print();
		srand((unsigned int)time(NULL));
		scanf("%d", &a);
		switch (a)
		{
		case 0:
			printf("游戏结束！");
			flag = 0;
			break;
		case 1:
			game();
			break;
		default:
			printf("请重新输入！");
		}
		if (flag == 0)
			break;
	}
	return 0;
}
