#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//×Ö·û´®×óÐý
//void revolve(char arr[],int a)
//{
//	int sz = strlen(arr);
//	int i = 0;
//	for (i = 0; i < a; i++)
//	{
//		char temp = arr[0];
//		for (int j = 0; j < sz - 1; j++)
//		{
//			
//			arr[j] = arr[j + 1];
//		}
//		arr[sz - 1] = temp;
//	}
//	printf("%s", arr);
//}

//void revolve(char* arr, int a)
//{
//	int len = strlen(arr);
//	char temp[100] = { 0 };
//	strcpy(temp, arr + a);
//	strncat(temp, arr, a);
//	strcpy(arr, temp);
//	printf("%s", arr);
//}
//int main(){
//	char arr[] = "ABCDEF";
//	int a;
//	scanf("%d", &a);
//	revolve(arr,a);
//	return 0;
//
//}

//×Ö·û´®Ðý×ª½á¹û
//int revolve(char* a, char* b)
//{
//	size_t len = strlen(a);
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		for (int j = 0; j < len - 1; j++)
//		{
//			char temp = a[0];
//			for (int k = 0; k < len - 1; k++)
//			{
//				a[k] = a[k + 1];
//			}
//			a[len - 1] = temp;
//			if (strcmp(a, b) == 0)
//			{
//				return 1;
//			}
//		}
//		for (int j = 0; j < len - 1; j++)
//		{
//			char temp = a[len - 1];
//			for (int k = len - 1; k > 0; k--)
//			{
//				a[k] = a[k - 1];
//			}
//			a[0] = temp;
//			if (strcmp(a, b) == 0)
//			{
//				return 1;
//			}
//		}
//	}
//	return 0;
//}

int revolve(char* a, char* b)
{
	char temp[255] = { 0 };
	strcpy(temp, a);
	strcat(temp, a);
	if (strstr(temp, b) != NULL)
	{
		return 1;
	}
	return 0;
}
int main()
{
	char arr1[] = "abcde";
	char arr2[] = "eabcd";
	int a = revolve(arr1, arr2);
	printf("%d", a);
	return 0;
}
