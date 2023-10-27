#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//模拟实现strcmp
int my_strcmp(const char* str1, const char* str2)
{
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
	}
	return (*str1) - (*str2);
}
//模拟实现strcat
char* my_strcat(char* des, char* sor)
{
	char* ret = des;
	while (*des!='\0')
	{
		des++; 
	}
	while (*des++ = *sor++)
	{
		;
	}
	return ret;
}
//模拟实现strstr
const char* my_strstr(const char* str1, const char* str2)
{
	const char* s1;
	const char* s2;
	const char* cp;
	cp = str1;
	while (*cp)
	{
		s1 = cp;
		s2 = str2;
		while (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		//if (*s1 == '\0')
		//{
		//	s2++;
		//}
		if (*s2 == '\0')
		{
			return cp;
		}
		cp++;
	}
	return NULL;
}

int main(){
	char arr1[] = "asdcedd";
	char arr2[] = "abcdef";
	int p = my_strcmp(arr1, arr2);
	if (p > 0)
	{
		printf("%s > %s\n", arr1, arr2);
	}
	else
	{
		printf("%s <= %s\n", arr1, arr2);
	}
	printf("---------------------\n");
	char arr3[20] = "ABCDEFG";
	char arr4[] = "HIJKLMN";
	char* a = my_strcat(arr3, arr4);
	printf("%s\n", a);
	printf("---------------------\n");
	char arr5[20] = "abbadadc";
	char arr6[] = "ad";
	const char* b = my_strstr(arr5, arr6);
	if (b == NULL)
	{
		printf("Not found!");
	}
	else
	{
		printf("Found! the string is：%s\n", b);

	}
	return 0;
}