#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//调整奇数偶数顺序
//int main(){
//	int arr1[20] = { 0 };
//	int arr2[20] = { 0 };
//	int arr3[20] = { 0 };
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	int flag = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr1[i]);
//	}
//	i = 0;
//	while (i < n)
//	{
//		if (arr1[i] % 2 != 0)
//		{
//			arr2[j++] = arr1[i++];
//			flag++;
//		}
//		else
//		{
//			arr3[k++] = arr1[i++];
//		}
//	}
//	k = 0;
//	for (j = flag; j < n; j++)
//	{
//		arr2[j] = arr3[k];
//		k++;
//	}
//	for (j = 0; j < n; j++)
//	{
//		printf("%d ", arr2[j]);
//	}
//	return 0;
//
//}

// 模拟实现库函数strcpy
#include <assert.h>
//void my_strcpy(char* des, char* sor)
//{
//	//断言
//	assert(sor != NULL);
//	assert(des != NULL);
//	while (*des++ = *sor++)
//	{
//		;
//	}
//}
//int main()
//{
//	char a[] = { "******************" };
//	char b[] = { "asdf" };
//	my_strcpy(a, b);
//	printf("%s",a);
//
//	return 0; 
//}

//模拟实现库函数strlen
size_t my_strlen(const char* a)
{
	assert(a != NULL);
	size_t flag = 0;
	while (*a)
	{
		flag++;
		a++;
	}
	return flag;
}
int main()
{
	char a[] = { "abcdefg" };
	size_t c = my_strlen(a);
	printf("%zd", c);
	return 0;
}