#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<stdio.h>


// ֧�ֶ�̬������ջ
typedef int STDataType;

typedef struct Stack
{
	STDataType* _a;
	int _top;		// ջ��
	int _capacity;  // ���� 
}Stack;

// ��ʼ��ջ 
void StackInit(Stack* ps);

// ��ջ 
void StackPush(Stack* ps, STDataType data);

// ��ջ 
void StackPop(Stack* ps);

// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps);

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps);

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ���0 �������Ϊ�շ��ط�����
bool StackEmpty(Stack* ps);

// ����ջ 
void StackDestroy(Stack* ps);
