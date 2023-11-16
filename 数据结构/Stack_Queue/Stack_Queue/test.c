#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
#include "Queue.h"
void Test1()
{
	Stack s1;
	StackInit(&s1);
	StackPush(&s1, 1);	
	StackPush(&s1, 2);
	StackPush(&s1, 3);
	printf("%d ", StackTop(&s1));
	StackPop(&s1);
	printf("%d ", StackTop(&s1));
	StackPop(&s1);
	StackPush(&s1, 4);
	StackPush(&s1, 5);
	//printf("%d\n", StackSize(&s1));
	//printf("%d \n", StackEmpty(&s1));
	while (!StackEmpty(&s1))
	{
		printf("%d ", StackTop(&s1));
		StackPop(&s1);
	}
}

void Test2()
{
	Queue q1;
	QueueInit(&q1);
	QueuePush(&q1, 1);
	QueuePush(&q1, 2);
	QueuePush(&q1, 3);
	QueuePush(&q1, 4);
	QueuePush(&q1, 5);
	while (q1.size != 0)
	{
		printf("%d->", q1.front->data);
		QueuePop(&q1);
	}
	printf("NULL\n");

	QueueInit(&q1);
	QueuePush(&q1, 1);
	QueuePush(&q1, 2);
	QueuePush(&q1, 3);
	QueuePush(&q1, 4);
	QueuePush(&q1, 5);
	QueueDestroy(&q1);
	while (q1.size != 0)
	{
		printf("%d->", q1.front->data);
		QueuePop(&q1);
	}
	printf("NULL\n");
}
int main(){
	//Test1();
	Test2();
	return 0;

}