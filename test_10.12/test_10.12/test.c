#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//猜名次
//int main(){
//	int a;
//	int b;
//	int c;
//	int d;
//	int e;
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						if ((((b == 2) + (a == 3)) == 1) && 
//							(((b == 2) + (e == 4)) == 1) && 
//							(((c == 1) + (d == 2)) == 1) && 
//							(((c == 5) + (d == 3)) == 1) && 
//							(((e == 4) + (a == 1)) == 1) &&
//							(a*b*c*d*e)==120)
//						{
//							printf("A:%d B:%d C:%d D:%d E:%d", a, b, c, d, e);
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}

//猜凶手
//int main()
//{
//	char killer;
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if (((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D'))==3)
//		{
//			printf("killer is %c", killer);
//		}
//	}
//	return 0;
//}

//杨辉三角
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int a[100][100] = { 0 };
//	a[0][0] = 1;
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j < i; j++)
//		{
//			if (i == j)
//			{
//				a[i][j] = 1;
//			}
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//杨辉三角
int main()
{
	int i = 0;
	int j = 0;
	int a[20][20] = { 0 };
	for (i = 1; i <= 10; i++)
	{
		for (j = 1; j <= i; j++)
		{
			if (j == 1||i == j)
			{
				a[i][j] = 1;
			}
			//printf("%d ", a[i][j]);
			if (i > 1 && j > 1)
			{
				a[i][j] = a[i - 1][j - 1] + a[i-1][j];
			}
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}