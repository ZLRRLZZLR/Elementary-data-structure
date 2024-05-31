#include"queue.h"


// 初始化队列 
void QueueInit(Queue* q)
{
	q->_front = NULL;

	q->_rear = NULL;

	q->_size = 0;
}

// 队尾入队列 
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

// 队头出队列 
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

// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->_size);

	return q->_front->_data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->_size);

	return q->_rear->_data;

}

// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q);

	return q->_size;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
bool QueueEmpty(Queue* q)
{
	assert(q);

	return q->_size == 0;
}

// 销毁队列 
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