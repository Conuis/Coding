#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* data;
	int size;
	int capacity;
}SL;
void CheckSeqList(SL* ps1);//检查容量
void SLPrint(SL* ps1);//打印
void SLInit(SL* ps1);//初始化顺序表
void SLDestroy(SL* ps1);//销毁顺序表
void SLPushBack(SL* ps1, SLDataType x);//尾插顺序表
void SLPushFront(SL* ps1, SLDataType x);//头插顺序表
void SLPopBack(SL* ps1);//尾删顺序表
void SLPopFront(SL* ps1);//头删顺序表
void SLPush(SL* ps1, int pos, SLDataType x);//任意位置插入
void SLPop(SL* ps1, int pos);//任意位置删除
int SLFind(SL* ps1, SLDataType x);
