#include"Sort.h"

int main()
{
	int a[] = { 2,4,8,3,1,7,9,2 };
	// —°‘Ò≈≈–Ú
	SelectSort(a, sizeof(a) / sizeof(int));

	for (int i = 0;i < sizeof(a) / sizeof(int);i++)
	{
		printf("% d",a[i]);
	}

	return 0;
}