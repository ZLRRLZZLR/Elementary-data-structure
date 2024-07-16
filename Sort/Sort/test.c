#include"Sort.h"

//void Print(int*a)
//{
//	for (int i = 0; i < 13; i++)
//	{
//		printf("%2d ", a[i]);
//	}
//}
//
//int main()
//{
//	////int a[] = { 2,4,8,3,1,7,9,2 };
//	//int a[] = { 9,1,2,5,7,4,6,3,10,6,9,15,12};
//	//// ѡ������
//	////SelectSort(a, sizeof(a) / sizeof(int));
//	////Print(a);
//	////printf("\n");
//	////InsertSort(a, sizeof(a) / sizeof(int));
//	////Print(a);
//	////printf("\n");
//	////ShellSort(a, sizeof(a) / sizeof(int));
//	////Print(a);
//
//	////printf("\n");
//	//////AdjustDwon(a, sizeof(a) / sizeof(int),0);
//	////HeapSort(a, sizeof(a) / sizeof(int), 0);
//	////Print(a);
//	////printf("\n");
//
//	////BubbleSort(a, sizeof(a) / sizeof(int));
//	////Print(a);
//	////printf("\n");
//	////QuickSort(a,0, sizeof(a) / sizeof(int) - 1);
//	////Print(a);
//	////printf("\n");
//	////QuickSortNonR(a, 0, sizeof(a) / sizeof(int) - 1);
//	////Print(a);
//	////printf("\n");
//	//MergeSort(a, sizeof(a) / sizeof(int) );
//	///*CountSort(a, sizeof(a) / sizeof(int));*/
//	//Print(a);
//
//	return 0;
//}

#include"Sort.h"

void TestInsertSort()
{
	int a[] = { 2,4,1,7,8,3,9,2 };
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestShellSort()
{
	int a[] = { 9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5 };
	//InsertSort(a, sizeof(a) / sizeof(int));

	PrintArray(a, sizeof(a) / sizeof(int));

	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestSelectSort()
{
	//int a[] = { 9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5 };
	//InsertSort(a, sizeof(a) / sizeof(int));
	//int a[] = { 2,4,1,7,8,3,9,2 };
	int a[] = { 9,1,2,5,7,4,6,3 };

	PrintArray(a, sizeof(a) / sizeof(int));
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestQuickSort()
{
	//int a[] = { 6,1,2,7,9,3,4,5,10,8 };

	int a[] = { 6,1,6,7,6,6,4,9 };
	/*int a[] = { 2,2,2,2,2,2,2,2 };
	int a[] = { 3,2,3,3,2,3,2,3 };
	int a[] = { 2,3,3,3,2,3,2,3 };*/

	PrintArray(a, sizeof(a) / sizeof(int));
	QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestMergeSort()
{
	int a[] = { 6,1,2,7,9,3,4,5,10,8,11 };
	//int a[] = { 10,6,7,1,3,9,4,2 };

	PrintArray(a, sizeof(a) / sizeof(int));
	MergeSortNonR(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));

}

void TestCountSort()
{
	int a[] = { 6,1,2,9,4,2,4,1,4,-5,-5,-3,6 };

	PrintArray(a, sizeof(a) / sizeof(int));
	CountSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestOP()
{
	srand(time(0));
	const int N = 10000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
	{

		a1[i] = rand() + i;

		//a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}

	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	MergeSort(a6, N);
	int end6 = clock();

	int begin7 = clock();
	//BubbleSort(a7, N);
	CountSort(a7, N);
	int end7 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);

	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);
	printf("CountSort:%d\n", end7 - begin7);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
}

void TestQuickSort1()
{
	srand((unsigned int)time(NULL));
	//int a[] = { 6,1,2,7,9,3,4,5,10,8 };

	int a[] = { 6,1,6,7,6,6,4,9 };
	/*int a[] = { 2,2,2,2,2,2,2,2 };
	int a[] = { 3,2,3,3,2,3,2,3 };
	int a[] = { 2,3,3,3,2,3,2,3 };*/

	PrintArray(a, sizeof(a) / sizeof(int));
	QuickSort1(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}

int main()
{
	//TestInsertSort();
	//TestShellSort();
	//TestSelectSort();
	//TestQuickSort();
	//TestMergeSort();
	//TestCountSort();
	TestQuickSort1();
	//TestOP();


	return 0;
}