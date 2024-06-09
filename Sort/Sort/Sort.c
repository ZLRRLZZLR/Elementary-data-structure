#include"Sort.h"
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

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
int GetMid(int* a, int left, int right)
{
	int mid = left + (left + right)>>1;

	if(a[left] > a[mid])
	{
		if(a[mid] > a[right])
		{
			return mid;
		}
		else if(a[left] > a[right])
			{
				return right;
			}
		else
			{
				return left;
			}
	}
	else
	{
		if(a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
			{
				return left;
			}
			else
			{
				return right;
			}
		
	}

}


// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{

	int key = GetMid(a,left,right);
	Swap(&a[key],&a[left]);

	int begin = left;
	int end = right;

	while(begin < end)
	{
		while (begin < end && a[end] >= a[left])
		{
			--end;
		}
		while(begin < end && a[begin] <= a[left])
		{
			++begin;
		}

		Swap(&a[begin], &a[end]);
	}

	Swap(&a[left],&a[begin]);

	return begin;

}

// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	int key = GetMid(a, left, right);
	Swap(&a[key], &a[left]);

	key = a[left];

	int begin = left;
	int end = right;

	while (begin < end)
	{
		while (begin < end && a[end] >= key)
		{
			--end;
		}

		a[begin] = a[end];

		while (begin < end && a[begin] <= key)
		{
			++begin;
		}

		a[end] = a[begin];

	}

	a[begin] = key;

	return begin;
}

// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{
	int prev = left;
	int cur = left + 1;

	int key = GetMid(a, left, right);
	Swap(&a[key], &a[left]);

	//while(cur <= right)
	//{
	//	if(a[cur] < a[left] && ++prev != cur)
	//	{
	//		Swap(&a[cur],&a[prev]);
	//	}

	//	cur++;
	//}
	while(cur <= right)
	{
		while(cur <= right && a[cur] > a[left])
		{
			cur++;
		}
		prev++;
		if(prev != cur)
		{
			Swap(&a[prev],&a[cur]);
		}
		cur++;
	}

	Swap(&a[prev], &a[left]);

	return prev;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	if(right - left + 1 <= 10)
	{
		InsertSort(a + left, right - left + 1);
	}

	else
	{

		//int key = PartSort1(a, left, right);
		//int key = PartSort2(a, left, right);
		int key = PartSort3(a, left, right);


		QuickSort(a, left, key - 1);
		QuickSort(a, key + 1, right);
	}

}
#include"Stack.h"

// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right)
{

		Stack q;
		StackInit(&q);
		if(left < right)
		{
			StackPush(&q, right);
			StackPush(&q, left);
		}


		while (!StackEmpty(&q))
		{
			int begin = StackTop(&q);
			StackPop(&q);
			int end = StackTop(&q);
			StackPop(&q);

			if (right - left + 1 <= 10)
			{
				InsertSort(a + left, right - left + 1);
			}

			else
			{
				int key = PartSort1(a, begin, end);

				if (key + 1 < end)
				{
					StackPush(&q, end);
					StackPush(&q, key + 1);
				}

				if (begin < key - 1)
				{
					StackPush(&q, key - 1);
					StackPush(&q, begin);
				}
			}

		}
		StackDestroy(&q);

}

void _MergeSort(int* a, int* tmp, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}

	int mid = begin + (end - begin) / 2;

	_MergeSort(a, tmp, begin, mid);
	_MergeSort(a, tmp, mid + 1, end);

	int begin1 = begin;
	int end1 = mid;

	int begin2 = mid + 1;
	int end2 = end;

	int i = begin;

	while(begin1 <= end1 && begin2 <= end)
	{

		if(a[begin1] <= a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}

	}

	while(begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	memcpy(a + begin,tmp + begin,(end - begin + 1) * sizeof(int));


}


// 归并排序递归实现
void MergeSort(int* a, int n)
{
	int* tmp = (int*) malloc(sizeof(int)*n);
	if(NULL == tmp)
	{
		perror("malloc");
		exit(1);
	}

	_MergeSort(a, tmp ,0, n - 1);

	free(tmp);
	tmp = NULL;
}


// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);

	if (NULL == tmp)
	{
		perror("malloc");
		exit(1);
	}

	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{

			int begin1 = i;
			int end1 = i + gap - 1;

			int begin2 = i + gap ;
			int end2 = i + 2 * gap - 1;

			if(begin2 >= n)
			{
				break;
			}

			if(end2 >= n)
			{
				end2 = n - 1;
			}
			int j = i;
			//printf("[%d,%d][%d,%d] ", begin1, end1, begin2, end2);
			while (begin1 <= end1 && begin2 <= end2)
			{

				if (a[begin1] <= a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}

			}

			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}

			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));

		}

		gap *= 2;

	}


	free(tmp);
	tmp = NULL;

}



// 计数排序
void CountSort(int* a, int n)
{
	int max = a[0];
	int min = a[0];
	for(int i = 0;i < n;i++)
	{
		if(a[i] > max)
		{
			max = a[i];
		}

		if (a[i] < min)
		{
			min = a[i];
		}
	}

	int range = max - min + 1;

	int* tmp = (int*)calloc(range,sizeof(int));

	if(NULL == tmp)
	{
		perror("calloc:");
		exit(1);

	}

	for(int i = 0;i < n;i++)
	{
		tmp[a[i] - min]++;
	}
	int j = 0;
	for(int i = 0; i < range ; i++)
	{
		while(tmp[i]--)
		{
			a[j++] = min + i;
			
		}
	}

	free(tmp);
	tmp = NULL;
}