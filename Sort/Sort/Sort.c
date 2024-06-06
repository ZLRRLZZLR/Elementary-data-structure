#include"Sort.h"

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

}
// 插入排序
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

// 希尔排序
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

// 选择排序
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

// 堆排序
void AdjustDwon(int* a, int n, int root)
{
	int child = (root * 2) + 1;

	while(child < n)
	{

		if (a[child] < a[child + 1] && child + 1 < n)
		{
			++child;
		}
			
		if (a[root] < a[child])
		{
			Swap(&a[root], &a[child]);

			root = child;

			child = (root * 2) + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	int end = n - 1;
	for(int i = (n - 1 - 1) / 2;i >= 0;i--)
	{
		AdjustDwon(a, n, i);
	}

	while(end > 0)
	{

		Swap(&a[0],&a[end]);
		AdjustDwon(a, end--, 0);
	}


}

// 冒泡排序
void BubbleSort(int* a, int n)
{

	for(int j = n ;j > 1;j--)
	{
		int flage = 0;
		for (int i = 1; i < j; i++)
		{
			if (a[i -1 ] < a[i])
			{
				Swap(&a[i - 1], &a[i]);
				flage = 1;
			}
		}
		if (flage == 0)
		{
			break;
		}
	}

}

//三数取中
int Gitmid(int* a, int left, int right);
{
	int key = (right - left) / 2;
	if()

}



// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{
	int key = Gitmid(a,left,right);
	int begin = left;
	int end = right;
	while(a[end] < )
	{

	}
}

// 快速排序挖坑法
int PartSort2(int* a, int left, int right);

// 快速排序前后指针法
int PartSort3(int* a, int left, int right);

void QuickSort(int* a, int left, int right);

// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right);