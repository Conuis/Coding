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
	PeoInfo *data;//通讯录容量
	int capacity;//记录当前容量
	int sz;
}Contact;

void InitContact(Contact* pc);//初始化通讯录
void AddContact(Contact* pc);//添加联系人信息
void DeleteContact(Contact* pc);//删除联系人信息
void ShowContact(const Contact* pc);//显示联系人信息
void SearchContact(const Contact* pc);//查找联系人信息
void ModifyContact(Contact* pc);//修改联系人信息
void SortContact(const Contact* pc);//排序
void DestroyContact(Contact* pc);