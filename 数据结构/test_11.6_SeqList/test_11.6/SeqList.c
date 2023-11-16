#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
void CheckSeqList(SL* ps1)
{
	if (ps1->size == ps1->capacity)
	{
		int NewCapacity = ps1->capacity == 0 ? 4 : ps1->capacity * 2;
		SLDataType* tmp = realloc(ps1->data, sizeof(SLDataType) * NewCapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
		}
		ps1->data = tmp;
		ps1->capacity = NewCapacity;
	}
}
void SLPrint(SL* ps1)
{
	int i = 0;
	for (i = 0; i < ps1->size; i++)
	{
		printf("%d ", ps1->data[i]);
	}
	printf("\n");
}
void SLInit(SL* ps1)
{
	ps1->data = NULL;
	ps1->size = 0;
	ps1->capacity = 0;
}
void SLDestroy(SL* ps1)
{
	assert(ps1);
	if (ps1->data != NULL)
	{
		free(ps1->data);
		ps1->data = NULL;
		ps1->size = 0;
		ps1->capacity = 0;
	}
}
void SLPushBack(SL* ps1, SLDataType x)
{
	assert(ps1);
	CheckSeqList(ps1);
	ps1->data[ps1->size] = x;
	ps1->size++;
}
void SLPushFront(SL* ps1, SLDataType x)
{
	assert(ps1);
	CheckSeqList(ps1);
	int end = ps1->size - 1;
	while ( end>= 0)
	{
		ps1->data[end + 1] = ps1->data[end];
		end--;
	}
	ps1->data[0] = x;
	ps1->size++;
}
void SLPopBack(SL* ps1)
{
	assert(ps1);
	assert(ps1->size > 0);
	ps1->size--;

}
void SLPopFront(SL* ps1)
{
	assert(ps1);
	assert(ps1->size > 0);
	int begin = 0;
	while (begin < ps1->size - 1)
	{
		ps1->data[begin] = ps1->data[begin + 1];
		begin++;
	}
	ps1->size--;
}

void SLPush(SL* ps1, int pos, SLDataType x)
{
	assert(ps1);
	CheckSeqList(ps1);
	int end = ps1->size;
	while (end >= pos)
	{
		ps1->data[end] = ps1->data[end - 1];
		end--;
	}
	ps1->data[pos] = x;
	ps1->size++;
}
void SLPop(SL* ps1, int pos)
{
	assert(ps1);
	assert(ps1->size > 0);
	int begin = pos + 1;
	while (begin < ps1->size)
	{
		ps1->data[begin - 1] = ps1->data[begin];
		begin++;
	}
	ps1->size-- ;
}
int SLFind(SL* ps1, SLDataType x)
{
	assert(ps1);
	for (int i = 0; i < ps1->size; i++)
	{
		if (ps1->data[i] == x)
		{
			return i;
		}
	}
	return -1;
}