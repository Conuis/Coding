#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
////模拟实现memcpy函数
//void* my_memcpy(void* des, const void* sor, size_t size)
//{
//	while (size--)
//	{
//		*(char*)des = *(char*)sor;
//		des = (char*)des + 1;
//		sor = (char*)sor + 1;
//	}
//}
//int main() {
//	int arr1[20] = { 1,2,3,4,5 };
//	int arr2[] = { 5,6,7,8,9,10 };
//	my_memcpy(arr1, arr2, sizeof(arr2));
//	for (int i = 0; i < 6; i++)
//	{
//		printf("%d ",arr2[i]);
//	}
//	printf("\n----------------\n");
//	char arr3[] = "xxxxxxxxxx";
//	char arr4[] = "abcde";
//	my_memcpy(arr3, arr4, sizeof(arr4));
//	printf("%s", arr3);
//	return 0;
//}

//模拟实现memmove
void* my_memmove(void* des, void* sor, size_t sz)
{
	if (des < sor)
	{
		while (sz--)
		{
			*(char*)des = *(char*)sor;
			des = (char*)des + 1;
			sor = (char*)sor + 1;
		}
	}
	else
	{
		while (sz--)
		{
			*((char*)des+sz) = *((char*)sor+sz);
		}
	}
}
int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr1, arr1 + 2, 20);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}	
	printf("\n--------------------\n");
	int arr2[] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr2+2, arr2 , 20);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr2[i]);
	}
	return 0;
}