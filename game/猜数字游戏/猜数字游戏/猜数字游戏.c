#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
void game()
{
	int number = rand()%100 + 1;
	int s;
	while (1)
	{
		printf("������һ�����֣�");
		scanf("%d", &s);
		if (s > number)
			printf("�´���\n");
		if (s < number)
			printf("��С��\n");
		if (s == number)
		{
			printf("�¶��ˣ���ϲ�㣡\n");
			break;
		}


	}
}
void print()
{
	printf("********************************\n");
	printf("********* ��������Ϸ ***********\n");
	printf("*********   1.play  ************\n");
	printf("*********   0.exit  ************\n");
	printf("********************************\n");
	printf("�����룺");
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
			printf("��Ϸ������");
			flag = 0;
			break;
		case 1:
			game();
			break;
		default:
			printf("���������룡");
		}
		if (flag == 0)
			break;
	}
	return 0;
}
