#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int main()
//{
//	int aa[2][5] = { 10,9,8,7,6,5,4,3,2,1 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//	return 0;
//}
//123
//int main()
//{
//	int a[5] = { 5, 4, 3, 2, 1 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//	return 0;
//}

//模拟实现qsort函数
#include <string.h>
struct Stu
{
	char name[20];
	int age;
};
void swap(char* e1, char* e2, size_t size)
{
	char temp;
	size_t i = 0;
	for (i = 0; i < size; i++)
	{
		temp = *e1;
		*e1 = *e2;
		*e2 = temp;
		e1++;
		e2++;
	}
}
void Bubble_sort(void* base, size_t num, size_t size, int (*cmp)(const void* e1, const void* e2))
{
	size_t i = 0;
	for (i = 0; i < num - 1; i++)
	{
		size_t j = 0;
		for (j = 0; j < num - 1 - i; j++)
		{
			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0)
			{
				swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
			}
		}
	}
}

int sort_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

int sort_struct_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name,((struct Stu*)e2)->name);
}
int sort_struct_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
int main()
{
	int arr[] = { 5,4,3,2,1,51651,5,46,4,6,165,16,54 };
	struct Stu arr1[3] = { {"wangwu",12},{"zhangsan",22},{"lisi",55} };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Bubble_sort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), sort_int);
	Bubble_sort(arr1, sizeof(arr1) / sizeof(arr1[0]), sizeof(arr1[0]), sort_struct_by_name);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	struct Stu* p = arr1;
	for (p = arr1; p<&arr1[3]; p++)
	{
		printf("%s,%d\n",p->name,p->age);
	}
	printf("\n");
	Bubble_sort(arr1, sizeof(arr1) / sizeof(arr1[0]), sizeof(arr1[0]), sort_struct_by_age);
	for (p = arr1; p < &arr1[3]; p++)
	{
		printf("%s,%d\n", p->name, p->age);
	}
	return 0;
}