#include"maze.h"

void CreatMaze(environmt* e)
{
	for(int i = 0;i < ROWS;i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			e->maze[i][j] = '~';
		}
	}
	e->maze[0][0] = 'S';
	e->maze[ROWS - 1][COLS - 1] = 'E';

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			e->ifvisit[i][j] = false;
		}
	}

	//≤º÷√±¶≤ÿ
	for(int i = 0; i < treasures_number;i++)
	{
		int x = rand() % ROWS;
		int y = rand() % COLS;

	}

}


void DSF(preson* p, environmt* e)
{
	
}



