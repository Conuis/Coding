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
// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n);
// 堆的销毁
void HeapDestory(Heap* hp);
// 堆的插入
void HeapPush(Heap* hp, HPDataType x);
void upAdjustB(HPDataType* hp, int child);
void upAdjustS(HPDataType* hp, int child);
// 堆的删除
void HeapPop(Heap* hp);
void AdjustDownS(HPDataType* hp, int size, int parent);
void AdjustDownB(HPDataType* hp, int size, int parent);
// 取堆顶的数据
HPDataType HeapTop(Heap* hp);
// 堆的数据个数
int HeapSize(Heap* hp);
// 堆的判空
int HeapEmpty(Heap* hp);
//创建文件
void CreateNDate();
//查找Topk
void PrintTopK(int k);
void Swap(HPDataType* p1, HPDataType* p2);
