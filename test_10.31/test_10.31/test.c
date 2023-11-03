#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "contact.h"
void menu()
{
	printf("*******************************\n");
	printf("****  1.ADD      2.DELETE  ****\n");
	printf("****  3.SEARCH   4.SHOW    ****\n");
	printf("****  5.SORT     6.MODIFY  ****\n");
	printf("****  0.EXIT               ****\n");
	printf("*******************************\n");
}
enum Option
{
	Exit,
	Add,
	Delete,
	Search,
	Show,
	Sort,
	Modify
};

int main() {

	int input = 0;
	Contact con;
	InitContact(&con);
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case Add:
			AddContact(&con);
			break;
		case Delete:
			DeleteContact(&con);
			break;
		case Search:
			SearchContact(&con);
			break;
		case Show:
			ShowContact(&con);
			break;
		case Sort:
			SortContact(&con);
			break;
		case Modify:
			ModifyContact(&con);
			break;
		case Exit:
			DestroyContact(&con);
			printf("退出通讯录\n");
		default:
			printf("请重新输入！\n");
			break;
		}
	} while (input);
	return 0;

}