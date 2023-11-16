#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

void QueueInit(Queue* q)
{
	assert(q);
	q->rear= NULL;
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
}

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

