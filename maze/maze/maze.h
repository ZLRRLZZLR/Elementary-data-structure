#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
#include<stdio.h>
#include<stdlib.h>
#include"stdbool.h"
#include<time.h>
#include<assert.h>

//初始得分为500
#define initial_score 500

//每个宝藏的分数
#define treasure_points 50

//未找到的宝藏的罚分
#define missing_treasure_penalty 30

//每走一步的罚分
#define step_penalty  1  

//宝藏总数量
#define treasures_number 12 

//障碍总数量
#define obstacle_number 40 

//地图行数
#define ROWS 40

//地图列数
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


// 支持动态增长的栈
typedef struct POS STDataType;

typedef struct Stack
{
	STDataType* _a;
	int _top;		// 栈顶
	int _capacity;  // 容量 
}Stack;

// 初始化栈 
void StackInit(Stack* ps);

// 入栈 
void StackPush(Stack* ps, STDataType data);

// 出栈 
void StackPop(Stack* ps);

// 获取栈顶元素 
STDataType StackTop(Stack* ps);

// 获取栈中有效元素个数 
int StackSize(Stack* ps);

// 检测栈是否为空，如果为空返回0 ，如果不为空返回非零结果
bool StackEmpty(Stack* ps);

// 销毁栈 
void StackDestroy(Stack* ps);

void CreatMaze(environmt* e);
void DSF(preson* p, environmt* e,int direction,Stack s);
