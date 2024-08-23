#include"queue.h"

#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<stdio.h>

typedef char StackDataType;
typedef struct Stack
{
    StackDataType* data;
    int size;
    int capacity;
}Stack;

void stackInit(Stack* pst)
{
    assert(pst);
    pst->data = NULL;
    pst->size = pst->capacity = 0;
}

void stackDetroy(Stack* pst)
{
    assert(pst);
    free(pst->data);
    pst->data = NULL;
    pst->size = pst->capacity = 0;
}

void checkCapacity(Stack* pst)
{
    assert(pst);
    if (pst->size == pst->capacity)
    {
        int newcapacity = pst->capacity == 0 ? 4 : 2 * pst->capacity;
        StackDataType* Newcapacity = (StackDataType*)realloc(pst->data, sizeof(StackDataType) * newcapacity);
        if (NULL == Newcapacity)
        {
            perror("realloc");
            exit(1);
        }
        else
        {
            pst->data = Newcapacity;
            pst->capacity = newcapacity;
        }
    }
    else
        return;
}

int stackIsEmpty(Stack* pst)
{
    assert(pst);
    return pst->size == 0;
}

void stackPush(Stack* pst, StackDataType data)
{
    assert(pst);
    checkCapacity(pst);
    pst->data[pst->size++] = data;
}

void stackPop(Stack* pst)
{
    assert(pst);
    assert(!stackIsEmpty(pst));
    pst->size--;

}

StackDataType stackTop(Stack* pst)
{
    assert(pst);
    assert(!stackIsEmpty(pst));
    return pst->data[pst->size - 1];

}

int stackSize(Stack* pst)
{
    return pst->size;
}

bool isValid(char* s)
{
    Stack pst;
    stackInit(&pst);
    for (int i = 0; i != '\0'; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            stackPush(&pst, s[i]);
        }
        else
        {
            if (stackIsEmpty(&pst))
                return false;
            if (s[i] == ')' && stackTop(&pst) == '(' || s[i] == '}' && stackTop(&pst) == '{' || s[i] == ']' && stackTop(&pst) == '[')
            {
                stackPop(&pst);
            }
            else
                return false;
        }
    }
    if (!stackIsEmpty(&pst))
        return false;
    else
        return true;
}

typedef struct {
    Queue q1;
    Queue q2;

} MyStack;


MyStack* myStackCreate() {
    MyStack* m1 = (MyStack*)malloc(sizeof(MyStack));
    QueueInit(&m1->q1);
    QueueInit(&m1->q2);

    return m1;

}

void myStackPush(MyStack* obj, int x) {
    if (!QueueEmpty(&obj->q1)) {
        QueuePush(&obj->q1, x);
    }
    else {
        QueuePush(&obj->q2, x);
    }
}

int myStackPop(MyStack* obj) {
    Queue* empty = &obj->q1;
    Queue* nonempty = &obj->q2;
    if (!QueueEmpty(&obj->q1)) {
        nonempty = &obj->q1;
        empty = &obj->q2;
    }
    while (QueueSize(nonempty) > 1) {
        QueuePush(empty, QueueFront(nonempty));
        QueuePop(nonempty);
    }

    int num = QueueFront(nonempty);
    QueuePop(nonempty);

    return num;
}

int myStackTop(MyStack* obj) {
    if (!QueueEmpty(&obj->q1)) {
        return QueueBack(&obj->q1);
    }
    else {
        return QueueBack(&obj->q2);
    }
}

bool myStackEmpty(MyStack* obj) {
    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
    QueueDestroy(&obj->q1);
    QueueDestroy(&obj->q2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/
int main()
{
	//Queue q;
	//QueueInit(&q);
	//QueuePush(&q, 1);
	//QueuePush(&q, 2);
	//printf("%d\n", QueueFront(&q));
	//QueuePop(&q);

	//QueuePush(&q, 3);
	//QueuePush(&q, 4);

	//while (!QueueEmpty(&q))
	//{
	//	printf("%d ", QueueFront(&q));
	//	QueuePop(&q);
	//}
	//printf("\n");
    //char s[] = {"(]"};
    //isValid(s);
    MyStack* m1 = myStackCreate();
    myStackEmpty(m1);

	return 0;
}
