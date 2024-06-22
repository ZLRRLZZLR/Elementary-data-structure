#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
#include<stdio.h>
#include<stdlib.h>
#include"stdbool.h"


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

//����������
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


void CreatMaze(environmt* e);
void DSF(preson* p, environmt* e);
