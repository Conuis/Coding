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
	Initboard(mine, ROWS, COLS,'0');//��ʼ����������
	Initboard(show, ROWS, COLS, '*');//��ʼ����������
	//Displayboard(mine, ROW, COL);
	Setmine(mine, ROW, COL);//������
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
		printf("�����룺");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ������");
			break;
		default:
			printf("������������������.");
			break;

		}

	} while (input);

	return 0;

}