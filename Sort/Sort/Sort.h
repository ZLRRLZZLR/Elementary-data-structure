#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//����
void Swap(int* a,int* b);

// ��������
void InsertSort(int* a, int n);

// ϣ������
void ShellSort(int* a, int n);

// ѡ������
void SelectSort(int* a, int n);


// ������
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);