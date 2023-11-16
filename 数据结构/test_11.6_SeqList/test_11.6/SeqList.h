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
void CheckSeqList(SL* ps1);//�������
void SLPrint(SL* ps1);//��ӡ
void SLInit(SL* ps1);//��ʼ��˳���
void SLDestroy(SL* ps1);//����˳���
void SLPushBack(SL* ps1, SLDataType x);//β��˳���
void SLPushFront(SL* ps1, SLDataType x);//ͷ��˳���
void SLPopBack(SL* ps1);//βɾ˳���
void SLPopFront(SL* ps1);//ͷɾ˳���
void SLPush(SL* ps1, int pos, SLDataType x);//����λ�ò���
void SLPop(SL* ps1, int pos);//����λ��ɾ��
int SLFind(SL* ps1, SLDataType x);
