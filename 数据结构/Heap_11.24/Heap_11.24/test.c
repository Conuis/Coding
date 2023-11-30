#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
void CreateNDate()
{
	// ÔìÊý¾Ý
	int n = 10000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

void PrintTopK(int k)
{
	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen error");
		return;
	}
	int* a = (int*)malloc(sizeof(int) * k);
	if (a == NULL)
	{
		perror("malloc fail");
	}
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &a[i]);
		upAdjustS(a, i);
	}
	int x = 0;
	while (fscanf(fout, "%d", &x) != EOF)
	{
		if (x > a[0])
		{
			a[0] = x;
			AdjustDownS(a, k, 0);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", a[i]);
	}
	fclose(fout);

}
//¶ÑÅÅÐòÉýÐò
void HeapSortUp(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		upAdjustB(a, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0],&a[end]);
		AdjustDownB(a, end, 0);
		end--;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main() {
	int a[] = {4,6,2,1,5,8,2,9};
	//Heap hp;
	//HeapCreate(&hp, a, 8);
	//while (!HeapEmpty(&hp))
	//{
	//	printf("%d ", HeapTop(&hp));
	//	HeapPop(&hp);
	//}
	//CreateNDate();
	//PrintTopK(10);
	HeapSortUp(a, sizeof(a)/sizeof(a[0]));

	return 0;

}