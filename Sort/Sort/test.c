#include"Sort.h"


int main()
{
	//int a[] = { 2,4,8,3,1,7,9,2 };
	int a[] = { 9,1,2,5,7,4,6,3,10,6};
	// —°‘Ò≈≈–Ú
	//SelectSort(a, sizeof(a) / sizeof(int));
	/*InsertSort(a, sizeof(a) / sizeof(int));*/
	//ShellSort(a, sizeof(a) / sizeof(int));
	//AdjustDwon(a, sizeof(a) / sizeof(int),0);
	HeapSort(a, sizeof(a) / sizeof(int), 0);

	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}


	return 0;
}