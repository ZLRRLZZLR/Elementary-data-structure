#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"Stack.h"

//����
void Swap(int* a, int* b);

// ��������
void InsertSort(int* a, int n);

// ϣ������
void ShellSort(int* a, int n);

// ѡ������
void SelectSort(int* a, int n);

int GetMid(int* a, int left, int right);

// ������
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);

// ð������
void BubbleSort(int* a, int n);

// ��������ݹ�ʵ��
// ��������hoare�汾
void QuickSort1(int* a, int left, int right);

// ���������ڿӷ�
void QuickSort2(int* a, int left, int right);

// ��������ǰ��ָ�뷨
void QuickSort3(int* a, int left, int right);

// ���������Ż�֮��·����
void QuickSort4(int* a, int left, int right);

void introsort(int* a, int left, int right);

void QuickSort5(int* a, int left, int right, int* depth, int defaultdepth);

// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right);

// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n);


// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n);

void CreateData();

// ��������
void CountSort(int* a, int n);

//�����ݵ�С�ļ�
int ReadNNumSortToFile(FILE* fout, int* a, int num, const char* file);

//�鲢�����ļ�
void MergeFile(const char* file1, const char* file2, const char* mfile);

//������
void MergeSortFile(const char* file, int num);


