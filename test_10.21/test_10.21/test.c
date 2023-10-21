#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//杨氏矩阵
//#define N 5
//#define M 5
//int Find(int arr[N][M], int a,int* c,int* d)
//{
//	int i = 0;
//	int j = 0;
//
//	if (a<arr[0][0] || a>arr[N - 1][M - 1])
//	{
//		return 0;
//	}
//	int row = M - 1;
//	int col = 0;
//	while (row >= 0 && col < N)
//	{
//		if (a < arr[col][row])
//		{
//			row--;
//		}
//		else if (a > arr[col][row])
//		{
//			col++;
//		}
//		else
//		{
//			*c = col + 1;
//			*d = row + 1;
//			return 1;
//		}
//	}
//	return 0;
//
//}
//int main(){
//	int arr[N][M] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}, {16,17,18,19,20},{21,22,23,24,25} };
//	int a = 0;
//	int c = 0;
//	int d = 0;
//	scanf("%d", &a);
//	int b = Find(arr, a,&c,&d);
//	if (b == 1)
//	{
//		printf("找到了！\n");
//		printf("坐标是（%d,%d）", c, d);
//	}
//	else
//	{
//		printf("没找到");
//	}
//	return 0;
//
//}

//qsort使用练习
#include <stdlib.h>
#include <string.h>
int cmp_int(const void* a,const void* b)
{
	return *(int*)a - *(int*)b;
}
int cmp_char(const void* a, const void* b)
{
	return strcmp(*(char**)a, *(char**)b);
}
int main()
{
	int arr[] = { 1,52,2133,44565,5 };
	char *arr1[] = { "fff","ddd","kkk" };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	qsort(arr1, sizeof(arr1) / sizeof(arr1[0]), sizeof(char*), cmp_char);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%s ", arr1[i]);
	}

	return 0;
}