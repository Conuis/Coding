#include "Heap.h"
//�ѵĳ�ʼ��
void InitHeap(Heap* hp)
{
	hp->a = NULL;
	hp->capacity = 0;
	hp->size = 0;

}
// �ѵ�����
void HeapDestory(Heap* hp)
{
	free(hp->a);
	hp->a = NULL;
	hp->size = hp->capacity = 0;
}
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
// С�ѵĲ���
void upAdjustS(HPDataType* hp, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (hp[child] < hp[parent])
		{
			Swap(&hp[child], &hp[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
		}
}
//���
void upAdjustB(HPDataType* hp, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (hp[child] > hp[parent])
		{
			Swap(&hp[child], &hp[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapPush(Heap* hp, HPDataType x)
{
	if (hp->size == hp->capacity)
	{
		int newcapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
		HPDataType* new = (HPDataType*)realloc(hp->a, sizeof(Heap) * newcapacity);
		hp->a = new;
		hp->capacity = newcapacity;
	}
	hp->a[hp->size] = x;
	hp->size++;
	upAdjustB(hp->a,hp->size-1);
}
// С�ѵ�ɾ��
void AdjustDownS(HPDataType* hp, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child<size)
	{
		if (child + 1 < size && hp[child] > hp[child + 1])
		{
			child = child + 1;
		}
		if (hp[parent] > hp[child])
		{
			Swap(&hp[parent], &hp[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//���
void AdjustDownB(HPDataType* hp, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && hp[child] < hp[child + 1])
		{
			child = child + 1;
		}
		if (hp[parent] < hp[child])
		{
			Swap(&hp[parent], &hp[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapPop(Heap* hp)
{
	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;
	AdjustDownB(hp->a,hp->size,0);
}
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	return hp->a[0];
}
// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	return hp->size;
}
// �ѵ��п�
int HeapEmpty(Heap* hp)
{
	return hp->size == 0;
}

// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	InitHeap(hp);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		HeapPush(hp, a[i]);
	}
}
