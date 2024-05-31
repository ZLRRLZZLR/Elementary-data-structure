#include"Sort.h"


void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

}


// —°‘Ò≈≈–Ú
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while(begin < end)
	{
		int max = a[begin + 1];
		int min = a[begin + 1];

		for (int i = begin + 1; i <= end; i++)
		{
			if(begin == 0)
			{
				max = a[0];
				min = a[0];
			}

			if (a[i] > max)
			{
				max = a[i];
			}

			if (a[i] < min)
			{
				min = a[i];
			}
		}
		Swap(&a[begin], &min);
		Swap(&a[end], &max);
		++begin;
		--end;
	}
}
