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
		int max = begin;
		int min = begin;
		for (int i = begin + 1; i <= end; i++)
		{


			if (a[i] > a[max])
			{
				max = i;
			}

			if (a[i] < a[min])
			{
				min = i;
			}
		}

		Swap(&a[begin], &a[min]);
		if (max == begin)
		{
			max = min;
		}
		Swap(&a[end], &a[max]);
   		++begin;
		--end;
	}
}
