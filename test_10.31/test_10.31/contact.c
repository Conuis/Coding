#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
//初始化信息（动态）
void InitContact(Contact* pc)
{
	assert(pc);
	pc->sz = 0;
	pc->capacity = CAPACITY;
	pc->data = calloc(pc->capacity , (sizeof(PeoInfo)));
	if (pc->data == NULL)
	{
		perror("InitContact:");
		return;
	}
}
//查找名字
int FindName(Contact* pc,char name[])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
//添加联系人信息
void AddContact(Contact* pc)
{
	assert(pc);
	//if (pc->sz == MAX)
	//{
	//	printf("通讯录已满！\n");
	//	return;
	//}
	// 
	//增加容量
	if (pc->sz == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, sizeof(PeoInfo) * (pc->capacity + 3));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += 3;
			printf("增容成功！\n");
		}
		else
		{
			perror("AddContact->realloc:");
			return;
		}

	}
	printf("请输入姓名：");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入性别：");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入年龄：");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入电话号码：");
	scanf("%s", pc->data[pc->sz].telep);
	printf("请输入地址：");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("添加完成！\n");
	return;
}
//删除联系人信息
void DeleteContact(Contact* pc)
{
	assert(pc);
	char name[NAME_MAX];
	if (pc->sz == 0)
	{
		printf("通讯录中没有联系人，无法删除\n");
		return;
	}
	printf("请输入需要删除的联系人名字：");
	scanf("%s", name);
	int ret = FindName(pc, name);
	if (ret == -1)
	{
		printf("需要删除的人不存在！\n");
		return;
	}
	else
	{
		int i = 0;
		for (i = ret; i < pc->sz; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		printf("删除成功！\n");
		pc->sz--;
	}

}
//查找联系人信息
void SearchContact(const Contact* pc)
{
	assert(pc);
	char name[NAME_MAX];
	if (pc->sz == 0)
	{
		printf("通讯录为空，无法查找！\n");
	}
	printf("请输入需要查找的名字：");
	scanf("%s", name);
	int ret = FindName(pc, name);
	if (ret == -1)
	{
		printf("无法找到此人！请重新输入！\n");
		return;
	}
	else
	{
		printf("%-10s%-10s%-10s%-10s%-10s%s\n", "序号", "姓名", "性别", "年龄", "电话", "地址");
		printf("%-10d%-10s%-10s%-10d%-10s%s\n", ret + 1, pc->data[ret].name, pc->data[ret].sex,
			pc->data[ret].age, pc->data[ret].telep, pc->data[ret].addr);
	}
}
//显示联系人信息
void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-10s%-10s%-10s%-10s%-10s%s\n", "序号","姓名", "性别", "年龄", "电话", "地址");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-10d%-10s%-10s%-10d%-10s%s\n", i+1,pc->data[i].name, pc->data[i].sex,
			pc->data[i].age, pc->data[i].telep, pc->data[i].addr);
	}
}

//修改联系人信息
void ModifyContact(Contact* pc)
{
	assert(pc);
	char name[NAME_MAX];
	printf("请输入需要修改的联系人姓名：");
	scanf("%s", name);
	int ret = FindName(pc, name);
	if (ret == -1)
	{
		printf("无法找到此人！无法修改！");
		return;
	}
	printf("请输入需要修改的性别：");
	scanf("%s", pc->data[ret].sex);
	printf("请输入需要修改的年龄：");
	scanf("%d", &(pc->data[ret].age));
	printf("请输入需要修改的电话：");
	scanf("%s", pc->data[ret].telep);
	printf("请输入需要修改的地址：");
	scanf("%s", pc->data[ret].addr);
	printf("修改完成！\n");
}

//排序
void Sortmenu()
{
	printf("*******************************\n");
	printf("****  1.按名字  2.按年龄   ****\n");
	printf("****  3.按性别  0.退出     ****\n");
	printf("*******************************\n");

}
enum Sort
{
	Exit,
	Name,
	Age,
	Sex
};
int cmp_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}
int cmp_age(const void* e1, const void* e2)
{
	return ((PeoInfo*)e1)->age - ((PeoInfo*)e2)->age;
}
int cmp_sex(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->sex, ((PeoInfo*)e2)->sex);
}
void SortContact(Contact* pc)
{
	assert(pc);
	Sortmenu();
	int input = 1;
	while (input)
	{
		printf("请输入需要排序方式：");
		scanf("%d",&input);
		switch (input)
		{
		case Name:
			qsort(pc->data,pc->sz, sizeof(PeoInfo), cmp_name);
			printf("排序成功\n");
			ShowContact(pc);
			break;
		case Age:
			qsort(pc->data, pc->sz, sizeof(PeoInfo), cmp_age);
			printf("排序成功\n");
			ShowContact(pc);
			break;
		case Sex:
			qsort(pc->data, pc->sz, sizeof(PeoInfo), cmp_sex);
			printf("排序成功\n");
			ShowContact(pc);
			break;
		case Exit:
			printf("退出排序！\n");
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
	}
}

//释放容量
void DestroyContact( Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
	printf("释放成功！\n");
}