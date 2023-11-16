#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void Test1()
{
	SL s1;
	SLInit(&s1);
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLPushBack(&s1, 5);	
	SLPrint(&s1);
	SLPushFront(&s1, 1);
	SLPushFront(&s1, 2);
	SLPushFront(&s1, 3);
	SLPushFront(&s1, 4);
	SLPushFront(&s1, 5);
	SLPrint(&s1);
	SLDestroy(&s1);
}
void Test2()
{
	SL s1;
	SLInit(&s1);
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLPushBack(&s1, 5);
	SLPopBack(&s1);
	SLPopBack(&s1);
	SLPopBack(&s1);
	SLPopBack(&s1);
	SLPopBack(&s1);
	SLPopBack(&s1);
	SLPrint(&s1);
}

void Test3()
{
	SL s1;
	SLInit(&s1);
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLPushBack(&s1, 5);
	SLPopFront(&s1);
	SLPopFront(&s1);
	SLPopFront(&s1);
	SLPopFront(&s1);
	SLPrint(&s1);
	SLDestroy(&s1);
}

void Test4()
{
	SL s1;
	SLInit(&s1);
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLPushBack(&s1, 5);
	SLPush(&s1, 3, 2);
	SLPrint(&s1);
	SLDestroy(&s1);
}

void Test5()
{
	SL s1;
	SLInit(&s1);
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLPushBack(&s1, 5);
	SLPop(&s1, 5);
	SLPrint(&s1);
	SLDestroy(&s1);
}

void Test6()
{
	SL s1;
	SLInit(&s1);
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 35);
	SLPushBack(&s1, 24);
	SLPushBack(&s1, 5);
	SLPop(&s1, 5);
	int a = SLFind(&s1, 24);
	SLPrint(&s1);
	printf("%d\n", a);
	SLDestroy(&s1);
}
int main(){
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	Test6();
	return 0;

}