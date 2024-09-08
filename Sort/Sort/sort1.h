#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"Stack.h"

//交换
void Swap(int* a, int* b);

// 插入排序
void InsertSort(int* a, int n);

// 希尔排序
void ShellSort(int* a, int n);

// 选择排序
void SelectSort(int* a, int n);

int GetMid(int* a, int left, int right);

// 堆排序
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);

// 冒泡排序
void BubbleSort(int* a, int n);

// 快速排序递归实现
// 快速排序hoare版本
void QuickSort1(int* a, int left, int right);

// 快速排序挖坑法
void QuickSort2(int* a, int left, int right);

// 快速排序前后指针法
void QuickSort3(int* a, int left, int right);

// 快速排序优化之三路划分
void QuickSort4(int* a, int left, int right);

void introsort(int* a, int left, int right);

void QuickSort5(int* a, int left, int right, int* depth, int defaultdepth);

// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right);

// 归并排序递归实现
void MergeSort(int* a, int n);


// 归并排序非递归实现
void MergeSortNonR(int* a, int n);

void CreateData();

// 计数排序
void CountSort(int* a, int n);

//读数据到小文件
int ReadNNumSortToFile(FILE* fout, int* a, int num, const char* file);

//归并两个文件
void MergeFile(const char* file1, const char* file2, const char* mfile);

//外排序
void MergeSortFile(const char* file, int num);


