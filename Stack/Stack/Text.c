#include"Stack.h"

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