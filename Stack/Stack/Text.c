#include"Stack.h"

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

// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	assert(ps);

	ps->_a = NULL;

	// topָ��ջ�����ݵ���һ��λ��
	ps->_top = 0;

	// topָ��ջ������
	//ps->_top = -1;

	ps->_capacity = 0;
}

// ��ջ 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);

	//����
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

// ��ջ 
void StackPop(Stack* ps)
{

	assert(ps);
	assert(ps->_top > 0);

	ps->_top--;

}

// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{

	assert(ps);
	assert(ps->_top > 0);

	return ps->_a[ps->_top - 1];
}

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->_top;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
bool StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->_top == 0;
}

// ����ջ 
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