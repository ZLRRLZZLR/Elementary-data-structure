#define _CRT_SECURE_NO_WARNINGS 1

#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<stdio.h>

///**二叉树的最大深度
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int maxDepth(struct TreeNode* root) {
//    if (root == NULL)
//        return 0;
//
//    int k1 = maxDepth(root->left);
//    int k2 = maxDepth(root->right);
//
//    return k1 > k2 ? k1 + 1 : k2 + 1;
//}
///**单值二叉树
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool isUnivalTree(struct TreeNode* root) {
//    if (root == NULL)
//        return true;
//
//    if (root->left && root->left->val != root->val)
//        return false;
//
//    if (root->right && root->right->val != root->val)
//        return false;
//
//    return isUnivalTree(root->left) && isUnivalTree(root->right);
//
//}
//typedef struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
//}TreeNode;
// 
//bool isUnivalTree(struct TreeNode* root) {
//    if (root == NULL)
//        return true;
//
//    if (root->left == NULL && root->right == NULL)
//        return true;
//
//    if ((root->right == NULL && root->val != root->left->val) || (root->left == NULL && root->val != root->right->val))
//        return false;
//
//    if (root->val != root->left->val && root->val != root->right->val)
//        return false;
//
//    return isUnivalTree(root->left) && isUnivalTree(root->right);
//
//}
//
//TreeNode* CreateNode(int x)
//{
//    TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
//    if(NULL == newnode)
//    {
//        perror("mallco:");
//        exit(1);
//    }
//    newnode->left = NULL;
//    newnode->right = NULL;
//    newnode->val = x;
//
//    return newnode;
//}
//
//
//
//int main()
//{
//    TreeNode* n1 = CreateNode(1);
//    TreeNode* n2 = CreateNode(1);
//    TreeNode* n3 = CreateNode(1);
//    TreeNode* n4 = CreateNode(1);
//    TreeNode* n5 = CreateNode(1);
//    TreeNode* n6 = NULL;
//    TreeNode* n7 = CreateNode(1);
//    n1->left = n2;
//    n2->left = n3;
//    n2->right = n4;
//    n1->right = n5;
//    n5->right = n7;
//    n5->left = n6;
//    isUnivalTree(n1);
//
//    return 0;
//}




//typedef struct {
//    int k;
//    int head;
//    int tail;
//    int* a;
//} MyCircularQueue;
//
//
//MyCircularQueue* myCircularQueueCreate(int k) {
//    MyCircularQueue* p = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//    p->a = (int*)malloc((k + 1) * sizeof(int));
//    p->head = 0;
//    p->tail = 0;
//    p->k = k;
//    return p;
//}
//bool myCircularQueueIsEmpty(MyCircularQueue* obj);
//bool myCircularQueueIsFull(MyCircularQueue* obj);
//
//bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
//    if (myCircularQueueIsFull(obj))
//    {
//        return false;
//    }
//    else
//    {
//        obj->a[obj->tail] = value;
//        obj->tail = (obj->tail + 1) % (obj->k + 1);
//        return true;
//    }
//}
//
//bool myCircularQueueDeQueue(MyCircularQueue* obj) {
//    if (myCircularQueueIsEmpty(obj))
//    {
//        return false;
//    }
//
//    obj->head = (obj->head + 1) % (obj->k + 1);
//    return true;
//
//}
//
//int myCircularQueueFront(MyCircularQueue* obj) {
//    if (myCircularQueueIsEmpty(obj))
//    {
//        return -1;
//    }
//    else
//    {
//        return obj->a[obj->head];
//    }
//}
//
//int myCircularQueueRear(MyCircularQueue* obj) {
//    if (myCircularQueueIsEmpty(obj))
//    {
//        return -1;
//    }
//    else
//    {
//        return obj->a[(obj->tail - 1 + obj->k + 1) % (obj->k + 1)];
//    }
//}
//
//bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
//    return obj->head == obj->tail;
//
//}
//
//bool myCircularQueueIsFull(MyCircularQueue* obj) {
//    return (obj->tail + 1) % (obj->k + 1) == obj->head)
//
//}
//
//void myCircularQueueFree(MyCircularQueue* obj) {
//    free(obj->a);
//    free(obj);
//}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/
//int main()
//{
//    MyCircularQueue* p;
//    p = myCircularQueueCreate(8);
//    int a = myCircularQueueEnQueue(p,3);
//    int b = myCircularQueueEnQueue(p,9);
//    int c = myCircularQueueEnQueue(p,5);
//    int d = myCircularQueueEnQueue(p,0);
//    int e = myCircularQueueDeQueue(p);
//    int f = myCircularQueueDeQueue(p);
//    int g = myCircularQueueIsEmpty(p);
//    int h = myCircularQueueIsEmpty(p);
//    int i = myCircularQueueRear(p);
//    int j = myCircularQueueRear(p);
//    return 0;
//}
//#include<stdlib.h>
//#include<stdbool.h>
//#include<assert.h>
//#include<stdio.h>
//
//
//// 支持动态增长的栈
//typedef int STDataType;
//
//typedef struct Stack
//{
//	STDataType* _a;
//	int _top;		// 栈顶
//	int _capacity;  // 容量 
//}Stack;
//// 初始化栈 
//void StackInit(Stack* ps)
//{
//	ps->_a = NULL;
//	ps->_capacity = ps->_top = 0;
//}
//
//// 入栈 
//void StackPush(Stack* ps, STDataType data)
//{
//	assert(ps);
//	if (ps->_capacity == ps->_top)
//	{
//		int newcapacity = ps->_capacity == 0 ? 4 : 2 * ps->_capacity;
//		STDataType* newnode = (STDataType*)realloc(ps->_a, newcapacity * sizeof(STDataType));
//
//		if (NULL == newnode)
//		{
//			perror("StackInit:realloc");
//			exit(1);
//		}
//		ps->_a = newnode;
//		ps->_capacity = newcapacity;
//	}
//
//	ps->_a[ps->_top] = data;
//	ps->_top++;
//}
//
//// 出栈 
//void StackPop(Stack* ps)
//{
//
//	assert(ps);
//	assert(ps->_top > 0);
//
//	ps->_top--;
//
//}
//
//// 获取栈顶元素 
//STDataType StackTop(Stack* ps)
//{
//
//	assert(ps);
//	assert(ps->_top > 0);
//
//	return ps->_a[ps->_top - 1];
//}
//
//// 获取栈中有效元素个数 
//int StackSize(Stack* ps)
//{
//	assert(ps);
//
//	return ps->_top;
//}
//
//// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
//bool StackEmpty(Stack* ps)
//{
//	assert(ps);
//	return ps->_top == 0;
//}
//
//// 销毁栈 
//void StackDestroy(Stack* ps)
//{
//	assert(ps);
//	free(ps->_a);
//	ps->_a = NULL;
//	ps->_capacity = ps->_top = 0;
//}
//typedef struct {
//	Stack pushst;
//	Stack popst;
//} MyQueue;
//
//
//MyQueue* myQueueCreate() {
//	MyQueue* q1 = (MyQueue*)malloc(sizeof(MyQueue));
//	StackInit(&q1->pushst);
//	StackInit(&q1->popst);
//	return q1;
//}
//
//void myQueuePush(MyQueue* obj, int x) {
//	StackPush(&obj->pushst, x);
//}
//
//int myQueuePeek(MyQueue* obj);
//int myQueuePop(MyQueue* obj) {
//	int top = myQueuePeek(obj);
//	StackPop(&obj->popst);
//	return top;
//
//}
//
//int myQueuePeek(MyQueue* obj) {
//	if (StackEmpty(&obj->popst))
//	{
//		while (!StackEmpty(&obj->pushst))
//		{
//			StackPush(&obj->popst, StackTop(&obj->pushst));
//			StackPop(&obj->pushst);
//		}
//		return StackTop(&obj->popst);
//	}
//	else
//	{
//		return StackTop(&obj->popst);
//	}
//}
//
//bool myQueueEmpty(MyQueue* obj) {
//	return StackEmpty(&obj->pushst) && StackEmpty(&obj->popst);
//}
//
//void myQueueFree(MyQueue* obj) {
//	StackDestroy(&obj->pushst);
//	StackDestroy(&obj->popst);
//	free(obj);
//}
//
///**
// * Your MyQueue struct will be instantiated and called as such:
// * MyQueue* obj = myQueueCreate();
// * myQueuePush(obj, x);
//
// * int param_2 = myQueuePop(obj);
//
// * int param_3 = myQueuePeek(obj);
//
// * bool param_4 = myQueueEmpty(obj);
//
// * myQueueFree(obj);
//*/
//int main()
//{
//    MyQueue* q1;
//    q1 = myQueueCreate();
//    myQueuePush(q1, 1);
//    myQueuePush(q1, 2);
//	myQueuePeek(q1);
//	myQueuePop(q1);
//	myQueueEmpty(q1);
//    return 0;
//}
//#include<stdlib.h>
//#include<stdbool.h>
//#include<assert.h>
//#include<stdio.h>
//
//
//// 支持动态增长的栈
//typedef int STDataType;
//
//typedef struct Stack
//{
//    STDataType* _a;
//    int _top;		// 栈顶
//    int _capacity;  // 容量 
//}Stack;
//
//
//// 初始化栈 
//void StackInit(Stack* ps)
//{
//    ps->_a = NULL;
//    ps->_capacity = ps->_top = 0;
//}
//
//// 入栈 
//void StackPush(Stack* ps, STDataType data)
//{
//    assert(ps);
//    if (ps->_capacity == ps->_top)
//    {
//        int newcapacity = ps->_capacity == 0 ? 4 : 2 * ps->_capacity;
//        STDataType* newnode = (STDataType*)realloc(ps->_a, newcapacity * sizeof(STDataType));
//
//        if (NULL == newnode)
//        {
//            perror("StackInit:realloc");
//            exit(1);
//        }
//        ps->_a = newnode;
//        ps->_capacity = newcapacity;
//    }
//
//    ps->_a[ps->_top] = data;
//    ps->_top++;
//}
//
//// 出栈 
//void StackPop(Stack* ps)
//{
//
//    assert(ps);
//    assert(ps->_top > 0);
//
//    ps->_top--;
//
//}
//
//// 获取栈顶元素 
//STDataType StackTop(Stack* ps)
//{
//
//    assert(ps);
//    assert(ps->_top > 0);
//
//    return ps->_a[ps->_top - 1];
//}
//
//// 获取栈中有效元素个数 
//int StackSize(Stack* ps)
//{
//    assert(ps);
//
//    return ps->_top;
//}
//
//// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
//bool StackEmpty(Stack* ps)
//{
//    assert(ps);
//    return ps->_top == 0;
//}
//
//// 销毁栈 
//void StackDestroy(Stack* ps)
//{
//    assert(ps);
//    free(ps->_a);
//    ps->_a = NULL;
//    ps->_capacity = ps->_top = 0;
//}
//
//
//typedef struct {
//    Stack s1;
//    Stack s2;
//} MyQueue;
//
//
//MyQueue* myQueueCreate() {
//    MyQueue* pqu = (MyQueue*)malloc(sizeof(MyQueue));
//
//    StackInit(&pqu->s1);
//    StackInit(&pqu->s2);
//
//    return pqu;
//}
//
//void myQueuePush(MyQueue* obj, int x) {
//    if (StackEmpty(&obj->s1))
//    {
//        StackPush(&obj->s1, x);
//    }
//    else
//    {
//        StackPush(&obj->s2, x);
//    }
//}
//
//int myQueuePop(MyQueue* obj) {
//    Stack* empty = &obj->s1;
//    Stack* nonempty = &obj->s2;
//
//    if (!StackEmpty(&obj->s1))
//    {
//        nonempty = &obj->s1;
//        empty = &obj->s2;
//    }
//    while (nonempty->_top > 1)
//    {
//        StackPush(empty, StackTop(nonempty));
//        StackPop(nonempty);
//    }
//
//    int top = StackTop(nonempty);
//    StackPop(nonempty);
//    return top;
//}
//
//int myQueuePeek(MyQueue* obj) {
//
//    if (!StackEmpty(&obj->s1))
//    {
//        return &obj->s1._a[0];
//    }
//    else
//    {
//        return &obj->s2._a[0];
//    }
//}
//
//bool myQueueEmpty(MyQueue* obj) {
//
//    return StackEmpty(&obj->s1) && StackEmpty(&obj->s2);
//
//}
//
//void myQueueFree(MyQueue* obj) {
//    StackDestroy(&obj->s1);
//    StackDestroy(&obj->s2);
//
//    free(obj);
//}
//
///**
// * Your MyQueue struct will be instantiated and called as such:
// * MyQueue* obj = myQueueCreate();
// * myQueuePush(obj, x);
//
// * int param_2 = myQueuePop(obj);
//
// * int param_3 = myQueuePeek(obj);
//
// * bool param_4 = myQueueEmpty(obj);
//
// * myQueueFree(obj);
//*/
//
//int main()
//{
//    MyQueue* q1;
//    q1 = myQueueCreate();
//    myQueuePush(q1, 1);
//    myQueuePush(q1, 2);
//    myQueuePush(q1, 3);
//    myQueuePush(q1, 4);
//    int a = myQueuePop(q1);
//    myQueuePush(q1, 5);
//    int b = myQueuePop(q1);
//    int c = myQueuePop(q1);
//    int d = myQueuePop(q1);
//    int e = myQueuePop(q1);
//    return 0;
//}




//用队列实现栈
//#include<stdio.h>
//#include<assert.h>
//#include<stdlib.h>
//#include"stdbool.h"
//
//typedef int QDataType;
//
//// 链式结构：表示队列 
//typedef struct QListNode
//{
//	struct QListNode* _next;
//	QDataType _data;
//}QNode;
//
//// 队列的结构 
//typedef struct Queue
//{
//	QNode* _front;
//	QNode* _rear;
//	int _size;
//}Queue;
//void QueueInit(Queue* q)
//{
//	q->_front = NULL;
//
//	q->_rear = NULL;
//
//	q->_size = 0;
//}
//
//// 队尾入队列 
//void QueuePush(Queue* q, QDataType data)
//{
//	assert(q);
//	QNode* newnode = (QNode*)malloc(sizeof(QNode));
//
//	if (NULL == newnode)
//	{
//		perror("QueuePush:malloc failed");
//		exit(1);
//	}
//
//	newnode->_data = data;
//	newnode->_next = NULL;
//
//	if (0 == q->_size)
//	{
//		q->_front = q->_rear = newnode;
//	}
//	else
//	{
//		q->_rear->_next = newnode;
//		q->_rear = q->_rear->_next;
//	}
//	q->_size++;
//}
//
//// 队头出队列 
//void QueuePop(Queue* q)
//{
//	assert(q);
//	assert(q->_size);
//
//	QNode* next = q->_front->_next;
//	free(q->_front);
//	q->_front = next;
//
//	if (q->_size == 1)
//	{
//		q->_rear = NULL;
//	}
//
//	q->_size--;
//
//}
//
//// 获取队列头部元素 
//QDataType QueueFront(Queue* q)
//{
//	assert(q);
//	assert(q->_size);
//
//	return q->_front->_data;
//}
//
//// 获取队列队尾元素 
//QDataType QueueBack(Queue* q)
//{
//	assert(q);
//	assert(q->_size);
//
//	return q->_rear->_data;
//
//}
//
//// 获取队列中有效元素个数 
//int QueueSize(Queue* q)
//{
//	assert(q);
//
//	return q->_size;
//}
//
//// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
//bool QueueEmpty(Queue* q)
//{
//	assert(q);
//
//	return q->_size == 0;
//}
//
//// 销毁队列 
//void QueueDestroy(Queue* q)
//{
//	assert(q);
//
//	QNode* cur = q->_front;
//	while (cur)
//	{
//		QNode* next = cur->_next;
//		free(cur);
//
//		cur = next;
//	}
//
//	q->_front = q->_rear = NULL;
//	q->_size = 0;
//}
//typedef struct {
//	Queue q1;
//	Queue q2;
//} MyStack;
//
//
//MyStack* myStackCreate() {
//	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
//	if (NULL == pst)
//	{
//		perror("malloc");
//		exit(1);
//	}
//	QueueInit(&pst->q1);
//	QueueInit(&pst->q2);
//	return pst;
//}
//
//void myStackPush(MyStack* obj, int x) {
//	if (!QueueEmpty(&obj->q1))
//	{
//		QueuePush(&obj->q1, x);
//	}
//	else
//	{
//		QueuePush(&obj->q2, x);
//	}
//}
//
//int myStackPop(MyStack* obj) {
//	Queue* empty = &obj->q1;
//	Queue* nonempty = &obj->q2;
//	if (!QueueEmpty(&obj->q1))
//	{
//		nonempty = &obj->q1;
//		empty = &obj->q2;
//	}
//	while (QueueSize(nonempty) > 1)
//	{
//		QueuePush(empty, QueueFront(nonempty));
//		QueuePop(nonempty);
//	}
//
//	int top = QueueFront(nonempty);
//	QueuePop(nonempty);
//	return  top;
//}
//
//int myStackTop(MyStack* obj) {
//	if (!QueueEmpty(&obj->q1))
//	{
//		return QueueBack(&obj->q1);
//	}
//	else
//	{
//		return QueueBack(&obj->q2);
//	}
//}
//
//bool myStackEmpty(MyStack* obj) {
//	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
//}
//
//void myStackFree(MyStack* obj) {
//	QueueDestroy(&obj->q1);
//	QueueDestroy(&obj->q2);
//
//	free(obj);
//}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/
//括号匹配
//#include<stdlib.h>
//#include<stdbool.h>
//#include<assert.h>
//#include<stdio.h>


//// 支持动态增长的栈
//typedef int STDataType;
//
//typedef struct Stack
//{
//	STDataType* _a;
//	int _top;		// 栈顶
//	int _capacity;  // 容量 
//}Stack;
//
//// 初始化栈 
//void StackInit(Stack* ps)
//{
//	ps->_a = NULL;
//	ps->_capacity = ps->_top = 0;
//}
//
//// 入栈 
//void StackPush(Stack* ps, STDataType data)
//{
//	assert(ps);
//	if (ps->_capacity == ps->_top)
//	{
//		int newcapacity = ps->_capacity == 0 ? 4 : 2 * ps->_capacity;
//		STDataType* newnode = (STDataType*)realloc(ps->_a, newcapacity * sizeof(STDataType));
//
//		if (NULL == newnode)
//		{
//			perror("StackInit:realloc");
//			exit(1);
//		}
//		ps->_a = newnode;
//		ps->_capacity = newcapacity;
//	}
//
//	ps->_a[ps->_top] = data;
//	ps->_top++;
//}
//
//// 出栈 
//void StackPop(Stack* ps)
//{
//
//	assert(ps);
//	assert(ps->_top > 0);
//
//	ps->_top--;
//
//}
//
//// 获取栈顶元素 
//STDataType StackTop(Stack* ps)
//{
//
//	assert(ps);
//	assert(ps->_top > 0);
//
//	return ps->_a[ps->_top - 1];
//}
//
//// 获取栈中有效元素个数 
//int StackSize(Stack* ps)
//{
//	assert(ps);
//
//	return ps->_top;
//}
//
//// 检测栈是否为空，如果为空返回0，如果不为空返回非零结果
//bool StackEmpty(Stack* ps)
//{
//	assert(ps);
//	return ps->_top;
//}
//
//// 销毁栈 
//void StackDestroy(Stack* ps)
//{
//	assert(ps);
//	free(ps->_a);
//	ps->_a = NULL;
//	ps->_capacity = ps->_top = 0;
//}
//
//
//bool isValid(char* s)
//{
//	Stack p;
//	StackInit(&p);
//	while (*s)
//	{
//		//左括号入栈
//		if (*s == '(' || *s == '{' || *s == '[')
//		{
//			StackPush(&p, *s);
//		}
//		else//右括号取栈顶左括号尝试匹配
//		{
//			if (!StackEmpty(&p))//栈内没有左括号
//			{
//				StackDestroy(&p);
//				return false;
//			}
//			char top = 0;
//			top = StackTop(&p);//不匹配
//			if (top == '(' && *s != ')' || top == '{' && *s != '}' || top == '[' && *s != ']')
//			{
//				StackDestroy(&p);
//				return false;
//			}
//			StackPop(&p);
//		}
//
//		s++;
//	}
//	int ret = !StackEmpty(&p);//栈内是否有多余左括号
//	StackDestroy(&p);
//	return ret;
//}

////随机链表的复制
///**
// * Definition for a Node.
// * struct Node {
// *     int val;
// *     struct Node *next;
// *     struct Node *random;
// * };
// */
//
//struct Node* copyRandomList(struct Node* head) {
//	struct Node* cur = head;
//	while (cur)
//	{
//		struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
//		newnode->val = cur->val;
//
//		newnode->next = cur->next;
//		cur->next = newnode;
//
//		cur = newnode->next;
//	}
//	cur = head;
//
//	while (cur)
//	{
//		struct Node* copy = cur->next;
//		if (cur->random == NULL)
//		{
//			copy->random = cur->random;
//		}
//		else
//		{
//			copy->random = cur->random->next;
//		}
//		cur = copy->next;
//	}
//	cur = head;
//	struct Node* newhead = NULL;
//	struct Node* newtail = NULL;
//	while (cur)
//	{
//		struct Node* copy = cur->next;
//		struct Node* next = copy->next;
//		if (newtail == NULL)
//		{
//			newhead = newtail = copy;
//		}
//		else
//		{
//			newtail->next = copy;
//			newtail = newtail->next;
//		}
//		cur->next = next;
//		cur = next;
//	}
//	return newhead;
//}
///**//环形链表II
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* detectCycle(struct ListNode* head) {
//	struct ListNode* slow = head;
//	struct ListNode* fast = head;
//	while (fast && fast->next)
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//		if (fast == slow)
//		{
//			struct ListNode* meet = slow;
//			while (meet != head)
//			{
//				meet = meet->next;
//				head = head->next;
//			}
//			return meet;
//		}
//	}
//	return NULL;
//
//}

//环形链表
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//bool hasCycle(struct ListNode* head) {
//	struct ListNode* slow = head;
//	struct ListNode* fast = head;
//	while (fast && fast->next)
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//		if (fast == slow)
//		{
//			return true;
//		}
//	}
//	return false;
//}
// //相交链表
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//	int len1 = 0, len2 = 0;
//	struct ListNode* HeadA = headA, * HeadB = headB;
//	while (HeadA)
//	{
//		HeadA = HeadA->next;
//		len1++;
//	}
//	while (HeadB)
//	{
//		HeadB = HeadB->next;
//		len2++;
//	}
//	int gap = abs(len1 - len2);
//	struct ListNode* longer = headA, * shoter = headB;
//	if (len2 > len1)
//	{
//		longer = headB;
//		shoter = headA;
//	}
//	while (gap--)
//	{
//		longer = longer->next;
//	}
//	while (longer && shoter)
//	{
//		if (longer == shoter)
//		{
//			return longer;
//		}
//		longer = longer->next;
//		shoter = shoter->next;
//	}
//	return NULL;
//}

//链表的回文结构
///*
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};*/
//ListNode* Mid(ListNode* head)
//{
//	struct ListNode* slow = head, * fast = head;
//	while (fast && fast->next)
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//	}
//	return slow;
//}
//ListNode* Reverse(ListNode* head)
//{
//	struct ListNode* cur = head, * newhead = NULL;
//	while (cur)
//	{
//		struct ListNode* n = cur->next;
//		cur->next = newhead;
//		newhead = cur;
//		cur = n;
//	}
//	return newhead;
//
//}
//class PalindromeList {
//public:
//	bool chkPalindrome(ListNode* A) {
//		struct ListNode* mid = Mid(A);
//		struct ListNode* Newhead = Reverse(mid);
//		while (A && Newhead)
//		{
//			if (A->val != Newhead->val)
//			{
//				return false;
//			}
//			A = A->next;
//			Newhead = Newhead->next;
//		}
//		return true;
//	}
//};

//实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。
//int kthToLast(struct ListNode* head, int k) {
//	struct ListNode* slow = head, * fast = head;
//	while (k--)
//	{
//		fast = fast->next;
//	}
//	while (fast)
//	{
//		fast = fast->next;
//		slow = slow->next;
//	}
//	return slow->val;
//}
// ///**//合并两个有序链表
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//typedef struct ListNode ListNode;
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//	if (list1 == NULL)
//		return list2;
//	if (list2 == NULL)
//		return list1;
//	ListNode* l1 = list1;
//	ListNode* l2 = list2;
//	ListNode* newhead = NULL, * newtail = NULL;
//	while (l1 && l2)
//	{
//		if (l1->val < l2->val)
//		{
//			if (newhead == NULL)
//			{
//				newhead = newtail = l1;
//			}
//			else
//			{
//				newtail->next = l1;
//				newtail = newtail->next;
//			}
//			l1 = l1->next;
//		}
//		else
//		{
//			if (newhead == NULL)
//			{
//				newhead = newtail = l2;
//			}
//			else
//			{
//				newtail->next = l2;
//				newtail = newtail->next;
//			}
//			l2 = l2->next;
//		}
//	}
//	if (l1 == NULL)
//	{
//		newtail->next = l2;
//
//
//	}
//	if (l2 == NULL)
//	{
//		newtail->next = l1;
//
//
//	}
//	return newhead;
//}


//约瑟夫问题环形链表
///**
// * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
// *
// *
// * @param n int整型
// * @param m int整型
// * @return int整型
// */
//typedef struct ListNode ListNode;
//ListNode* buynode(int x)
//{
//	ListNode* next = (ListNode*)malloc(sizeof(ListNode));
//	if (NULL == next)
//	{
//		exit(1);
//	}
//	next->val = x;
//	next->next = NULL;
//	return next;
//}
//ListNode* creatcricle(int n)
//{
//	ListNode* phead = buynode(1);
//	ListNode* pcur = phead;
//	for (int i = 2; i <= n; i++)
//	{
//		pcur->next = buynode(i);
//		pcur = pcur->next;
//	}
//	pcur->next = phead;
//	return pcur;
//}
//
//int ysf(int n, int m) {
//	ListNode* prev = creatcricle(n);
//	ListNode* pcur = prev->next;
//	int count = 1;
//	while (pcur->next != pcur)
//	{
//		if (m == count)
//		{
//			prev->next = pcur->next;
//			free(pcur);
//			pcur = prev->next;
//			count = 1;
//		}
//		else
//		{
//			prev = pcur;
//			pcur = pcur->next;
//			count++;
//		}
//
//	}
//	return pcur->val;
//}
//快慢指针寻找中间节点
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //typedef struct ListNode ListNode;
 //struct ListNode* middleNode(struct ListNode* head) {
 //	ListNode* slow = head;
 //	ListNode* fast = head;
 //	while (fast && fast->next)
 //	{
 //		slow = slow->next;
 //		fast = fast->next->next;
 //	}
 //	return slow;
 //}

 //移除链表元素
 ///**
 // * Definition for singly-linked list.
 // * struct ListNode {
 // *     int val;
 // *     struct ListNode *next;
 // * };
 // */
 //typedef struct ListNode ListNode;
 //struct ListNode* removeElements(struct ListNode* head, int val) {
 //	ListNode* pcur = head;
 //	ListNode* newtail, * newhead;
 //	newtail = newhead = NULL;
 //
 //	while (pcur)
 //	{
 //		if (pcur->val != val)
 //		{
 //			if (newhead == NULL)
 //			{
 //				newhead = newtail = pcur;
 //			}
 //			else
 //			{
 //				newtail->next = pcur;
 //				newtail = pcur;
 //			}
 //		}
 //		pcur = pcur->next;
 //	}
 //	if (newhead != NULL)
 //		newtail->next = NULL;
 //	return newhead;
 //}