#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef int QDataType;
typedef struct QListNode
{
	struct QListNode* next;
	QDataType data;
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* front;
	QNode* rear;
	int size;
}Queue;

// 初始化队列 
void QueueInit(Queue* q);
// 队尾入队列 
void QueuePush(Queue* q, QDataType data);
// 队头出队列 
void QueuePop(Queue* q);
// 获取队列头部元素 
QDataType QueueFront(Queue* q);
// 获取队列队尾元素 
QDataType QueueBack(Queue* q);
// 获取队列中有效元素个数 
int QueueSize(Queue* q);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q);
// 销毁队列 
void QueueDestroy(Queue* q);
void QueueInit(Queue* q)
{
	assert(q);
	q->rear = NULL;
	q->front = NULL;
	q->size = 0;
}

void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(Queue));
	if (newnode == NULL)
	{
		perror("malloc fail");
	}
	newnode->data = data;
	newnode->next = NULL;
	if (q->size == 0)
	{
		q->rear = q->front = newnode;
	}
	else
	{
		q->rear->next = newnode;
		q->rear = newnode;
	}
	q->size++;
}

void QueuePop(Queue* q)
{
	assert(q);
	assert(q->front);
	Queue* next = q->front->next;
	free(q->front);
	q->front = NULL;
	q->front = next;
	if (q->front == NULL)
	{
		q->rear = NULL;
	}
	q->size--;
}

QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->front);
	return q->front->data;
}

QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->rear);
	return q->rear->data;
};

int QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}

int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->size == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void QueueDestroy(Queue* q)
{
	Queue* del = NULL;
	while (q->front)
	{
		del = q->front;
		q->front = q->front->next;
		free(del);
		del = NULL;
	}
	q->front = q->rear = NULL;
	q->size = 0;
}


typedef struct {
	Queue q1;
	Queue q2;
} MyStack;


MyStack* myStackCreate() {
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&pst->q1);
	QueueInit(&pst->q2);
	return pst;
}

void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

int myStackPop(MyStack* obj) {
	Queue* empty = &obj->q1;
	Queue* noneempty = &obj->q2;
	if (QueueEmpty(noneempty))
	{
		empty = &obj->q2;
		noneempty = &obj->q1;
	}
	while (QueueSize(noneempty) > 1)
	{
		QueuePush(empty, QueueFront(noneempty));
		QueuePop(noneempty);
	}
	int top = QueueFront(noneempty);
	QueuePop(noneempty);
	return top;
}

int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else
	{
		return QueueBack(&obj->q2);
	}
}

bool myStackEmpty(MyStack* obj) {
	if ((QueueEmpty(&obj->q1)) && (QueueEmpty(&obj->q2)))
	{
		return true;
	}
	return false;
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}

int main() {
	MyStack* myStack = myStackCreate();
	myStackPush(myStack,1);
	myStackPush(myStack, 2);
	int a = myStackTop(myStack);
	myStackPop(myStack);
	int b = myStackTop(myStack);
	printf("%d %d", a, b);
	myStackEmpty(myStack);
	return 0;

}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/