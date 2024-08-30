#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<assert.h>

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

//���ϵ���
void AdjustUp();

//���µ���
void AdjustDown();

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

void CreateNDate();

//TopK����
void PrintTopK(int k);