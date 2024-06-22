#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
#include<stdio.h>
#include<stdlib.h>
#include"stdbool.h"


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

//宝藏总数量
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


void CreatMaze(environmt* e);
void DSF(preson* p, environmt* e);
