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
////�ѵĳ�ʼ��
//void HeapInit(HP* php);
//
////������
//void HeapSort(HPDataType* a, int n);
//
//// �ѵ�����
//void HeapDestory(HP* hp);
//
//// �ѵĲ���
//void HeapPush(HP* hp, HPDataType x);
//
////���ϵ����㷨
//void AdjustUp(HPDataType* a, int child);
//
////���µ����㷨
//void AdjustDown(HPDataType* a, int n, int parent);
//
////����
//void Swap(int* a, int* b);
//
//// �ѵ�ɾ��
//void HeapPop(HP* hp);
//
//// ȡ�Ѷ�������
//HPDataType HeapTop(HP* hp);
//
//// �ѵ����ݸ���
//int HeapSize(HP* hp);
//
//// �ѵ��п�
//int HeapEmpty(HP* hp);

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

//�ѵĳ�ʼ��
void HeapInit(Heap* php);

// �ѵ�����
void HeapDestory(Heap* hp);

// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x);

// �ѵ�ɾ��
void HeapPop(Heap* hp);

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);

// �ѵ����ݸ���
int HeapSize(Heap* hp);

// �ѵ��п�
int HeapEmpty(Heap* hp);

// ��������ж�����
void HeapSort(int* a, int n);

//void CreateNDate()
//{
//	// ������
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