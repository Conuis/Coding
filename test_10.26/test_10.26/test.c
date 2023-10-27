#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//模拟实现strlen函数
size_t my_strlen(char* arr)
{
	size_t sum = 0;
	while (*arr != '\0')
	{
		sum++;
		arr++;
	}
	return sum;
}
char* my_strcpy(char* des, char* sor)
{
	char* ret = des;
	while (*des++ = *sor++)
	{
		;
	}
	return ret;
}
int main(){
	char arr[] = "asdfa\0sdf";
	int a = my_strlen(arr);
	printf("%d\n", a);
	printf("------------------------------\n");
	char arr1[] = "xxxxxxxxxxxxxxxxxxxxxxxxxx";
	char arr2[] = "hello morning";
	char* b = my_strcpy(arr1,arr2);
	printf("%s", b);
	return 0;
}