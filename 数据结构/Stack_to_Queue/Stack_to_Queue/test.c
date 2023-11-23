#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}Stack;

// 初始化栈 
void StackInit(Stack* ps);
// 入栈 
void StackPush(Stack* ps, STDataType data);
// 出栈 
void StackPop(Stack* ps);
// 获取栈顶元素 
STDataType StackTop(Stack* ps);
// 获取栈中有效元素个数 
int StackSize(Stack* ps);
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps);
// 销毁栈 
void StackDestroy(Stack* ps);

void StackInit(Stack* ps)
{
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

void StackPush(Stack* ps, STDataType data)
{
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* new = (STDataType*)realloc(ps->a, sizeof(STDataType) * newcapacity);
		if (new == NULL)
		{
			perror("newcapacity fail");
		}
		ps->a = new;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = data;
	ps->top++;
}

void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}

STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}

int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}

int StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->top == 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

typedef struct {
	Stack s1;
	Stack s2;
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* new = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&new->s1);
	StackInit(&new->s2);
	return new;
}

void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->s1, x);
}

void in2out(MyQueue* obj)
{
	while (StackSize(&obj->s1))
	{
		StackPush(&obj->s2, StackTop(&obj->s1));
		StackPop(&obj->s1);
	}
}
int myQueuePop(MyQueue* obj) {
	in2out(obj);
	int top = StackTop(&obj->s2);
	StackPop(&obj->s2);
	return top;
}

int myQueuePeek(MyQueue* obj) {
	if ((StackEmpty(&obj->s2)))
	{
		in2out(obj);
		return StackTop(&obj->s2);
	}
	else
	{
		return StackTop(&obj->s2);
	}
	
}

bool myQueueEmpty(MyQueue* obj) {
	if (!StackEmpty(&obj->s2))
	{
		return false;
	}
	else {
		return true;
	}
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->s1);
	StackDestroy(&obj->s2);
	free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/
int main(){
	MyQueue* q1 = myQueueCreate();
	myQueuePush(q1, 1);
	myQueuePush(q1, 2);
	myQueuePeek(q1);
	myQueuePop(q1);
	myQueueEmpty(q1);

	return 0;

}