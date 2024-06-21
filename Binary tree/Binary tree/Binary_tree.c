#include"Binary_tree.h"
#include"queue.h"

BTNode* BuyNode(int x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		return NULL;
	}

	node->_data = x;
	node->_left = NULL;
	node->_right = NULL;

	return node;
}

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	BTNode* node = NULL;

	if (*pi >= n)
		return NULL;
	if(a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}

	node = BuyNode(a[(*pi)++]);

	node->_left = BinaryTreeCreate(a,n,pi);
	node->_right = BinaryTreeCreate(a, n, pi);

	return node;
}

// 二叉树销毁
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

// 错误示范
//int TreeSize(BTNode* root)
//{
//	static int size = 0;
//	if (root == NULL)
//		return 0;
//	else
//		++size;
//
//	TreeSize(root->left);
//	TreeSize(root->right);
//
//	return size;
//}

//int size = 0;
//int TreeSize(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//	else
//		++size;
//
//	TreeSize(root->left);
//	TreeSize(root->right);
//
//	return size;
//}

//void TreeSize(BTNode* root, int* psize)
//{
//	if (root == NULL)
//		return 0;
//	else
//		++(*psize);
//
//	TreeSize(root->left, psize);
//	TreeSize(root->right, psize);
//}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0 : BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (NULL == root)
		return NULL;

	if (root->_left == NULL && root->_right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);

}

// 二叉树第k层节点个数
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

// 二叉树查找值为x的节点
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

// 二叉树前序遍历 
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

// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL");
	}

	BinaryTreeInOrder(root->_left);
	printf("%d", root->_data);
	BinaryTreeInOrder(root->_right);
}

// 二叉树后序遍历
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

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
	{
		QueuePush(&q, root);
	}

	else
	{
		QueueDestroy(&q);
		return ;
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		printf("%d",front->_data);

		if(front->_left)
		QueuePush(&q, front->_left);

		if(front->_right)
		QueuePush(&q, front->_right);
	}

	QueueDestroy(&q);
}

// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root) 
	{
		QueuePush(&q, root);
	}

	else
	{
		QueueDestroy(&q);
		return false;
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (NULL == front)
		{
			break;
		}

		QueuePush(&q, front->_left);
		QueuePush(&q, front->_right);
	}

	while (!(QueueEmpty(&q)))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front)
		{
			QueueDestroy(&q);
			return false;
		}

	}

	QueueDestroy(&q);
	return true;
}


// 有效率问题
//int TreeHeight(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//
//	return TreeHeight(root->left) > TreeHeight(root->right) ?
//		TreeHeight(root->left) + 1 : TreeHeight(root->right) + 1;
//}

//树高
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