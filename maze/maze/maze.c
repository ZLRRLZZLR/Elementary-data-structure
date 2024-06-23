#include"maze.h"

// 初始化栈 
void StackInit(Stack* ps)
{
	assert(ps);

	ps->_a = NULL;

	// top指向栈顶数据的下一个位置
	ps->_top = 0;

	// top指向栈顶数据
	//ps->_top = -1;

	ps->_capacity = 0;
}

// 入栈 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);

	//扩容
	if (ps->_capacity == ps->_top)
	{
		int newcapacity = ps->_capacity == 0 ? 4 : 2 * ps->_capacity;
		STDataType* newnode = (STDataType*)realloc(ps->_a, newcapacity * sizeof(STDataType));

		if (NULL == newnode)
		{
			perror("StackInit:realloc");
			exit(1);
		}

		ps->_a = newnode;
		ps->_capacity = newcapacity;
	}

	ps->_a[ps->_top] = data;
	ps->_top++;
}

// 出栈 
void StackPop(Stack* ps)
{

	assert(ps);
	assert(ps->_top > 0);

	ps->_top--;

}

// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{

	assert(ps);
	assert(ps->_top > 0);

	return ps->_a[ps->_top - 1];
}

// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->_top;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
bool StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->_top == 0;
}

// 销毁栈 
void StackDestroy(Stack* ps)
{
	assert(ps);

	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}

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

	//布置宝藏
	for(int i = treasures_number; i > 0;)
	{
		int x = rand() % ROWS;
		int y = rand() % COLS;
		if(e->maze[x][y] != 'C' && e->maze[x][y] != 'S' && e->maze[x][y] != 'E')
		{
			e->maze[x][y] = 'C';
			i--;
		}
	}

	//布置障碍
	for (int i = obstacle_number; i > 0;)
	{
		int x = rand() % ROWS;
		int y = rand() % COLS;
		if (e->maze[x][y] != 'C' && e->maze[x][y] != 'S' && e->maze[x][y] != 'E')
		{
			e->maze[x][y] = '#';
			i--;
		}
	}

}

void Move(preson* p, environmt* e, int direction, Stack s)
{
	switch (direction)
	{
	case UP:
		p->y -= 1;
		p->steps++;
		e->ifvisit[p->x][p->y] = true;
		break;
	case DOWN:
		p->y += 1;
		p->steps++;
		e->ifvisit[p->x][p->y] = true;
		break;
	case LEFT:
		p->x -= 1;
		p->steps++;
		e->ifvisit[p->x][p->y] = true;
		break;
	case RIGHT:
		p->x += 1;
		p->steps++;
		e->ifvisit[p->x][p->y] = true;
		break;
	default:
		break;
	}
}


void DSF(preson* p, environmt* e,int direction,Stack* s)
{
	if(e->maze[p->x][p->y] == 'E')
	{
		return true;
	}
	switch (direction)
	{
	case UP:
		p->y -= 1;
		p->steps++;
		e->ifvisit[p->x][p->y] = true;
		break;
	case DOWN:
		p->y += 1;
		p->steps++;
		e->ifvisit[p->x][p->y] = true;
		break;
	case LEFT:
		p->x -= 1;
		p->steps++;
		e->ifvisit[p->x][p->y] = true;
		break;
	case RIGHT:
		p->x += 1;
		p->steps++;
		e->ifvisit[p->x][p->y] = true;
		break;
	default:
		break;
	}

	if(e->maze[p->x][p->y] == 'C')
	{
		p->treasuresfound += 1;

	}





}



