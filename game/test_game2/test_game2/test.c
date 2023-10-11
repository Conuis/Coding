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
	Initboard(board, ROW, COL);//��ʼ��ȫ���ǿո�
	Displayboard(board, ROW, COL);//��ӡ����

	while (1)
	{
		Playerboard(board, ROW, COL);//�������
		Displayboard(board, ROW, COL);//��ӡ����
		ret = Determineboard(board, ROW, COL);//�ж�
		if (ret != 'C')
		{
			break;
		}
		Computerboard(board, ROW, COL);//��������
		Displayboard(board, ROW, COL);//��ӡ����
		ret = Determineboard(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("��һ�ʤ\n");

	}
	else if (ret == '0')
	{
		printf("���Ի�ʤ\n");
	}
	else
	{
		printf("ƽ�֣�");
	}

}
int main() {
	int input;
	srand((unsigned int)time(NULL));
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
			printf("��Ϸ������\n");
			break;
		default:
			printf("�����������������!\n");
		}
	} while (input);
	return 0;

}