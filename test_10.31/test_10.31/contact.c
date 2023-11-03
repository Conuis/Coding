#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
//��ʼ����Ϣ����̬��
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
//��������
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
//�����ϵ����Ϣ
void AddContact(Contact* pc)
{
	assert(pc);
	//if (pc->sz == MAX)
	//{
	//	printf("ͨѶ¼������\n");
	//	return;
	//}
	// 
	//��������
	if (pc->sz == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, sizeof(PeoInfo) * (pc->capacity + 3));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += 3;
			printf("���ݳɹ���\n");
		}
		else
		{
			perror("AddContact->realloc:");
			return;
		}

	}
	printf("������������");
	scanf("%s", pc->data[pc->sz].name);
	printf("�������Ա�");
	scanf("%s", pc->data[pc->sz].sex);
	printf("���������䣺");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("������绰���룺");
	scanf("%s", pc->data[pc->sz].telep);
	printf("�������ַ��");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("�����ɣ�\n");
	return;
}
//ɾ����ϵ����Ϣ
void DeleteContact(Contact* pc)
{
	assert(pc);
	char name[NAME_MAX];
	if (pc->sz == 0)
	{
		printf("ͨѶ¼��û����ϵ�ˣ��޷�ɾ��\n");
		return;
	}
	printf("��������Ҫɾ������ϵ�����֣�");
	scanf("%s", name);
	int ret = FindName(pc, name);
	if (ret == -1)
	{
		printf("��Ҫɾ�����˲����ڣ�\n");
		return;
	}
	else
	{
		int i = 0;
		for (i = ret; i < pc->sz; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		printf("ɾ���ɹ���\n");
		pc->sz--;
	}

}
//������ϵ����Ϣ
void SearchContact(const Contact* pc)
{
	assert(pc);
	char name[NAME_MAX];
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷����ң�\n");
	}
	printf("��������Ҫ���ҵ����֣�");
	scanf("%s", name);
	int ret = FindName(pc, name);
	if (ret == -1)
	{
		printf("�޷��ҵ����ˣ����������룡\n");
		return;
	}
	else
	{
		printf("%-10s%-10s%-10s%-10s%-10s%s\n", "���", "����", "�Ա�", "����", "�绰", "��ַ");
		printf("%-10d%-10s%-10s%-10d%-10s%s\n", ret + 1, pc->data[ret].name, pc->data[ret].sex,
			pc->data[ret].age, pc->data[ret].telep, pc->data[ret].addr);
	}
}
//��ʾ��ϵ����Ϣ
void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-10s%-10s%-10s%-10s%-10s%s\n", "���","����", "�Ա�", "����", "�绰", "��ַ");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-10d%-10s%-10s%-10d%-10s%s\n", i+1,pc->data[i].name, pc->data[i].sex,
			pc->data[i].age, pc->data[i].telep, pc->data[i].addr);
	}
}

//�޸���ϵ����Ϣ
void ModifyContact(Contact* pc)
{
	assert(pc);
	char name[NAME_MAX];
	printf("��������Ҫ�޸ĵ���ϵ��������");
	scanf("%s", name);
	int ret = FindName(pc, name);
	if (ret == -1)
	{
		printf("�޷��ҵ����ˣ��޷��޸ģ�");
		return;
	}
	printf("��������Ҫ�޸ĵ��Ա�");
	scanf("%s", pc->data[ret].sex);
	printf("��������Ҫ�޸ĵ����䣺");
	scanf("%d", &(pc->data[ret].age));
	printf("��������Ҫ�޸ĵĵ绰��");
	scanf("%s", pc->data[ret].telep);
	printf("��������Ҫ�޸ĵĵ�ַ��");
	scanf("%s", pc->data[ret].addr);
	printf("�޸���ɣ�\n");
}

//����
void Sortmenu()
{
	printf("*******************************\n");
	printf("****  1.������  2.������   ****\n");
	printf("****  3.���Ա�  0.�˳�     ****\n");
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
		printf("��������Ҫ����ʽ��");
		scanf("%d",&input);
		switch (input)
		{
		case Name:
			qsort(pc->data,pc->sz, sizeof(PeoInfo), cmp_name);
			printf("����ɹ�\n");
			ShowContact(pc);
			break;
		case Age:
			qsort(pc->data, pc->sz, sizeof(PeoInfo), cmp_age);
			printf("����ɹ�\n");
			ShowContact(pc);
			break;
		case Sex:
			qsort(pc->data, pc->sz, sizeof(PeoInfo), cmp_sex);
			printf("����ɹ�\n");
			ShowContact(pc);
			break;
		case Exit:
			printf("�˳�����\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	}
}

//�ͷ�����
void DestroyContact( Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
	printf("�ͷųɹ���\n");
}