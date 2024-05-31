#include"queue.h"


// ��ʼ������ 
void QueueInit(Queue* q)
{
	q->_front = NULL;

	q->_rear = NULL;

	q->_size = 0;
}

// ��β����� 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));

	if (NULL == newnode)
	{
		perror("QueuePush:malloc failed");
		exit(1);
	}

	newnode->_data = data;
	newnode->_next = NULL;

	if (0 == q->_size)
	{
		q->_front = q->_rear = newnode;
	}
	else
	{
		q->_rear->_next = newnode;
		q->_rear = q->_rear->_next;
	}
	q->_size++;
}

// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(q);
	assert(q->_size);

	QNode* next = q->_front->_next;
	free(q->_front);
	q->_front = next;

	if (q->_size == 1)
	{
		q->_rear = NULL;
	}

	q->_size--;

}

// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->_size);

	return q->_front->_data;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->_size);

	return q->_rear->_data;

}

// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	assert(q);

	return q->_size;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
bool QueueEmpty(Queue* q)
{
	assert(q);

	return q->_size == 0;
}

// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	assert(q);
	assert(q->_size);

	QNode* cur = q->_front;
	while(cur)
	{
		QNode* next = cur->_next;
		free(cur);

		cur = next;
	}

	q->_front = q->_rear = NULL;
	q->_size = 0;
}