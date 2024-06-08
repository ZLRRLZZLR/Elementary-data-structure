#include"Sort.h"

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

}
// ��������
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

// ϣ������
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

// ѡ������
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

// ������
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

// ð������
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

//����ȡ��
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


// ��������ݹ�ʵ��
// ��������hoare�汾
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

// ���������ڿӷ�
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

// ��������ǰ��ָ�뷨
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

// �������� �ǵݹ�ʵ��
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

// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n);

// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n);

// ��������
void CountSort(int* a, int n);