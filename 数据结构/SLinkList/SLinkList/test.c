#define _CRT_SECURE_NO_WARNINGS 1
#include "SLlist.h"
void Test1()
{
	SLNode* s1 = NULL;
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLPrint(s1);
}

void Test2()
{
	SLNode* s1 = NULL;
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLPushFront(&s1, 1);
	SLPushFront(&s1, 11);
	SLPushFront(&s1, 1123);
	SLPopBack(&s1);
	SLPopFront(&s1);
	SLPrint(s1);
}

void Test3()
{
	SLNode* s1 = NULL;
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	//SLPushFront(&s1, 1);
	//SLPushFront(&s1, 11);
	//SLPushFront(&s1, 1123);
	//SLPopBack(&s1);
	//SLPopFront(&s1);
	SLNode* pos = SListFind(s1, 1);
	SLNode* pos2 = SListFind(s1, 3);
	//SLInsertAfter(pos, 40);
	//SLEraseAfter(pos2);
	//SLInsert(&s1, pos, 20);
	SLErase(&s1, pos);
	SLPrint(s1);
	SLDestroy(&s1);
	SLPrint(s1);
}
int main(){
	//Test1();
	Test3();
	return 0;

}