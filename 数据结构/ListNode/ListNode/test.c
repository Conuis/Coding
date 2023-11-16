#define _CRT_SECURE_NO_WARNINGS 1
#include "ListNode.h"

void Test1()
{
	ListNode* s1 = ListCreate();
	ListPushBack(s1, 1);
	ListPushBack(s1, 2);
	ListPushBack(s1, 3);
	ListPushBack(s1, 4);
	ListPrint(s1);

	ListPopBack(s1);
	ListPopBack(s1);
	ListPrint(s1);

	ListPushFront(s1, 10);
	ListPushFront(s1, 20);
	ListPrint(s1);

	//ListPopFront(s1);
	//ListPopFront(s1);
	//ListPopFront(s1);
	//ListPrint(s1);

	ListNode* pos1 = ListFind(s1, 1);
	ListNode* pos2 = ListFind(s1, 2);
	ListInsert(pos1, 13);
	ListInsert(pos2, 53);
	ListPrint(s1);

	ListErase(pos2);
	ListPrint(s1);

	ListDestory(s1);
	ListPrint(s1);


}
int main(){
	Test1();
	return 0;

}