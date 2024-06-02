#include"Sort.h"

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

}
// ≤Â»Î≈≈–Ú
void InsertSort(int* a, int n)
{

	for ( int i = 0; i < n - 1; i++)
	{
		int end = i;
		int temp = a[end + 1];
		while (end >= 0)
		{
			if (temp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = temp;
	}
}

// œ£∂˚≈≈–Ú
void ShellSort(int* a, int n)
{
	//int gap = 3;
	//for(int j = gap ;j > 0;j--)
	//{
	//	for (size_t i = 0; i < n - gap; i += gap)
	//	{
	//		int end = i;
	//		int temp = a[end + gap];
	//		while (end >= 0)
	//		{
	//			if (temp < a[end])
	//			{
	//				a[end + gap] = a[end];
	//				end -= gap;
	//			}
	//			else
	//			{
	//				break;
	//			}
	//		}
	//		a[end + gap] = temp;
	//	}
	//}
	//InsertSort(a,n);

	int gap = n;

	while(gap > 1)
	{
		gap = gap / 3 + 1;

		for (size_t i = 0; i < n - gap; i++)
		{
			int end = i;
			int temp = a[end + gap];
			while (end >= 0)
			{
				if (temp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = temp;
		}

	}

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

// ∂—≈≈–Ú
void AdjustDwon(int* a, int n, int root)
{
	int parent = (n - 1 - 1) / 2;
	for()
	{

	}
}
void HeapSort(int* a, int n);