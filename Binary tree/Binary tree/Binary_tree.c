#include"Binary_tree.h"
#include"queue.h"

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);

// ����������
void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
		return;

	BinaryTreeDestory(&((*root)->_left));
	BinaryTreeDestory(&((*root)->_right));

	free(*root);
	*root = NULL;

	return;
}

// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0 : BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (NULL == root)
		return NULL;

	if (root->_left == NULL && root->_right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);

}

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (NULL == root)
	{
		return 0;
	}

	if(k == 1)
	{
		return 1;
	}

	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if(NULL == root)
	{
		return NULL;
	}

	if(root->_data == x)
	{
		return root;
	}

	BTNode* find1 = BinaryTreeFind(root->_left, x);
	BTNode* find2 = BinaryTreeFind(root->_right, x);

	if (find1)
	{
		return BinaryTreeFind(root->_left, x);
	}
	if (find2)
	{
		return BinaryTreeFind(root->_right, x);
	}

	return NULL;
}

// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N");
		return;
	}
	printf("%d",root->_data);

	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);

}

// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL");
	}

	BinaryTreePrevOrder(root->_left);
	printf("%d", root->_data);
	BinaryTreePrevOrder(root->_right);
}

// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL");
	}

	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	printf("%d", root->_data);
}

// �������
void BinaryTreeLevelOrder(BTNode* root)
{

}

// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);

	while (!(QueueEmpty(&q)))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (NULL == front)
		{
			break;
		}

		QueuePush(&q, root->_left);
		QueuePush(&q, root->_right);
	}

	while (!(QueueEmpty(&q)))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (NULL == front)
		{
			return false;
		}

		QueuePush(&q, root->_left);
		QueuePush(&q, root->_right);
	}

	return true;
}

//����
int TreeHeight(BTNode* root)
{
	if(NULL == root)
	{
		return 0;
	}

	int leftheight = TreeHeight(root->_left);
	int rightheight = TreeHeight(root->_right);

	return leftheight > rightheight ? leftheight + 1 : rightheight + 1;

}