#define _CRT_SECURE_NO_WARNINGS 1
#include "ListNode.h"

ListNode* ListCreate()
{
	ListNode* phead = (ListNode*)malloc(sizeof(struct ListNode));
	phead->next = phead;
	phead->prev = phead;
}

void ListPrint(ListNode* pHead)
{
	ListNode* cur = pHead->next;
	printf("ÉÚ±øÎ»<=>");
	while (cur != pHead)
	{
		printf("%d<=>", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

ListNode* CreateNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(struct ListNode));
	if (newnode == NULL)
	{
		perror("newnode fail");
	}
	newnode->val = x;
	return newnode;
}
void ListPushBack(ListNode* pHead, LTDataType x)
{
	ListNode* newnode = CreateNode(x);
	ListNode* cur = pHead->prev;
	newnode->prev = cur;
	cur->next = newnode;
	newnode->next = pHead;
	pHead->prev = newnode;
}

void ListPopBack(ListNode* pHead)
{
	assert(pHead->next!=pHead);
	ListNode* cur = pHead->prev;
	ListNode* prev = pHead->prev->prev;
	prev->next = pHead;
	pHead->prev = prev;
	free(cur);
	cur = NULL;
}

void ListPushFront(ListNode* pHead, LTDataType x)
{
	ListNode* newnode = CreateNode(x);
	ListNode* cur = pHead->next;
	pHead->next = newnode;
	newnode->prev = pHead;
	newnode->next = cur;
	cur->prev = newnode;
}

void ListPopFront(ListNode* pHead)
{
	assert(pHead->next != pHead);
	ListNode* cur = pHead->next;
	ListNode* next = pHead->next->next;
	pHead->next = next;
	next->prev = pHead;
	free(cur);
	cur = NULL;

}

ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		if (cur->val == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* prev = pos->prev;
	ListNode* newnode = CreateNode(x);
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

void ListErase(ListNode* pos)
{
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;
}

void ListDestory(ListNode* pHead)
{
	ListNode* cur = pHead->next;
	ListNode* prev = cur;
	while (cur != pHead)
	{
		prev = cur;
		cur = cur->next;
		free(prev);
		prev = NULL;
	}
	pHead->next = pHead;
	pHead->prev = pHead;
}