#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLNDataType;
typedef struct SLlist
{
	SLNDataType val;
	struct SLlist* next;
}SLNode;

void SLPrint(SLNode* phead);

void SLPushBack(SLNode** pplist, SLNDataType x);

void SLPushFront(SLNode** pplist, SLNDataType x);

void SLPopBack(SLNode** pplist);

void SLPopFront(SLNode** pplist);

SLNode* SListFind(SLNode* plist, SLNDataType x);

void SLInsertAfter(SLNode* pos, SLNDataType x);

void SLEraseAfter(SLNode* pos);

void SLInsert(SLNode** pphead, SLNode* pos, SLNDataType x);

void SLErase(SLNode** pphead, SLNode* pos);

void SLDestroy(SLNode** pphead);