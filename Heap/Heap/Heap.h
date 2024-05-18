#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}HP;

//�ѵĳ�ʼ��
void HeapInit(HP* php);

void HeapSort(int* a, int n);

// �ѵ�����
void HeapDestory(HP* hp);

// �ѵĲ���
void HeapPush(HP* hp, HPDataType x);

//���ϵ����㷨
void AdjustUp(HPDataType* a, int child);

//���µ����㷨
void AdjustDown(HPDataType* a, int n, int parent);

//����
void Swap(int* a, int* b);

// �ѵ�ɾ��
void HeapPop(HP* hp);

// ȡ�Ѷ�������
HPDataType HeapTop(HP* hp);

// �ѵ����ݸ���
int HeapSize(HP* hp);

// �ѵ��п�
int HeapEmpty(HP* hp);