#include"Stack.h"

// 支持动态增长的栈
typedef int STDataType;

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

// 检测栈是否为空，如果为空返回非零结果，如果非空返回0 
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

typedef struct {
	Stack poplist;
	Stack pushlist;
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* m1 = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&m1->poplist);
	StackInit(&m1->pushlist);

	return m1;
}

void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->pushlist, x);
}

int myQueuePop(MyQueue* obj) {
	int num = myQueuePeek(obj);
	StackPop(&obj->poplist);
	return num;

}

int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&obj->poplist)) {
		while (StackSize(&obj->pushlist)) {
			StackPush(&obj->poplist, StackTop(&obj->pushlist));
			StackPop(&obj->pushlist);
		}
	}
	return StackTop(&obj->poplist);
}

bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->poplist) && StackEmpty(&obj->pushlist);
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->poplist);
	StackDestroy(&obj->pushlist);
	free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/

int main()
{
	Stack ps;
	StackInit(&ps);
	StackPush(&ps, 1);
	printf("%d\n", StackTop(&ps));
	StackPush(&ps, 2);
	printf("%d\n", StackTop(&ps));
	StackPush(&ps, 3);
	printf("%d\n", StackTop(&ps));
	StackPush(&ps, 4);
	printf("%d\n", StackTop(&ps));
	StackSize(&ps);
	StackPop(&ps);
	printf("%d\n", StackTop(&ps));
	StackPop(&ps);
	printf("%d\n", StackTop(&ps));
	StackPop(&ps);
	printf("%d\n", StackTop(&ps));
	StackPop(&ps);

	printf("%d", StackEmpty(&ps));
	StackDestroy(&ps);
	

	return 0;
}