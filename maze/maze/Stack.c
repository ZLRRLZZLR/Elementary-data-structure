#include"Stack.h"

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
	if(ps->_capacity == ps->_top)
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

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
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