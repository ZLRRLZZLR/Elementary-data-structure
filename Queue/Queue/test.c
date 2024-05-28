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
    char s[] = {"(]"};
    isValid(s);
	return 0;
}
