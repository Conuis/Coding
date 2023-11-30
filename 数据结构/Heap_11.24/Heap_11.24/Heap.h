#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}Heap;
void InitHeap(Heap* hp);
// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n);
// �ѵ�����
void HeapDestory(Heap* hp);
// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x);
void upAdjustB(HPDataType* hp, int child);
void upAdjustS(HPDataType* hp, int child);
// �ѵ�ɾ��
void HeapPop(Heap* hp);
void AdjustDownS(HPDataType* hp, int size, int parent);
void AdjustDownB(HPDataType* hp, int size, int parent);
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);
// �ѵ����ݸ���
int HeapSize(Heap* hp);
// �ѵ��п�
int HeapEmpty(Heap* hp);
//�����ļ�
void CreateNDate();
//����Topk
void PrintTopK(int k);
void Swap(HPDataType* p1, HPDataType* p2);
