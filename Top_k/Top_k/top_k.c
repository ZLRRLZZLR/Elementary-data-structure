#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

typedef int HPDataType;

void CreateNDate()
{
	// 造数据
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
		int x = rand() % 1000000 + i;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

void PrintTopK(int k)
{

}

void Swap(int*a,int*b)
{
	int temp = *a;

	*a = *b;

	*b = temp;

}


//向下调整算法
void AdjustDown(HPDataType* a, int n, int parent)
{
	assert(a);
	int child = parent * 2 + 1;

	while(child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child = child + 1;
		}

		if(a[parent] < a[child])
		{

			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}

}

void HeapSort(int* a, int n)
{
	int parent = (n - 1 - 1) / 2;

	for(;parent >= 0;parent--)
	{

		AdjustDown(a,n,parent);

	}

	int end = n - 1;

	while(end > 0)
	{

		Swap(&a[0], &a[end]);

		AdjustDown(a, end, 0);

		end--;
	}

}

int main()
{
	//int arr[10] = {0};
	//CreateNDate();
	int k = 0;
	puts("请输入K的数值");
	scanf("%d",&k);

	int* arr = (int*)malloc(sizeof(int)*k);
	if(NULL == arr)
	{
		perror("malloc");
		exit(1);
	}

	memset(arr,0, sizeof(int) * k);

	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen error");
		return;
	}

	int i = 0;
	while(fscanf(fout,"%d",&i) != EOF)
	{
		if(i > arr[0])
		{
			arr[0] = i;
			HeapSort(arr, 10);

		}
	}

	for(int j = 0;j < 10;j++)
	{
		printf("%d ",arr[j]);
	}
	return 0;
}