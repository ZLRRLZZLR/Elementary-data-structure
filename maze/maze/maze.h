#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
#include<stdio.h>
#include<stdlib.h>
#include"stdbool.h"
#include<time.h>
#include<assert.h>

//��ʼ�÷�Ϊ500
#define initial_score 500

//ÿ�����صķ���
#define treasure_points 50

//δ�ҵ��ı��صķ���
#define missing_treasure_penalty 30

//ÿ��һ���ķ���
#define step_penalty  1  

//����������
#define treasures_number 12 

//�ϰ�������
#define obstacle_number 40 

//��ͼ����
#define ROWS 40

//��ͼ����
#define COLS 40


enum DIRECTION {UP = 1,DOWN,LEFT,RIGHT};

typedef struct PRESON
{
	int x;
	int y;
	int direction;
	int steps;
	int treasuresfound;
}preson;


typedef struct ENVIRONMENT
{
	char maze[ROWS][COLS];
	bool ifvisit[ROWS][COLS];

}environmt;

typedef struct POS
{
	int x;
	int y;

}pos;


// ֧�ֶ�̬������ջ
typedef struct POS STDataType;

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

void CreatMaze(environmt* e);
void DSF(preson* p, environmt* e,int direction,Stack s);
