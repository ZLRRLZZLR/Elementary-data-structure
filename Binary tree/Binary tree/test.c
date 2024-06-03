#include"Binary_tree.h"

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

BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(6);


	node1->_left = node2;
	node1->_right = node4;
	node2->_left = node3;
	node4->_left = node5;
	node4->_right = node6;
	node5->_right = node7;

	return node1;
}

int main()
{
	BTNode* n = CreatBinaryTree();
	//BinaryTreePrevOrder(n);
	/*BinaryTreeInOrder(n);*/

	/*BinaryTreeDestory(&n);*/

	/*printf("%d\n",BinaryTreeSize(n));*/

	//printf("%d\n", BinaryTreeLeafSize(n));
	//printf("%d\n", BinaryTreeLevelKSize(n, 4));
	//BTNode* find = BinaryTreeFind(n, 10);

	//if(find)
	//{
	//	printf("%d", find->_data);

	//}
	//else
	//{
	//	puts("NULL");
	//}

	//printf("%d\n", TreeHeight(n));

	if(!BinaryTreeComplete(n));
	{
		puts("false");
	}


	return 0;
}