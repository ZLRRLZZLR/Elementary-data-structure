#include"Binary_tree.h"



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

//int main()
//{
//	BTNode* n = CreatBinaryTree();
//	BTDataType* a = { "ABD##E#H##CF##G##" };
//	BTNode* n1 = NULL;
//
//	//BinaryTreePrevOrder(n);
//	//BinaryTreeInOrder(n);
//
//	//BinaryTreeDestory(&n);
//
//	//printf("%d\n",BinaryTreeSize(n));
//
//	printf("%d\n", BinaryTreeLeafSize(n));
//	printf("%d\n", BinaryTreeLevelKSize(n, 4));
//	BTNode* find = BinaryTreeFind(n, 10);
//
//	if(find)
//	{
//		printf("%d\n", find->_data);
//
//	}
//	else
//	{
//		printf("%s\n","NULL");
//	}
//
//	printf("%d\n", TreeHeight(n));
//
//	int ret = BinaryTreeComplete(n);
//	printf("%d\n",ret);
//
//	BinaryTreeLevelOrder(n);
//	int i = 0;
//	BTNode* root = BinaryTreeCreate(a,sizeof(a)/sizeof(a[0]), &i);
//		BinaryTreePrevOrder(n);
//		printf("\n");
//		BinaryTreePrevOrder(root);
//	return 0;
//}
int main()
{
	BTNode* root = CreatBinaryTree();
	PrevOrder(root);
	printf("\n");

	InOrder(root);
	printf("\n");


	int size = 0;
	TreeSize(root, &size);
	printf("TreeSize:%d\n",size);
	TreeSize(root, &size);
	printf("TreeSize:%d\n", size);
	TreeSize(root, &size);
	printf("TreeSize:%d\n", size);

	/*printf("TreeSize:%d\n", TreeSize(root));
	printf("TreeLeafSize:%d\n", TreeLeafSize(root));
	printf("TreeHeight:%d\n", TreeHeight(root));
	printf("TreeLevelKSize:%d\n", TreeLevelKSize(root, 3));
	printf("TreeLevelKSize:%d\n", TreeLevelKSize(root, 4));*/

	return 0;
}