#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

//typedef int HPDataType;
//typedef struct Heap
//{
//	HPDataType* _a;
//	int _size;
//	int _capacity;
//}HP;
//
////堆的初始化
//void HeapInit(HP* php);
//
////堆排序
//void HeapSort(HPDataType* a, int n);
//
//// 堆的销毁
//void HeapDestory(HP* hp);
//
//// 堆的插入
//void HeapPush(HP* hp, HPDataType x);
//
////向上调整算法
//void AdjustUp(HPDataType* a, int child);
//
////向下调整算法
//void AdjustDown(HPDataType* a, int n, int parent);
//
////交换
//void Swap(int* a, int* b);
//
//// 堆的删除
//void HeapPop(HP* hp);
//
//// 取堆顶的数据
//HPDataType HeapTop(HP* hp);
//
//// 堆的数据个数
//int HeapSize(HP* hp);
//
//// 堆的判空
//int HeapEmpty(HP* hp);

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

//堆的初始化
void HeapInit(Heap* php);

// 堆的销毁
void HeapDestory(Heap* hp);

// 堆的插入
void HeapPush(Heap* hp, HPDataType x);

// 堆的删除
void HeapPop(Heap* hp);

// 取堆顶的数据
HPDataType HeapTop(Heap* hp);

// 堆的数据个数
int HeapSize(Heap* hp);

// 堆的判空
int HeapEmpty(Heap* hp);

// 对数组进行堆排序
void HeapSort(int* a, int n);

//void CreateNDate()
//{
//	// 造数据
//	int n = 10000;
//	srand(time(0));
//	const char* file = "data.txt";
//	FILE* fin = fopen(file, "w");
//	if (fin == NULL)
//	{
//		perror("fopen error");
//		return;
//	}
//
//	for (size_t i = 0; i < n; ++i)
//	{
//		int x = rand() % 1000000;
//		fprintf(fin, "%d\n", x);
//	}
//
//	fclose(fin);
//}
//
//void PrintTopK(int k);