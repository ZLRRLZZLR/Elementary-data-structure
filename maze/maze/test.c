#include"maze.h"


int main()
{
	srand((unsigned int)time(NULL));
	preson p1 = {0};
	environmt e1;
	CreatMaze(&e1);
	int scores = 500;
	//for(int i = 0;i < 40;i++)
	//{
	//	for (int j = 0; j < 40; j++)
	//	{
	//		printf("%c",e1.maze[i][j]);
	//	}
	//}
	Stack  s1;
	StackInit(&s1);
	DSF(&p1, &e1, UP,&s1);

	scores = scores - p1.steps + p1.treasuresfound * 50 - (treasures_number - p1.treasuresfound) * 30;
	printf("%d",scores);
	return 0;
}
