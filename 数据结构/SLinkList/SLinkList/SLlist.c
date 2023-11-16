#define _CRT_SECURE_NO_WARNINGS 1
#include "SLlist.h"

void SLPrint(SLNode* phead)
{
	SLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}
SLNode* CreateNode(SLNDataType x)
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		perror("newnode fail");
		exit(-1);
	}
	newnode->val = x;
	newnode->next = NULL;
	return newnode;
}
void SLPushBack(SLNode** pphead, SLNDataType x)
{	
	SLNode* newnode = CreateNode(x);
	if ((*pphead) == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
	
}

void SLPushFront(SLNode** pphead, SLNDataType x)
{
	assert(*pphead);
	SLNode* newnode = CreateNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SLPopBack(SLNode** pphead)
{
	assert(*pphead);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLNode* tail = *pphead;
		SLNode* prev = NULL;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}

void SLPopFront(SLNode** pphead)
{
	SLNode* cur = *pphead;
	*pphead = (*pphead)->next;
	free(cur);
}

SLNode* SListFind(SLNode* phead, SLNDataType x)
{
	SLNode* cur = phead;
	while (cur)
	{
		if (cur->val == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

void SLInsertAfter(SLNode* pos, SLNDataType x)
{
	SLNode* newnode = CreateNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
	
}

void SLEraseAfter(SLNode* pos)
{
	SLNode* tmp = pos->next;
	pos->next = pos->next->next;
	free(tmp);
	tmp = NULL;
}


void SLInsert(SLNode** pphead, SLNode* pos, SLNDataType x)
{
	assert(pphead);
	assert(pos && (*pphead));
	SLNode* newnode = CreateNode(x);
	if (*pphead == pos)
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		SLNode* cur = *pphead;
		SLNode* prev = NULL;
		while (cur != pos)
		{
			prev = cur;
			cur = cur->next;
		}
		newnode->next = prev->next;
		prev->next = newnode;
	}
}

void SLErase(SLNode** pphead, SLNode* pos)
{
	if (*pphead == pos)
	{
		SLPopFront(pphead);
	}
	else
	{
		SLNode* cur = *pphead;
		SLNode* prev = NULL;
		while (cur != pos)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = cur->next;
		free(cur);
		cur = NULL;
	}

}
void SLDestroy(SLNode** pphead)
{
	SLNode* cur = *pphead;
	SLNode* prev = NULL;
	while (cur)
	{
		prev = cur;
		cur = cur->next;
		free(prev);
		prev = NULL;
	}
	*pphead = NULL;
}