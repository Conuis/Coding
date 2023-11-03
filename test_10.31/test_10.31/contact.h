#pragma once
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define NAME_MAX 20
#define TELEP_MAX 12
#define ADDR_MAX 30
#define MAX 100
#define CAPACITY 3
typedef struct PeoInfo
{
	char name[NAME_MAX];
	char sex[5];
	int age;
	char telep[TELEP_MAX];
	char addr[ADDR_MAX];
}PeoInfo;

//typedef struct Contact
//{
//	PeoInfo data[MAX];
//	int sz;
//}Contact;

typedef struct Contact
{
	PeoInfo *data;//ͨѶ¼����
	int capacity;//��¼��ǰ����
	int sz;
}Contact;

void InitContact(Contact* pc);//��ʼ��ͨѶ¼
void AddContact(Contact* pc);//�����ϵ����Ϣ
void DeleteContact(Contact* pc);//ɾ����ϵ����Ϣ
void ShowContact(const Contact* pc);//��ʾ��ϵ����Ϣ
void SearchContact(const Contact* pc);//������ϵ����Ϣ
void ModifyContact(Contact* pc);//�޸���ϵ����Ϣ
void SortContact(const Contact* pc);//����
void DestroyContact(Contact* pc);