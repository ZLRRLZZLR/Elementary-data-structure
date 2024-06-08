#include"Sort.h"

void Print(int*a)
{
	for (int i = 0; i < 14; i++)
	{
		printf("%2d ", a[i]);
	}
}

int main()
{
	//int a[] = { 2,4,8,3,1,7,9,2 };
	int a[] = { 9,1,2,5,7,4,6,3,10,6,9,15,12,-1};
	// Ñ¡ÔñÅÅÐò
	//SelectSort(a, sizeof(a) / sizeof(int));
	//Print(a);
	//printf("\n");
	//InsertSort(a, sizeof(a) / sizeof(int));
	//Print(a);
	//printf("\n");
	//ShellSort(a, sizeof(a) / sizeof(int));
	//Print(a);

	//printf("\n");
	////AdjustDwon(a, sizeof(a) / sizeof(int),0);
	//HeapSort(a, sizeof(a) / sizeof(int), 0);
	//Print(a);
	//printf("\n");

	//BubbleSort(a, sizeof(a) / sizeof(int));
	//Print(a);
	//printf("\n");
	QuickSort(a,0, sizeof(a) / sizeof(int) - 1);
	Print(a);
	//printf("\n");
	//QuickSortNonR(a, 0, sizeof(a) / sizeof(int) - 1);
	//Print(a);
	//printf("\n");



	return 0;
}