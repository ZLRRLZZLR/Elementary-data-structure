#define _CRT_SECURE_NO_WARNINGS 1

#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<stdio.h>
#include<string.h>

////ţ������ţ� HJ40 ͳ���ַ�
//#include <stdio.h>
//#include<ctype.h>
//
//int main() {
//    char arr[1050];
//    int num = 0;
//    int other = 0;
//    int alpha = 0;
//    int space = 0;
//    gets(arr);
//    int i = 0;
//    while (arr[i] != '\0') {
//        if (isalpha(arr[i])) {
//            alpha++;
//        }
//        else if (isdigit(arr[i])) {
//            num++;
//        }
//        else if (isspace(arr[i])) {
//            space++;
//        }
//        else {
//            other++;
//        }
//        i++;
//    }
//    printf("%d\n", alpha);
//    printf("%d\n", space);
//    printf("%d\n", num);
//    printf("%d\n", other);
//
//    return 0;
//}
//
//#include <stdio.h>
//
//int main() {
//    char arr[8];
//    int num;
//    while (scanf("%d", &num) != EOF) {
//        int count = 0;
//        for (int j = 1; j <= num; j++) {
//            int flag = 1;
//            sprintf(arr, "%d", j);
//            for (int i = 0; arr[i] != '\0'; i++) {
//                if (arr[i] == '7') {
//                    count++;
//                    flag = 0;
//                    break;
//                }
//            }
//            if (flag) {
//                if (j % 7 == 0)
//                    count++;
//            }
//        }
//        printf("%d", count);
//    }
//    return 0;
//}
////������ 08.05.�ݹ�˷�
//int _multiply(int A, int B) {
//    if (!B)
//        return 0;
//
//    return A + _multiply(A, B - 1);
//}
//
//int multiply(int A, int B) {
//    return _multiply(A, B);
//}

////����01.06.�ַ���ѹ��
//char* compressString(char* S) {
//    char flag = *S;
//    int count = 0;
//    char* s = S;
//    static char arr[60000];
//    int i = 0, j = 0;
//    while (s[i] != '\0') {
//        while (s[i] == flag) {
//            count++;
//            i++;
//        }
//        arr[j++] = flag;
//        sprintf(arr + j, "%d", count);
//        j = strlen(arr);
//        flag = s[i];
//        count = 0;
//    }
//    arr[j] = '\0';
//    if (j >= i) {
//        return S;
//    }
//    return arr;
//}

//char* compressString(char* S) {
//    char flag = *S;
//    int count = 0;
//    char* s = S;
//    char arr[5000];
//    int i = 0, j = 0;
//    while (s[i] != '\0') {
//        while (s[i] == flag) {
//            count++;
//            i++;
//        }
//        arr[j++] = flag;
//        arr[j++] = count + '0';
//        flag = s[i];
//        count = 0;
//    }
//    arr[j] = '\0';
//    if (j >= i) {
//        return S;
//    }
//    return arr;
//}
//
//int main() {
//    char* S = "aabcccccaa";
//    compressString(S);
//
//    return 0;
//}

///**LCP.��Ļʽ�̻�
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//void _numColor(struct TreeNode* root, int* tmp) {
//    if (NULL == root) {
//        return;
//    }
//    tmp[root->val]++;
//    _numColor(root->left, tmp);
//    _numColor(root->right, tmp);
//}
//int numColor(struct TreeNode* root) {
//    int* tmp = (int*)calloc(2000, sizeof(int));
//    _numColor(root, tmp);
//    int count = 0;
//    for (int i = 0; i < 2000; i++) {
//        if (tmp[i] != 0) {
//            count++;
//        }
//    }
//    return count;
//}
//1122. ������������
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
//    int min = arr1[0];
//    int max = arr1[0];
//
//    for (int i = 0; i < arr1Size; i++) {
//        if (arr1[i] > max) {
//            max = arr1[i];
//        }
//        if (arr1[i] < min) {
//            min = arr1[i];
//        }
//    }
//    int* tmp = (int*)calloc(max - min + 1, sizeof(int));
//    if (NULL == tmp) {
//        perror("calloc");
//        exit(1);
//    }
//    for (int i = 0; i < arr1Size; i++) {
//        tmp[arr1[i] - min]++;
//    }
//    int j = 0;
//    for (int i = 0; i < arr2Size; ) {
//        if (tmp[arr2[i] - min]) {
//            while (tmp[arr2[i] - min]--) {
//                arr1[j++] = arr2[i];
//            }
//        }
//        i++;
//    }
//
//    for (int i = 0; i < max - min + 1; i++) {
//        while (tmp[i] > 0) {
//            arr1[j++] = i + min;
//            tmp[i]--;
//        }
//    }
//    *returnSize = arr1Size;
//    return arr1;
//
//}
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size) {
//    int min = arr1[0];
//    int max = arr1[0];
//
//    for (int i = 0; i < arr1Size; i++) {
//        if (arr1[i] > max) {
//            max = arr1[i];
//        }
//        if (arr1[i] < min) {
//            min = arr1[i];
//        }
//    }
//    int* tmp = (int*)calloc(max - min + 1, sizeof(int));
//    if (NULL == tmp) {
//        perror("calloc");
//        exit(1);
//    }
//    for (int i = 0; i < arr1Size; i++) {
//        tmp[arr1[i] - min]++;
//    }
//    int j = 0;
//    for (int i = 0; i < arr2Size; ) {
//        if (tmp[arr2[i] - min]) {
//            while (tmp[arr2[i] - min]--) {
//                arr1[j++] = arr2[i];
//            }
//        }
//        i++;
//        }
//
//    for (int i = 0; i < max - min + 1; i++) {
//        while (tmp[i] > 0) {
//            arr1[j++] = i + min;
//            tmp[i]--;
//        }
//    }
//    return arr1;
//
//}

///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//void Sort(int* arr, int numsSize) {
//    for (int i = 0; i < numsSize - 1; i++) {
//        int end = i;
//        int tmp = arr[end + 1];
//        while (end >= 0) {
//            if (arr[end] > tmp) {
//                arr[end + 1] = arr[end];
//                end--;
//            }
//            else {
//                break;
//            }
//        }
//        arr[end + 1] = tmp;
//    }
//}
//
//bool Find(int* arr, int left, int right, int find) {
//    int begin = left;
//    int end = right;
//    while (begin <= end) {
//        int mid = (begin + end) / 2;
//        if (find > arr[mid]) {
//            begin = mid + 1;
//        }
//        else if (find < arr[mid]) {
//            end = mid - 1;
//        }
//        else {
//            return true;
//        }
//    }
//    return false;
//}
//int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size) {
//    int* tmp1 = (int*)malloc(sizeof(int) * arr1Size);
//    if (NULL == tmp1) {
//        perror("malloc");
//        exit(1);
//    }
//    int* tmp2 = (int*)malloc(sizeof(int) * arr1Size);
//    if (NULL == tmp2) {
//        perror("malloc");
//        exit(1);
//    }
//    Sort(arr1, arr1Size);
//    int i = arr1Size;
//    int j = 0;
//    int k = 0;
//    while (i--) {
//        if ((arr2, 0, arr2Size - 1, arr1[i])) {
//            tmp1[j++] = arr1[i];
//        }
//        else {
//            tmp2[k++] = arr1[i];
//        }
//    }
//    Sort(tmp2, k);
//    memcpy(arr1, tmp1, j * sizeof(int));
//    memcpy(arr1 + j, tmp2, k * sizeof(int));
//    
//    return arr1;
//}
//
//
//int main() {
//    int arr1[] = { 2,3,1,3,2,4,6,7,9,2,19 };
//    int arr2[] = { 2,1,4,3,9,6};
//    relativeSortArray(arr1,sizeof(arr1) / sizeof(int),arr2,sizeof(arr2) / sizeof(int));
//
//    return 0;
//}
////35. ��������λ��
//int searchInsert(int* nums, int numsSize, int target) {
//    int begin = 0;
//    int end = numsSize - 1;
//    while (begin >= end && begin < numsSize && end >= 0) {
//        int mid = (begin + end) / 2;
//        if (nums[mid] == target)
//            return mid;
//        else
//            end = mid - 1;
//    }
//    int i = 0;
//    for (; i < numsSize; i++) {
//        if (nums[i] >= target)
//            break;
//    }
//    return i;
//}

//HJ7 ȡ����ֵ
//#include <stdio.h>
//
//int main() {
//    float num;
//    while (scanf("%f", &num) != EOF) {
//        int a = num * 10;
//        a = a % 10;
//        if (a >= 5)
//            printf("%d", (int)(num + 1));
//        else
//            printf("%d", (int)num);
//    }
//    return 0;
//}
//#include <stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//struct ListNode {
//    int val;
//    struct ListNode* next;
//};
// 
//struct ListNode* Mid(struct ListNode* A) {
//    struct ListNode* slow = A;
//    struct ListNode* fast = A;
//
//    while (fast && fast->next) {
//
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//
//    return slow;
//}
//struct ListNode* Reverse(struct ListNode* A) {
//    struct ListNode* l1 = NULL;
//    struct ListNode* l2 = A;
//    struct ListNode* l3 = A->next;
//    while (l1->next) {
//        l2->next = l1;
//        l1 = l2;
//        l2 = l3;
//        if (l2)
//            l3 = l2->next;
//    }
//
//    return l1;
//}
//
//bool chkPalindrome(struct ListNode* A) {
//    struct ListNode* mid = Mid(A);
//    struct ListNode* newhead = Reverse(mid);
//    struct ListNode* head = A;
//
//    while (head->next || newhead->next) {
//
//        if (newhead != head)
//            return false;
//
//        head = head->next;
//        newhead = newhead->next;
//
//    }
//
//    return true;
//
//}

//void _Merge(int* a, int* tmp, int left, int right) {
//    if (left >= right)
//        return;
//
//    int mid = (left + right) / 2;
//
//    _Merge(a, tmp, 0, mid);
//    _Merge(a, tmp, mid + 1, right);
//
//    int begin1 = left, end1 = mid;
//    int begin2 = mid + 1, end2 = right;
//
//    int j = left;
//
//    while (begin1 <= end1 && begin2 <= end2) {
//        if (a[begin1] <= a[begin2])
//            tmp[j++] = a[begin1++];
//
//        if (a[begin2] <= a[begin1])
//            tmp[j++] = a[begin2++];
//    }
//
//    while (begin1 <= end1) {
//        tmp[j++] = a[begin1++];
//    }
//    while (begin2 <= end2) {
//        tmp[j++] = a[begin2++];
//    }
//
//    memcpy(a + left, tmp + left, (right - left + 1) * sizeof(int));
//
//}
//void Merge(int* a, int n) {
//    int* tmp = (int*)malloc(sizeof(int) * n);
//    if (tmp == NULL) {
//        perror("malloc");
//        exit(1);
//    }
//
//    _Merge(a, tmp, 0, n - 1);
//
//    free(tmp);
//    tmp = NULL;
//}
//
//
//int main() {
//    int arr[6] = { 1,4 ,2 ,7 ,5 ,2 };
//    Merge(arr, 5);
//
//    return 0;
//}

//#include<stdio.h>
//#include<assert.h>
//#include<stdlib.h>
//
//
//typedef char BTDataType;
//
//typedef struct BinaryTreeNode
//{
//	BTDataType _data;
//	struct BinaryTreeNode* _left;
//	struct BinaryTreeNode* _right;
//}BTNode;
//
//BTNode* BuyNode(int x) {
//	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
//	node->_data = x;
//	node->_left = NULL;
//	node->_right = NULL;
//
//	return node;
//}
//
//BTNode* CreateTree(BTNode* root, char* arr, int* pi) {
//	if (arr[(*pi)] == '#') {
//		(*pi)++;
//		return NULL;
//	}
//	root = BuyNode(arr[(*pi)++]);
//	root->_left = CreateTree(root->_left, arr, pi);
//	root->_right = CreateTree(root->_right, arr, pi);
//	return root;
//}
//
//// �������������
//void BinaryTreeInOrder(BTNode* root) {
//	if (NULL == root)
//		return;
//	BinaryTreeInOrder(root->_left);
//	printf("%c ", root->_data);
//	BinaryTreeInOrder(root->_right);
//}
//int main() {
//	char arr[100];
//	scanf("%s", arr);
//	int i = 0;
//	BTNode* root = NULL;
//	root = CreateTree(root, arr, &i);
//	BinaryTreeInOrder(root);
//	return 0;
//}

//#include<stdio.h>
//#include<assert.h>
//#include<stdlib.h>
//
//
//#include<stdio.h>
//#include<assert.h>
//#include<stdlib.h>
//
//
//typedef char BTDataType;
//
//typedef struct BinaryTreeNode
//{
//	BTDataType _data;
//	struct BinaryTreeNode* _left;
//	struct BinaryTreeNode* _right;
//}BTNode;
//
//BTNode* BuyNode(int x) {
//	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
//	node->_data = x;
//	node->_left = NULL;
//	node->_right = NULL;
//
//	return node;
//}
//
//BTNode* CreateTree(BTNode* root, char* arr, int* pi) {
//	while (arr[(*pi)] == '#') {
//		(*pi)++;
//	}
//	root = BuyNode(arr[(*pi)++]);
//	root->_left = CreateTree(root->_left, arr, pi);
//	root->_right = CreateTree(root->_right, arr, pi);
//	return root;
//}
//
//// �������������
//void BinaryTreeInOrder(BTNode* root) {
//	if (NULL == root) {
//		printf(" ");
//		return;
//	}
//	BinaryTreeInOrder(root->_left);
//	printf("%c", root->_data);
//	BinaryTreeInOrder(root->_right);
//}
//int main() {
//	char arr[100];
//	scanf("%s", arr);
//	int i = 0;
//	BTNode* root = NULL;
//	root = CreateTree(root, arr, &i);
//	BinaryTreeInOrder(root);
//	return 0;
//}
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int maxDepth(struct TreeNode* root) {
//    if (NULL == root)
//        return 0;
//
//    int left = maxDepth(root->left);
//    int right = maxDepth(root->right);
//
//    return left > right ? left + 1 : right + 1;
//}
//
//bool isBalanced(struct TreeNode* root) {
//    if (NULL == root)
//        return true;
//    int left = maxDepth(root->left);
//    int right = maxDepth(root->right);
//    if (abs(left - right) > 1)
//        return false;
//
//    return isBalanced(root->left) && isBalanced(root->right);
//}
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//void _invertTree(struct TreeNode* root) {
//    if (NULL == root)
//        return;
//    _invertTree(root->left);
//    _invertTree(root->right);
//    struct TreeNode* node = root->left;
//    root->left = root->right;
//    root->right = node;
//}
//
//struct TreeNode* invertTree(struct TreeNode* root) {
//    _invertTree(root);
//    return root;
//}
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
//int BinaryTreeSize(struct TreeNode* root) {
//    if (NULL == root)
//        return 0;
//
//    return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
//}
//void PreOrder(struct TreeNode* root, int* arr, int* pi) {
//    if (NULL == root)
//        return;
//    arr[(*pi)++] = root->val;
//
//    PreOrder(root->left, arr, pi);
//    PreOrder(root->right, arr, pi);
//
//}
//
//int* preorderTraversal(struct TreeNode* root, int* returnSize) {
//    *returnSize = BinaryTreeSize(root);
//    int* arr = (int*)malloc(sizeof(int) * (*returnSize));
//    int i = 0;
//    PreOrder(root, arr, &i);
//
//    return arr;
//}
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//    if (p == NULL && q == NULL)
//        return true;
//
//    if (p == NULL || q == NULL)
//        return false;
//
//    if (p->val != q->val)
//        return false;
//
//    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//
//}
//
//bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
//    if (NULL == root)
//        return false;
//    if (root->val == subRoot->val && isSameTree(root, subRoot))
//        return true;
//
//    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
//}
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool _isSymmetric(struct TreeNode* q, struct TreeNode* p) {
//    if (NULL == q && NULL == p)
//        return true;
//
//    if (NULL == q || NULL == p)
//        return false;
//
//    if (p->val != q->val)
//        return false;
//
//    return _isSymmetric(p->left, q->right) && _isSymmetric(p->right, q->left);
//
//}
//
//bool isSymmetric(struct TreeNode* root) {
//    if (NULL == root)
//        return true;
//
//    return _isSymmetric(root->left, root->right);
//}

///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool isUnivalTree(struct TreeNode* root) {
//    if (NULL == root)
//        return true;
//
//    if (root->left)
//        if (root->left->val != root->val)
//            return false;
//
//    if (root->right)
//        if (root->right->val != root->val)
//            return false;
//
//    return isUnivalTree(root->left) && isUnivalTree(root->right);
//}

///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//int maxDepth(struct TreeNode* root) {
//    if (NULL == root)
//        return 0;
//
//    int left = maxDepth(root->left);
//    int right = maxDepth(root->right);
//
//    return left > right ? left + 1 : right + 1;
//}
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//    if (p == NULL && q == NULL)
//        return true;
//
//    if (p == NULL || q == NULL)
//        return false;
//
//    if (p->val != q->val)
//        return false;
//
//    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//
//
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <assert.h>
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//void Swap(int* p1, int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//void AdjustDown(int* a, int n, int parent)
//{
//	int child = parent * 2 + 1;
//	while (child < n)
//	{
//		// ѡ�����Һ����д����һ��
//		if (child + 1 < n && a[child + 1] > a[child])
//		{
//			++child;
//		}
//		if (a[child] > a[parent])
//		{
//			Swap(&a[child], &a[parent]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//void HeapSort(int* a, int n)
//{
//	// ���� -- ���µ������� -- O(N)
//	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
//	{
//		AdjustDown(a, n, i);
//	}
//	// O(N*logN)
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[end], &a[0]);
//		AdjustDown(a, end, 0);
//		--end;
//	}
//}
//// file1�ļ������ݺ�file2�ļ������ݹ鲢��mfile�ļ���
//void MergeFile(const char* file1, const char* file2, const char* mfile)
//{
//	FILE* fout1 = fopen(file1, "r");
//	if (fout1 == NULL)
//	{
//		printf("���ļ�ʧ��\n");
//		exit(-1);
//	}
//	FILE* fout2 = fopen(file2, "r");
//	if (fout2 == NULL)
//	{
//		printf("���ļ�ʧ��\n");
//		exit(-1);
//	}
//	FILE* fin = fopen(mfile, "w");
//	if (fin == NULL)
//	{
//		printf("���ļ�ʧ��\n");
//		exit(-1);
//	}
//	// ������ڴ�������鲢��˼����ȫ���ƣ�ֻ��������Ӳ���ļ��ж���
//	// ���ζ�ȡfile1��file2�����ݣ�˭������С��˭����mfile�ļ���ȥд
//	// file1��file2����һ���ļ��������ٰ���һ���ļ�δ�����ļ����ݣ�
//	// ����д��mfile�ĺ���
//	int num1, num2;
//	int ret1 = fscanf(fout1, "%d\n", &num1);
//	int ret2 = fscanf(fout2, "%d\n", &num2);
//	while (ret1 != EOF && ret2 != EOF)
//	{
//		if (num1 < num2)
//		{
//			fprintf(fin, "%d\n", num1);
//			ret1 = fscanf(fout1, "%d\n", &num1);
//		}
//		else
//		{
//			fprintf(fin, "%d\n", num2);
//			ret2 = fscanf(fout2, "%d\n", &num2);
//		}
//	}
//	while (ret1 != EOF)
//	{
//		fprintf(fin, "%d\n", num1);
//		ret1 = fscanf(fout1, "%d\n", &num1);
//	}
//	while (ret2 != EOF)
//	{
//		fprintf(fin, "%d\n", num2);
//		ret2 = fscanf(fout2, "%d\n", &num2);
//	}
//	fclose(fout1);
//	fclose(fout2);
//	fclose(fin);
//}
//// ���ض�ȡ�������ݸ���
//int ReadNNumSortToFile(FILE* fout, int* a, int n, const char* file)
//{
//	int x = 0;
//	// ��ȡn�����ݷŵ�file
//	int i = 0;
//	while (i < n && fscanf(fout, "%d", &x) != EOF)
//	{
//		a[i++] = x;
//	}
//	// һ�����ݶ�û�ж�������˵���ļ��Ѿ�������β��
//	if (i == 0)
//		return i;
//	// ����
//	HeapSort(a, i);
//	FILE* fin = fopen(file, "w");
//	if (fout == NULL)
//	{
//		printf("���ļ�%sʧ��\n", file);
//		exit(-1);
//	}
//	for (int j = 0; j < i; j++)
//	{
//		fprintf(fin, "%d\n", a[j]);
//	}
//	fclose(fin);
//	return i;
//}
//// MergeSortFile�ĵڶ�����ÿ��ȡ���ٸ����ݵ��ڴ�������Ȼ��д��һ��С�ļ����й鲢
//// ���n������ȡ���������ж��ٺ�����ڴ�������ã���Զ���nԽ�󣬸������ݵ��ڴ��������
//// �����ļ��鲢������������Խ��һЩ��
//void MergeSortFile(const char* file, int n)
//{
//	FILE* fout = fopen(file, "r");
//	if (fout == NULL)
//	{
//		printf("���ļ�%sʧ��\n", file);
//		exit(-1);
//	}
//	int i = 0;
//	int x = 0;
//	const char* file1 = "file1";
//	const char* file2 = "file2";
//	const char* mfile = "mfile";
//	// �ָ��һ��һ�����ݣ��ڴ������д����С�ļ���
//	int* a = (int*)malloc(sizeof(int) * n);
//	if (a == NULL)
//	{
//		perror("malloc fail");
//		return;
//	}
//	// �ֱ��ȡǰn�����������д��file1��file2�ļ�
//	ReadNNumSortToFile(fout, a, n, file1);
//	ReadNNumSortToFile(fout, a, n, file2);
//	while (1)
//	{
//		// file1��file2�ļ��鲢��mfile�ļ���
//		MergeFile(file1, file2, mfile);
//		// ɾ��file1��file2
//		if (remove(file1) != 0 || remove(file2) != 0)
//		{
//			perror("Error deleting file");
//			return;
//		}
//		// ��mfile������Ϊfile1
//		if (rename(mfile, file1) != 0)
//		{
//			perror("Error renaming file");
//			return;
//		}
//		// ��ȡN�����ݵ�file2�������߹鲢
//		// ���һ�����ݶ�û��������鲢������
//		if (ReadNNumSortToFile(fout, a, n, file2) == 0)
//		{
//			break;
//		}
//	}
//	printf("%s�ļ��ɹ�����%s\n", file, file1);
//	fclose(fout);
//	free(a);
//}
//// ����N���������д���ļ���
//void CreateNDate()
//{
//	// ������
//	int n = 1000000;
//	srand(time(0));
//	const char* file = "data.txt";
//	FILE* fin = fopen(file, "w");
//	if (fin == NULL)
//	{
//		perror("fopen error");
//		return;
//	}
//	for (int i = 0; i < n; ++i)
//	{
//		int x = rand() + i;
//		fprintf(fin, "%d\n", x);
//	}
//	fclose(fin);
//}
//int main()
//{
//	//CreateNDate();
//	MergeSortFile("data.txt", 100000);
//	return 0;
//}
//// ����N���������д���ļ���
//void CreateNDate()
//{
//	// ������
//	int n = 1000000;
//	srand(time(0));
//	const char* file = "data.txt";
//	FILE* fin = fopen(file, "w");
//	if (fin == NULL)
//	{
//		perror("fopen error");
//		return;
//	}
//	for (int i = 0; i < n; ++i)
//	{
//		int x = rand() + i;
//		fprintf(fin, "%d\n", x);
//	}
//	fclose(fin);
//}
///**
//* Note: The returned array must be malloced, assume caller calls free().
//*/
//void Swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//void AdjustDown(int* a, int n, int parent)
//{
//	int child = parent * 2 + 1;
//	while (child < n)
//	{
//		// ѡ�����Һ����д����һ��
//		if (child + 1 < n && a[child + 1] > a[child])
//		{
//			++child;
//		}
//		if (a[child] > a[parent])
//		{
//			Swap(&a[child], &a[parent]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//void HeapSort(int* a, int n)
//{
//	// ���� -- ���µ������� -- O(N)
//	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
//	{
//		AdjustDown(a, n, i);
//	}
//	// �Լ���ʵ�� -- O(N*logN)
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[end], &a[0]);
//		AdjustDown(a, end, 0);
//		--end;
//	}
//}
//void InsertSort(int* a, int n)
//{
//	for (int i = 1; i < n; i++)
//	{
//		int end = i - 1;
//		int tmp = a[i];
//		// ��tmp���뵽[0,end]�����У���������
//		while (end >= 0)
//		{
//			if (tmp < a[end])
//			{
//				a[end + 1] = a[end];
//				--end;
//			}
//			else
//			{
//				break;
//			}
//		}
//		a[end + 1] = tmp;
//	}
//}
//void IntroSort(int* a, int left, int right, int depth, int defaultDepth)
//{
//	if (left >= right)
//		return;
//	// ���鳤��С��16��С���飬��Ϊ�������򣬼򵥵ݹ����
//	if (right - left + 1 < 16)
//	{
//		InsertSort(a + left, right - left + 1);
//		return;
//	}
//	// ����ȳ���2*logNʱ���ö�����
//	if (depth > defaultDepth)
//	{
//		HeapSort(a + left, right - left + 1);
//		return;
//	}
//	depth++;
//	int begin = left;
//	int end = right;
//	// ���ѡkey
//	int randi = left + (rand() % (right - left));
//	Swap(&a[left], &a[randi]);
//	int prev = left;
//	int cur = prev + 1;
//	int keyi = left;
//	while (cur <= right)
//	{
//		if (a[cur] < a[keyi] && ++prev != cur)
//		{
//			Swap(&a[prev], &a[cur]);
//		}
//		++cur;
//	}
//	Swap(&a[prev], &a[keyi]);
//	keyi = prev;
//	// [begin, keyi-1] keyi [keyi+1, end]
//	IntroSort(a, begin, keyi - 1, depth, defaultDepth);
//	IntroSort(a, keyi + 1, end, depth, defaultDepth);
//}
//void QuickSort(int* a, int left, int right)
//{
//	int depth = 0;
//	int logn = 0;
//	int N = right - left + 1;
//	for (int i = 1; i < N; i *= 2)
//	{
//		logn++;
//	}
//	// introspective sort -- ��ʡ����
//	IntroSort(a, left, right, depth, logn * 2);
//}
//int* sortArray(int* nums, int numsSize, int* returnSize) {
//	srand(time(0));
//	QuickSort(nums, 0, numsSize - 1);
//	*returnSize = numsSize;
//	return nums;
//}

//void Swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//void QuickSort(int* a, int left, int right)
//{
//	if (left >= right)
//		return;
//	int begin = left;
//	int end = right;
//	// ���ѡkey
//	int randi = left + (rand() % (right - left));
//	Swap(&a[left], &a[randi]);
//	// ��·����
//	// left��rightָ����Ǹ�key��ȵ�����
//// [begin, left-1] [left, right] right+1, end]
//	int key = a[left];
//	int cur = left + 1;
//	while (cur <= right)
//	{
//		// 1��cur������keyС��С�Ļ�����ߣ�ͬʱ��key�����м�λ��
//		// 2��cur������key�󣬴�Ļ����ұ�
//		if (a[cur] < key)
//		{
//			Swap(&a[cur], &a[left]);
//			++left;
//			++cur;
//		}
//		else if (a[cur] > key)
//		{
//			Swap(&a[cur], &a[right]);
//			--right;
//		}
//		else
//		{
//			++cur;
//		}
//	}
//	// [begin, left-1] [left, right] right+1, end]
//	QuickSort(a, begin, left - 1);
//	QuickSort(a, right + 1, end);
//}
//int* sortArray(int* nums, int numsSize, int* returnSize) {
//	srand(time(0));
//	QuickSort(nums, 0, numsSize - 1);
//	*returnSize = numsSize;
//	return nums;
//}
//
//void Swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//void QuickSort(int* a, int left, int right)
//{
//	if (left >= right)
//		return;
//	int begin = left;
//	int end = right;
//	// ���ѡkey
//	int randi = left + (rand() % (right - left));
//	// printf("%d\n", randi);
//	Swap(&a[left], &a[randi]);
//	int prev = left;
//	int cur = prev + 1;
//	int keyi = left;
//	while (cur <= right)
//	{
//		if (a[cur] < a[keyi] && ++prev != cur)
//		{
//			Swap(&a[prev], &a[cur]);
//		}
//		++cur;
//	}
//	Swap(&a[prev], &a[keyi]);
//	keyi = prev;
//	// [begin, keyi-1] keyi [keyi+1, end]
//	QuickSort(a, begin, keyi - 1);
//	QuickSort(a, keyi + 1, end);
//}
//int* sortArray(int* nums, int numsSize, int* returnSize) {
//	srand(time(0));
//	QuickSort(nums, 0, numsSize - 1);
//	*returnSize = numsSize;
//	return nums;
//}
//// ��·����
//KeyWayIndex PartSort3Way(int* a, int left, int right)
//{
//	int key = a[left];
//	// left��rightָ����Ǹ�key��ȵ�����
//	// [��ʼ, left-1][left, right][right+1, ����]
//	int cur = left + 1;
//	while (cur <= right)
//	{
//		// 1��cur������keyС��С�Ļ�����ߣ�ͬʱ��key�����м�λ��
//		// 2��cur������key�󣬴�Ļ����ұ�
//		if (a[cur] < key)
//		{
//			Swap(&a[cur], &a[left]);
//			++cur;
//			++left;
//		}
//		else if (a[cur] > key)
//		{
//			Swap(&a[cur], &a[right]);
//			--right;
//		}
//		else
//		{
//			++cur;
//		}
//	}
//	KeyWayIndex kwi;
//	kwi.leftKeyi = left;
//	kwi.rightKeyi = right;
//	return kwi;
//}
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#include<string.h>
//void PrintArray(int* a, int n)
//{
//	for (int i = 0; i < n; ++i)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//}
//void Swap(int* p1, int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//// hoare
//// [left, right]
//int PartSort1(int* a, int left, int right)
//{
//	int keyi = left;
//	while (left < right)
//	{
//		// �ұ���С
//		while (left < right && a[right] >= a[keyi])
//		{
//			--right;
//		}
//		// ����Ҵ�
//		while (left < right && a[left] <= a[keyi])
//		{
//			++left;
//		}
//		Swap(&a[left], &a[right]);
//	}
//	Swap(&a[keyi], &a[left]);
//	return left;
//}
/// ǰ��ָ��
//int PartSort2(int* a, int left, int right)
//{
//	int prev = left;
//	int cur = left + 1;
//	int keyi = left;
//	while (cur <= right)
//	{
//		if (a[cur] < a[keyi] && ++prev != cur)
//		{
//			Swap(&a[prev], &a[cur]);
//		}
//		++cur;
//	}
//	Swap(&a[prev], &a[keyi]);
//	keyi = prev;
//	return keyi;
//}
//typedef struct
//{
//	int leftKeyi;
//	int rightKeyi;
//}KeyWayIndex;
//// ��·����
//KeyWayIndex PartSort3Way(int* a, int left, int right)
//{
//	int key = a[left];
//	// left��rightָ����Ǹ�key��ȵ�����
//	// [��ʼ, left-1][left, right][right+1, ����]
//	int cur = left + 1;
//	while (cur <= right)
//	{
//		// 1��cur������keyС��С�Ļ�����ߣ�ͬʱ��key�����м�λ��
//		// 2��cur������key�󣬴�Ļ����ұ�
//		if (a[cur] < key)
//		{
//			Swap(&a[cur], &a[left]);
//			++cur;
//			++left;
//		}
//		else if (a[cur] > key)
//		{
//			Swap(&a[cur], &a[right]);
//			--right;
//		}
//		else
//		{
//			++cur;
//		}
//	}
//	KeyWayIndex kwi;
//	kwi.leftKeyi = left;
//	kwi.rightKeyi = right;
//	return kwi;
//}
//void TestPartSort1()
//{
//	int a1[] = { 6,1,7,6,6,6,4,9 };
//	int a2[] = { 3,2,3,3,3,3,2,3 };
//	int a3[] = { 2,2,2,2,2,2,2,2 };
//	PrintArray(a1, sizeof(a1) / sizeof(int));
//	int keyi1 = PartSort1(a1, 0, sizeof(a1) / sizeof(int) - 1);
//	PrintArray(a1, sizeof(a1) / sizeof(int));
//	printf("hoare keyi:%d\n\n", keyi1);
//	PrintArray(a2, sizeof(a2) / sizeof(int));
//	int keyi2 = PartSort1(a2, 0, sizeof(a2) / sizeof(int) - 1);
//	PrintArray(a2, sizeof(a2) / sizeof(int));
//	printf("hoare keyi:%d\n\n", keyi2);
//	PrintArray(a3, sizeof(a3) / sizeof(int));
//	int keyi3 = PartSort1(a3, 0, sizeof(a3) / sizeof(int) - 1);
//	PrintArray(a3, sizeof(a3) / sizeof(int));
//	printf("hoare keyi:%d\n\n", keyi3);
//}
//void TestPartSort2()
//{
//	int a1[] = { 6,1,7,6,6,6,4,9 };
//	int a2[] = { 3,2,3,3,3,3,2,3 };
//	int a3[] = { 2,2,2,2,2,2,2,2 };
//	PrintArray(a1, sizeof(a1) / sizeof(int));
//	int keyi1 = PartSort2(a1, 0, sizeof(a1) / sizeof(int) - 1);
//	PrintArray(a1, sizeof(a1) / sizeof(int));
//	printf("ǰ��ָ�� keyi:%d\n\n", keyi1);
//	PrintArray(a2, sizeof(a2) / sizeof(int));
//	int keyi2 = PartSort2(a2, 0, sizeof(a2) / sizeof(int) - 1);
//	PrintArray(a2, sizeof(a2) / sizeof(int));
//	printf("ǰ��ָ�� keyi:%d\n\n", keyi2);
//	PrintArray(a3, sizeof(a3) / sizeof(int));
//	int keyi3 = PartSort2(a3, 0, sizeof(a3) / sizeof(int) - 1);
//	PrintArray(a3, sizeof(a3) / sizeof(int));
//	printf("ǰ��ָ�� keyi:%d\n\n", keyi3);
//}
//void TestPartSort3()
//{
//	//int a0[] = { 6,1,2,7,9,3,4,5,10,4 };
//	int a1[] = { 6,1,7,6,6,6,4,9 };
//	int a2[] = { 3,2,3,3,3,3,2,3 };
//	int a3[] = { 2,2,2,2,2,2,2,2 };
//	PrintArray(a1, sizeof(a1) / sizeof(int));
//	KeyWayIndex kwi1 = PartSort3Way(a1, 0, sizeof(a1) / sizeof(int) - 1);
//	PrintArray(a1, sizeof(a1) / sizeof(int));
//	printf("3Way keyi:%d,%d\n\n", kwi1.leftKeyi, kwi1.rightKeyi);
//	PrintArray(a2, sizeof(a2) / sizeof(int));
//	KeyWayIndex kwi2 = PartSort3Way(a2, 0, sizeof(a2) / sizeof(int) - 1);
//	PrintArray(a2, sizeof(a2) / sizeof(int));
//	printf("3Way keyi:%d,%d\n\n", kwi2.leftKeyi, kwi2.rightKeyi);
//	PrintArray(a3, sizeof(a3) / sizeof(int));
//	KeyWayIndex kwi3 = PartSort3Way(a3, 0, sizeof(a3) / sizeof(int) - 1);
//	PrintArray(a3, sizeof(a3) / sizeof(int));
//	printf("3Way keyi:%d,%d\n\n", kwi3.leftKeyi, kwi3.rightKeyi);
//}
//int main()
//{
//	TestPartSort1();
//	TestPartSort2();
//	TestPartSort3();
//	return 0;
//}

//// ��·����
//KeyWayIndex PartSort3Way(int* a, int left, int right)
//{
//	int key = a[left];
//	// left��rightָ����Ǹ�key��ȵ�����
//	// [��ʼ, left-1][left, right][right+1, ����]
//	int cur = left + 1;
//	while (cur <= right)
//	{
//		// 1��cur����?key?��?�Ļ�����ߣ�ͬʱ��key�����м�λ��
//		// 2��cur����?key?��?�Ļ����ұ�
//		if (a[cur] < key)
//		{
//			Swap(&a[cur], &a[left]);
//			++cur;
//			++left;
//		}
//		else if (a[cur] > key)
//		{
//			Swap(&a[cur], &a[right]);
//			--right;
//		}
//		else
//		{
//			++cur;
//		}
//	}
//	KeyWayIndex kwi;
//	kwi.leftKeyi = left;
//	kwi.rightKeyi = right;
//	return kwi;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#include<string.h>
//void PrintArray(int* a, int n)
//{
//	for (int i = 0; i < n; ++i)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//}
//void Swap(int* p1, int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//// hoare
//// [left, right]
//int PartSort1(int* a, int left, int right)
//{
//	int keyi = left;
//	while (left < right)
//	{
//		// �ұ���С
//		while (left < right && a[right] >= a[keyi])
//		{
//			--right;
//		}
//		// ����Ҵ�
//		while (left < right && a[left] <= a[keyi])
//		{
//			++left;
//		}
//		Swap(&a[left], &a[right]);
//	}
//	Swap(&a[keyi], &a[left]);
//	return left;
//}
//// ǰ��ָ��
//int PartSort2(int* a, int left, int right)
//{
//	int prev = left;
//	int cur = left + 1;
//	int keyi = left;
//	while (cur <= right)
//	{
//		if (a[cur] < a[keyi] && ++prev != cur)
//		{
//			Swap(&a[prev], &a[cur]);
//		}
//		++cur;
//	}
//	Swap(&a[prev], &a[keyi]);
//	keyi = prev;
//	return keyi;
//}
//typedef struct
//{
//	int leftKeyi;
//	int rightKeyi;
//}KeyWayIndex;
//// ��·����
//KeyWayIndex PartSort3Way(int* a, int left, int right)
//{
//	int key = a[left];
//	// left��rightָ����Ǹ�key��ȵ�����
//	// [��ʼ, left-1][left, right][right+1, ����]
//	int cur = left + 1;
//	while (cur <= right)
//	{
//		// 1��cur������keyС��С�Ļ�����ߣ�ͬʱ��key�����м�λ��
//		// 2��cur������key�󣬴�Ļ����ұ�
//		if (a[cur] < key)
//		{
//			Swap(&a[cur], &a[left]);
//			++cur;
//			++left;
//		}
//		else if (a[cur] > key)
//		{
//			Swap(&a[cur], &a[right]);
//			--right;
//		}
//		else
//		{
//			++cur;
//		}
//	}
//	KeyWayIndex kwi;
//	kwi.leftKeyi = left;
//	kwi.rightKeyi = right;
//	return kwi;
//}
//void TestPartSort1()
//{
//	int a1[] = { 6,1,7,6,6,6,4,9 };
//	int a2[] = { 3,2,3,3,3,3,2,3 };
//	int a3[] = { 2,2,2,2,2,2,2,2 };
//	PrintArray(a1, sizeof(a1) / sizeof(int));
//	int keyi1 = PartSort1(a1, 0, sizeof(a1) / sizeof(int) - 1);
//	PrintArray(a1, sizeof(a1) / sizeof(int));
//	printf("hoare keyi:%d\n\n", keyi1);
//	PrintArray(a2, sizeof(a2) / sizeof(int));
//	int keyi2 = PartSort1(a2, 0, sizeof(a2) / sizeof(int) - 1);
//	PrintArray(a2, sizeof(a2) / sizeof(int));
//	printf("hoare keyi:%d\n\n", keyi2);
//	PrintArray(a3, sizeof(a3) / sizeof(int));
//	int keyi3 = PartSort1(a3, 0, sizeof(a3) / sizeof(int) - 1);
//	PrintArray(a3, sizeof(a3) / sizeof(int));
//	printf("hoare keyi:%d\n\n", keyi3);
//}
//void TestPartSort2()
//{
//	int a1[] = { 6,1,7,6,6,6,4,9 };
//	int a2[] = { 3,2,3,3,3,3,2,3 };
//	int a3[] = { 2,2,2,2,2,2,2,2 };
//	PrintArray(a1, sizeof(a1) / sizeof(int));
//	int keyi1 = PartSort2(a1, 0, sizeof(a1) / sizeof(int) - 1);
//	PrintArray(a1, sizeof(a1) / sizeof(int));
//	printf("ǰ��ָ�� keyi:%d\n\n", keyi1);
//	PrintArray(a2, sizeof(a2) / sizeof(int));
//	int keyi2 = PartSort2(a2, 0, sizeof(a2) / sizeof(int) - 1);
//	PrintArray(a2, sizeof(a2) / sizeof(int));
//	printf("ǰ��ָ�� keyi:%d\n\n", keyi2);
//	PrintArray(a3, sizeof(a3) / sizeof(int));
//	int keyi3 = PartSort2(a3, 0, sizeof(a3) / sizeof(int) - 1);
//	PrintArray(a3, sizeof(a3) / sizeof(int));
//	printf("ǰ��ָ�� keyi:%d\n\n", keyi3);
//}
//void TestPartSort3()
//{
//	//int a0[] = { 6,1,2,7,9,3,4,5,10,4 };
//	int a1[] = { 6,1,7,6,6,6,4,9 };
//	int a2[] = { 3,2,3,3,3,3,2,3 };
//	int a3[] = { 2,2,2,2,2,2,2,2 };
//	PrintArray(a1, sizeof(a1) / sizeof(int));
//	KeyWayIndex kwi1 = PartSort3Way(a1, 0, sizeof(a1) / sizeof(int) - 1);
//	PrintArray(a1, sizeof(a1) / sizeof(int));
//	printf("3Way keyi:%d,%d\n\n", kwi1.leftKeyi, kwi1.rightKeyi);
//	PrintArray(a2, sizeof(a2) / sizeof(int));
//	KeyWayIndex kwi2 = PartSort3Way(a2, 0, sizeof(a2) / sizeof(int) - 1);
//	PrintArray(a2, sizeof(a2) / sizeof(int));
//	printf("3Way keyi:%d,%d\n\n", kwi2.leftKeyi, kwi2.rightKeyi);
//	PrintArray(a3, sizeof(a3) / sizeof(int));
//	KeyWayIndex kwi3 = PartSort3Way(a3, 0, sizeof(a3) / sizeof(int) - 1);
//	PrintArray(a3, sizeof(a3) / sizeof(int));
//	printf("3Way keyi:%d,%d\n\n", kwi3.leftKeyi, kwi3.rightKeyi);
//}
//int main()
//{
//	TestPartSort1();
//	TestPartSort2();
//	TestPartSort3();
//	return 0;
//}

//// �������ж����key��ȵ�ֵ
//int a[] = { 6,1,7,6,6,6,4,9 };
//int a[] = { 3,2,3,3,3,3,2,3 };
//// ������ȫ����ͬ��ֵ
//int a[] = { 2,2,2,2,2,2,2,2 };
//void QuickSortNonR(int* a, int left, int right)
//{
//	Stack st;
//	StackInit(&st);
//	StackPush(&st, left);
//	StackPush(&st, right);
//
//	while (StackEmpty(&st) != 0)
//	{
//		right = StackTop(&st);
//		StackPop(&st);
//		left = StackTop(&st);
//		StackPop(&st);
//
//		if (right - left <= 1)
//			continue;
//
//		int div = PartSort1(a, left, right);
//		// �Ի�׼ֵΪ�ָ�㣬�γ����������֣�[left, div) �� [div+1, right)
//		StackPush(&st, div + 1);
//		StackPush(&st, right);
//
//		StackPush(&st, left);
//		StackPush(&st, div);
//	}
//
//	StackDestroy(&s);
//}

//// ���谴�������array������[left, right)�����е�Ԫ�ؽ�������
//void QuickSort(int array[], int left, int right)
//{
//	if (right - left <= 1)
//		return;
//
//	// ���ջ�׼ֵ��array����� [left, right)�����е�Ԫ�ؽ��л���
//	int div = partion(array, left, right);
//
//	// ���ֳɹ�����divΪ�߽��γ������������� [left, div) �� [div+1, right)
//	// �ݹ���[left, div)
//	QuickSort(array, left, div);
//
//	// �ݹ���[div+1, right)
//	QuickSort(array, div + 1, right);
//}

//// ����ʵ�ֵĽӿ�
//// ��������
//void InsertSort(int* a, int n);
//// ϣ������
//void ShellSort(int* a, int n);
//// ѡ������
//void SelectSort(int* a, int n);
//// ������
//void AdjustDwon(int* a, int n, int root);
//void HeapSort(int* a, int n);
//// ð������
//void BubbleSort(int* a, int n)
//// ��������ݹ�ʵ��
//// ��������hoare�汾
//int PartSort1(int* a, int left, int right);
//// ���������ڿӷ�
//int PartSort2(int* a, int left, int right);
//// ��������ǰ��ָ�뷨
//int PartSort3(int* a, int left, int right);
//void QuickSort(int* a, int left, int right);
//// �������� �ǵݹ�ʵ��
//void QuickSortNonR(int* a, int left, int right)
//// �鲢����ݹ�ʵ��
//void MergeSort(int* a, int n)
//// �鲢����ǵݹ�ʵ��
//void MergeSortNonR(int* a, int n)
//// ��������
//void CountSort(int* a, int n)
//// ������������ܶԱ�
//void TestOP()
//{
//	srand(time(0));
//	const int N = 100000;
//	int* a1 = (int*)malloc(sizeof(int) * N);
//	int* a2 = (int*)malloc(sizeof(int) * N);
//	int* a3 = (int*)malloc(sizeof(int) * N);
//	int* a4 = (int*)malloc(sizeof(int) * N);
//	int* a5 = (int*)malloc(sizeof(int) * N);
//	int* a6 = (int*)malloc(sizeof(int) * N);
//	for (int i = 0; i < N; ++i)
//	{
//		a1[i] = rand();
//		a2[i] = a1[i];
//		a3[i] = a1[i];
//		a4[i] = a1[i];
//		a5[i] = a1[i]; 
//		a6[i] = a1[i];
//	}
//	int begin1 = clock();
//	InsertSort(a1, N);
//	int end1 = clock();
//	int begin2 = clock();
//	ShellSort(a2, N);
//	int end2 = clock();
//	int begin3 = clock();
//	SelectSort(a3, N);
//	int end3 = clock();
//	int begin4 = clock();
//	HeapSort(a4, N);
//	int end4 = clock();
//	int begin5 = clock();
//	QuickSort(a5, 0, N - 1);
//	int end5 = clock();
//	int begin6 = clock();
//	MergeSort(a6, N);
//	int end6 = clock();
//	printf("InsertSort:%d\n", end1 - begin1);
//	printf("ShellSort:%d\n", end2 - begin2);
//	printf("SelectSort:%d\n", end3 - begin3);
//	printf("HeapSort:%d\n", end4 - begin4);
//	printf("QuickSort:%d\n", end5 - begin5);
//	printf("MergeSort:%d\n", end6 - begin6);
//	free(a1);
//	free(a2);
//	free(a3);
//	free(a4);
//	free(a5);
//	free(a6);
//}

//typedef struct {
//    int head;
//    int tail;
//    int k;
//    int* arr;
//
//} MyCircularQueue;
//
//
//MyCircularQueue* myCircularQueueCreate(int k) {
//    MyCircularQueue* m1 = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//    m1->arr = (int*)malloc(sizeof(int) * (k + 1));
//    m1->k = k;
//    m1->head = m1->tail = 0;
//    return m1;
//}
//
//bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
//    return obj->head == obj->tail;
//}
//
//bool myCircularQueueIsFull(MyCircularQueue* obj) {
//    return ((obj->tail + 1) % (obj->k + 1)) == obj->head;
//}
//
//bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
//    if (!myCircularQueueIsFull(obj)) {
//        obj->arr[obj->tail] = value;
//        obj->tail = (obj->tail + 1) % (obj->k + 1);
//        return true;
//    }
//    else {
//        return false;
//    }
//
//}
//
//bool myCircularQueueDeQueue(MyCircularQueue* obj) {
//    if (!myCircularQueueIsEmpty(obj)) {
//        obj->head = (obj->head + 1) % (obj->k + 1);
//        return true;
//    }
//    else {
//        return false;
//    }
//}
//
//int myCircularQueueFront(MyCircularQueue* obj) {
//    if (myCircularQueueIsEmpty(obj)) {
//        return -1;
//    }
//    else {
//        return obj->arr[obj->head];
//    }
//}
//
//int myCircularQueueRear(MyCircularQueue* obj) {
//    if (myCircularQueueIsEmpty(obj)) {
//        return -1;
//    }
//    else {
//        return obj->arr[(obj->tail + obj->k) % (obj->k + 1)];
//    }
//}
//
//
//
//void myCircularQueueFree(MyCircularQueue* obj) {
//    free(obj->arr);
//    free(obj);
//}
//
///**
// * Your MyCircularQueue struct will be instantiated and called as such:
// * MyCircularQueue* obj = myCircularQueueCreate(k);
// * bool param_1 = myCircularQueueEnQueue(obj, value);
//
// * bool param_2 = myCircularQueueDeQueue(obj);
//
// * int param_3 = myCircularQueueFront(obj);
//
// * int param_4 = myCircularQueueRear(obj);
//
// * bool param_5 = myCircularQueueIsEmpty(obj);
//
// * bool param_6 = myCircularQueueIsFull(obj);
//
// * myCircularQueueFree(obj);
//*/
//��Ч����
//// ֧�ֶ�̬������ջ
//typedef int STDataType;
//
//typedef struct Stack
//{
//	STDataType* _a;
//	int _top;		// ջ��
//	int _capacity;  // ���� 
//}Stack;
//
//
//// ��ʼ��ջ 
//void StackInit(Stack* ps);
//
//// ��ջ 
//void StackPush(Stack* ps, STDataType data);
//
//// ��ջ 
//void StackPop(Stack* ps);
//
//// ��ȡջ��Ԫ�� 
//STDataType StackTop(Stack* ps);
//
//// ��ȡջ����ЧԪ�ظ��� 
//int StackSize(Stack* ps);
//
//// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0
//bool StackEmpty(Stack* ps);
//
//// ����ջ 
//void StackDestroy(Stack* ps);
//
//
//// ��ʼ��ջ 
//void StackInit(Stack* ps)
//{
//	assert(ps);
//
//	ps->_a = NULL;
//
//	// topָ��ջ�����ݵ���һ��λ��
//	ps->_top = 0;
//
//	// topָ��ջ������
//	//ps->_top = -1;
//
//	ps->_capacity = 0;
//}
//
//// ��ջ 
//void StackPush(Stack* ps, STDataType data)
//{
//	assert(ps);
//
//	//����
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
//
//		ps->_a = newnode;
//		ps->_capacity = newcapacity;
//	}
//
//	ps->_a[ps->_top] = data;
//	ps->_top++;
//}
//
//// ��ջ 
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
//// ��ȡջ��Ԫ�� 
//STDataType StackTop(Stack* ps)
//{
//
//	assert(ps);
//	assert(ps->_top > 0);
//
//	return ps->_a[ps->_top - 1];
//}
//
//// ��ȡջ����ЧԪ�ظ��� 
//int StackSize(Stack* ps)
//{
//	assert(ps);
//
//	return ps->_top;
//}
//
//// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
//bool StackEmpty(Stack* ps)
//{
//	assert(ps);
//
//	return ps->_top == 0;
//}
//
//// ����ջ 
//void StackDestroy(Stack* ps)
//{
//	assert(ps);
//
//	free(ps->_a);
//	ps->_a = NULL;
//	ps->_capacity = ps->_top = 0;
//}
//
//bool isValid(char* s) {
//	Stack st;
//	StackInit(&st);
//	while (*s != '\0')
//	{
//		if (*s == '{'
//			|| *s == '['
//			|| *s == '('
//			)
//		{
//			StackPush(&st, *s);
//			s++;
//		}
//		else
//		{
//			if ((StackEmpty(&st))
//				|| (StackTop(&st) == '(' && *s != ')')
//				|| (StackTop(&st) == '[' && *s != ']')
//				|| (StackTop(&st) == '{' && *s != '}'))
//			{
//				StackDestroy(&st);
//				return false;
//			}
//			else
//			{
//				StackPop(&st);
//				s++;
//			}
//
//		}
//	}
//	int ret = StackEmpty(&st);
//	StackDestroy(&st);
//	return ret;
//}
///**
// * Definition for a Node.
// * struct Node {
// *     int val;
// *     struct Node *next;
// *     struct Node *random;
// * };
// */
//typedef struct Node Node;
//struct Node* copyRandomList(struct Node* head) {
//    if (head == NULL)
//        return head;
//    Node* cur = head;
//    while (cur) {
//        Node* copy = (Node*)malloc(sizeof(Node));
//        copy->val = cur->val;
//        copy->next = cur->next;
//        cur->next = copy;
//        cur = copy->next;
//    }
//    cur = head;
//    while (cur) {
//        Node* copy = cur->next;
//        if (cur->random == NULL) {
//            copy->random = NULL;
//        }
//        else {
//            copy->random = cur->random->next;
//        }
//
//        cur = copy->next;
//    }
//    cur = head;
//    Node* newhead = head->next;
//    Node* newtail = head->next;
//    while (cur) {
//        Node* next = NULL;
//        if (newtail->next) {
//            next = newtail->next->next;
//        }
//        else {
//            next = NULL;
//        }
//        cur->next = newtail->next;
//        newtail->next = next;
//        cur = cur->next;
//        newtail = newtail->next;
//    }
//    return newhead;
//}
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//typedef struct ListNode ListNode;
//struct ListNode* detectCycle(struct ListNode* head) {
//    ListNode* slow = head;
//    ListNode* fast = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (slow == fast) {
//            ListNode* newhead = slow;
//            while (head != newhead) {
//                head = head->next;
//                newhead = newhead->next;
//            }
//            return head;
//        }
//    }
//    return NULL;
//}
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//typedef struct ListNode ListNode;
//bool hasCycle(struct ListNode* head) {
//    ListNode* slow = head;
//    ListNode* fast = head;
//    while (fast && fast->next) {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (fast == slow) {
//            return true;
//        }
//    }
//    return false;
//
//}
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//typedef struct ListNode ListNode;
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//    ListNode* l1 = headA;
//    ListNode* l2 = headB;
//    int lenA = 0;
//    int lenB = 0;
//
//    while (l1->next) {
//        l1 = l1->next;
//        lenA++;
//    }
//    while (l2->next) {
//        l2 = l2->next;
//        lenB++;
//    }
//    if (l1 != l2)
//    {
//        return false;
//    }
//    int gap = abs(lenA - lenB);
//    ListNode* shortlist = headA;
//    ListNode* longlist = headB;
//    if (lenA > lenB) {
//        longlist = headA;
//        shortlist = headB;
//    }
//    while (gap--) {
//        longlist = longlist->next;
//    }
//    while (longlist != shortlist) {
//        if (shortlist == NULL) {
//            return NULL;
//        }
//        shortlist = shortlist->next;
//        longlist = longlist->next;
//
//    }
//    return shortlist;
//}
///*
//struct ListNode {
//    int val;
//    struct ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};*/
//
//typedef struct ListNode ListNode;
//ListNode* Mid(ListNode* A) {
//    ListNode* fast = A;
//    ListNode* slow = A;
//    while (fast && fast->next) {
//        fast = fast->next;
//        slow = slow->next;
//    }
//    return slow;
//}
//
//ListNode* Reverse(ListNode* A) {
//
//    ListNode* l2 = A;
//    ListNode* l1 = NULL;
//    while (l2) {
//        ListNode* l3 = l2->next;
//        l2->next = l1;
//        l1 = l2;
//        l2 = l3;
//    }
//
//    return l1;
//}
//
//class PalindromeList {
//public:
//    bool chkPalindrome(ListNode* A) {
//        ListNode* newtail = Mid(A);
//        ListNode* newhead = Reverse(newtail);
//        ListNode* head = A;
//        while (head && newhead) {
//            if (head->val != newhead->val) {
//                return false;
//            }
//            head = head->next;
//            newhead = newhead->next;
//        }
//        return true;
//    }
//};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


//int kthToLast(struct ListNode* head, int k) {
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//    while (k--) {
//        fast = fast->next;
//    }
//    while (fast) {
//        fast = fast->next;
//        slow = slow->next;
//    }
//    return slow->val;
//}

//void rotate(int* nums, int numsSize, int k) {
//    int* arr = (int*)malloc(sizeof(int) * numsSize);
//    k %= numsSize;
//    memcpy(arr, nums + numsSize - k, sizeof(int) * k);
//    memcpy(arr + k, nums, sizeof(int) * (numsSize - k));
//    memcpy(nums, arr, sizeof(int) * numsSize);
//
//}

//void reverse(int* nums, int left, int right) {
//    while (left <= right) {
//        int tmp = nums[left];
//        nums[left] = nums[right];
//        nums[right] = tmp;
//        left++;
//        right--;
//    }
//}
//void rotate(int* nums, int numsSize, int k) {
//    k %= numsSize;
//    reverse(nums, numsSize - k, numsSize - 1);
//    reverse(nums, 0, numsSize - k - 1);
//    reverse(nums, 0, numsSize - 1);
//
//}

//int missingNumber(int* nums, int numsSize) {
//    int num = 0;
//    for (int i = 0; i <= numsSize; i++)
//    {
//        num ^= i;
//    }
//    for (int i = 0; i < numsSize; i++)
//    {
//        num ^= nums[i];
//    }
//    return num;
//}
//
//
//int missingNumber(int* nums, int numsSize) {
//    int num = 0;
//    for (int i = 0; i <= numsSize; i++)
//    {
//        num ^= i;
//    }
//    for (int i = 0; i < numsSize; i++)
//    {
//        num ^= nums[i];
//    }
//    return num;
//}


//int missingNumber(int* nums, int numsSize) {
//    int sum = 0;
//    for (int i = 0; i <= numsSize; i++)
//    {
//        sum += i;
//    }
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum -= nums[i];
//    }
//    return sum;
//}


//// ����׳˵ݹ�Fac�Ŀռ临�Ӷȣ�
//long long Fac(size_t N)
//{
//	if (N == 0)
//		return 1;
//
//	return Fac(N - 1) * N;
//}

//// ����Fibonacci�Ŀռ临�Ӷȣ�
//// ����쳲��������е�ǰn��
//long long* Fibonacci(size_t n)
//{
//	if (n == 0)
//		return NULL;
//
//	long long* fibArray = (long long*)malloc((n + 1) * sizeof(long long));
//	fibArray[0] = 0;
//	fibArray[1] = 1;
//	for (int i = 2; i <= n; ++i)
//	{
//		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
//	}
//
//	return fibArray;
//}

//// ����BubbleSort�Ŀռ临�Ӷȣ�
//void BubbleSort(int* a, int n)
//{
//	assert(a);
//	for (size_t end = n; end > 0; --end)
//	{
//		int exchange = 0;
//		for (size_t i = 1; i < end; ++i)
//		{
//			if (a[i - 1] > a[i])
//			{
//				Swap(&a[i - 1], &a[i]);
//				exchange = 1;
//			}
//		}
//
//		if (exchange == 0)
//			break;
//	}
//}
// ����Fibon
//// ����쳲������ݹ�Fib��ʱ�临�Ӷȣ�
//long long Fib(size_t N)
//{
//	if (N < 3)
//		return 1;
//
//	return Fib(N - 1) + Fib(N - 2);
//}

//// ����׳˵ݹ�Fac��ʱ�临�Ӷȣ�
//long long Fac(size_t N)
//{
//	if (0 == N)
//		return 1;
//
//	return Fac(N - 1) * N;
//}

//// ����BinarySearch��ʱ�临�Ӷȣ�
//int BinarySearch(int* a, int n, int x)
//{
//	assert(a);
//
//	int begin = 0;
//	int end = n - 1;
//	// [begin, end]��begin��end������ұ����䣬�����=��
//	while (begin <= end)
//	{
//		int mid = begin + ((end - begin) >> 1);
//		if (a[mid] < x)
//			begin = mid + 1;
//		else if (a[mid] > x)
//			end = mid - 1;
//		else
//			return mid;
//	}
//
//	return -1;
//}

//// ����BubbleSort��ʱ�临�Ӷȣ�
//void BubbleSort(int* a, int n)
//{
//	assert(a);
//	for (size_t end = n; end > 0; --end)
//	{
//		int exchange = 0;
//		for (size_t i = 1; i < end; ++i)
//		{
//			if (a[i - 1] > a[i])
//			{
//				Swap(&a[i - 1], &a[i]);
//				exchange = 1;
//			}
//		}
//
//		if (exchange == 0)
//			break;
//	}
//}


//// ����Func4��ʱ�临�Ӷȣ�
//void Func4(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 100; ++k)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}

//// ����Func3��ʱ�临�Ӷȣ�
//void Func3(int N, int M)
//{
//	int count = 0;
//	for (int k = 0; k < M; ++k)
//	{
//		++count;
//	}
//
//	for (int k = 0; k < N; ++k)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}

//long long Fib(int N)
//{
//	if (N < 3)
//		return 1;
//
//	return Fib(N - 1) + Fib(N - 2);
//}
//// ����Func2��ʱ�临�Ӷȣ�
//void Func2(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 2 * N; ++k)
//	{
//		++count;
//	}
//
//	int M = 10;
//	while (M--)
//	{
//		++count;
//	}
//
//	printf("%d\n", count);
//}

//// �����һ��Func1��++count����ܹ�ִ���˶��ٴΣ�
//void Func1(int N)
//{
//	int count = 0;
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			++count;
//		}
//	}
//
//	for (int k = 0; k < 2 * N; ++k)
//	{
//		++count;
//	}
//
//	int M = 10;
//	while (M--)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}

////���������Լɪ������
///**
// * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
// *
// *
// * @param n int����
// * @param m int����
// * @return int����
// */
//typedef struct ListNode ListNode;
//ListNode* CreateNode(int i)
//{
//    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
//    node->val = i;
//    node->next = NULL;
//    return node;
//}
//ListNode* CreateCircle(int n)
//{
//    ListNode* Head = CreateNode(1);
//    ListNode* Tail = Head;
//    for (int i = 2; i <= n; i++)
//    {
//        Tail->next = CreateNode(i);
//        Tail = Tail->next;
//    }
//    Tail->next = Head;
//    return Tail;
//}
//
//int ysf(int n, int m) {
//    ListNode* prev = CreateCircle(n);
//    ListNode* pcur = prev->next;
//    int count = 1;
//    while (pcur->next != pcur)
//    {
//        if (count == m)
//        {
//            prev->next = pcur->next;
//            free(pcur);
//            pcur = prev->next;
//            count = 1;
//        }
//        else
//        {
//            count++;
//            prev = pcur;
//            pcur = pcur->next;
//        }
//    }
//    int val = pcur->val;
//    free(pcur);
//    pcur = prev = NULL;
//    return val;
//}
//������ 02.04. �ָ�����
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//
//typedef struct ListNode ListNode;
//struct ListNode* partition(struct ListNode* head, int x) {
//    if (NULL == head)
//    {
//        return head;
//    }
//    ListNode* SmallHead, * BigHead, * SmallTail, * BigTail;
//    SmallHead = SmallTail = (ListNode*)malloc(sizeof(ListNode));
//    BigHead = BigTail = (ListNode*)malloc(sizeof(ListNode));
//    ListNode* pcur = head;
//    while (pcur != NULL)
//    {
//        if (pcur->val < x)
//        {
//            SmallTail->next = pcur;
//            SmallTail = SmallTail->next;
//        }
//        else
//        {
//            BigTail->next = pcur;
//            BigTail = BigTail->next;
//        }
//        pcur = pcur->next;
//    }
//    BigTail->next = NULL;
//    SmallTail->next = BigHead->next;
//    free(BigHead);
//    BigHead = NULL;
//
//    return SmallHead->next;
//}

///**21. �ϲ�������������
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//typedef struct ListNode ListNode;
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//    ListNode* l1 = list1;
//    ListNode* l2 = list2;
//    ListNode* newhead = NULL;
//    ListNode* newtail = NULL;
//    if (l1 == NULL)
//        return l2;
//    if (l2 == NULL)
//        return l1;
//
//    while (l1 && l2)
//    {
//        if (l1->val <= l2->val)
//        {
//            if (newtail == NULL)
//            {
//                newhead = newtail = l1;
//                l1 = l1->next;
//            }
//            else
//            {
//                newtail->next = l1;
//                newtail = newtail->next;
//                l1 = l1->next;
//            }
//        }
//        else
//        {
//            if (newtail == NULL)
//            {
//                newhead = newtail = l2;
//                l2 = l2->next;
//            }
//            else
//            {
//                newtail->next = l2;
//                newtail = newtail->next;
//                l2 = l2->next;
//            }
//        }
//    }
//    if (l1)
//        newtail->next = l1;
//    else
//        newtail->next = l2;
//
//    return newhead;
//
//}
////206. ��ת����
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//typedef struct ListNode ListNode;
//struct ListNode* reverseList(struct ListNode* head) {
//    if (head == NULL)
//    {
//        return head;
//    }
//    ListNode* n1 = NULL;
//    ListNode* n2 = head;
//    ListNode* n3 = head->next;
//    while (n2 != NULL)
//    {
//
//        n2->next = n1;
//        n1 = n2;
//        n2 = n3;
//        if (n2 != NULL)
//        {
//            n3 = n2->next;
//        }
//    }
//    return n1;
//
//}
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//typedef struct ListNode ListNode;
//struct ListNode* removeElements(struct ListNode* head, int val) {
//    ListNode* newhead = NULL;
//    ListNode* newtail = NULL;
//    ListNode* cur = head;
//    if (head == NULL)
//        return head;
//    while (cur != NULL)
//    {
//        if (cur->val != val)
//        {
//            if (newtail == NULL)
//            {
//                newtail = newhead = cur;
//            }
//            else
//            {
//                newtail->next = cur;
//                newtail = cur;
//            }
//
//        }
//        cur = cur->next;
//    }
//    if (newtail)
//    {
//        newtail->next = NULL;
//    }
//    return newhead;
//}
////876. ������м���
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//typedef struct ListNode ListNode;
//struct ListNode* middleNode(struct ListNode* head) {
//    ListNode* fast = head;
//    ListNode* slow = head;
//    if (head == NULL)
//        return head;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    return slow;
//}
////88. �ϲ�������������
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
//    int l3 = m + n - 1;
//    int l2 = n - 1;
//    int l1 = m - 1;
//    while (l1 >= 0 && l2 >= 0)
//    {
//        if (nums1[l1] < nums2[l2])
//        {
//            nums1[l3--] = nums2[l2--];
//        }
//        else
//        {
//            nums1[l3--] = nums1[l1--];
//        }
//    }
//    while (l2 >= 0)
//    {
//        nums1[l3--] = nums2[l2--];
//    }
//}
////27. �Ƴ�Ԫ��
//int removeElement(int* nums, int numsSize, int val) {
//    int src = 0;
//    int dst = 0;
//    while (src < numsSize)
//    {
//        if (nums[src] == val)
//        {
//            src++;
//        }
//        else
//        {
//            nums[dst] = nums[src];
//            dst++;
//            src++;
//        }
//    }
//    return dst;
//
//}
////������ 01.02.�ж��Ƿ�Ϊ�ַ�����
//bool CheckPermutation(char* s1, char* s2) {
//    int len1 = strlen(s1);
//    int len2 = strlen(s2);
//    if (len1 != len2)
//    {
//        return false;
//    }
//    int* S1 = calloc(26, sizeof(int));
//    int* S2 = calloc(26, sizeof(int));
//    for (int i = 0; i < len1; i++)
//    {
//        S1[s1[i] - 'a']++;
//        S2[s2[i] - 'a']++;
//    }
//
//    for (int i = 0; i < 26; i++)
//    {
//        if (S1[i] != S2[i])
//        {
//            return false;
//        }
//    }
//
//    return true;
//}
////������ 01.01.�ж��ַ��Ƿ�Ψһ
//bool isUnique(char* astr) {
//    int len = strlen(astr);
//    int* s = calloc(26, sizeof(int));
//    for (int i = 0; i < len; i++)
//    {
//        s[astr[i] - 'a']++;
//    }
//    for (int i = 0; i < 26; i++)
//    {
//        if (s[i] > 1)
//        {
//            return false;
//        }
//    }
//    return true;
//}
////NC31 ��һ��ֻ����һ�ε��ַ�
///**
// * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
// *
// *
// * @param str string�ַ���
// * @return int����
// */
// //��������
//int FirstNotRepeatingChar(char* str) {
//    int len = strlen(str);
//    int* S = calloc(26, sizeof(int));
//    int* s = calloc(26, sizeof(int));
//    for (int i = 0; i < len; i++)
//    {
//        if (isupper(str[i]))
//            S[str[i] - 'A']++;
//        else
//            s[str[i] - 'a']++;
//    }
//    for (int i = 0; i < len; i++)
//    {
//        if (isupper(str[i]))
//        {
//            if (S[str[i] - 'A'] == 1)
//                return i;
//        }
//        else
//        {
//            if (s[str[i] - 'a'] == 1)
//                return i;
//        }
//    }
//    return -1;
//}
////OR86 ����С�� N ����������
//#include <stdio.h>
//#include<math.h>
//
//int isZS(int n)
//{
//    int flag = 1;
//    for (int i = 2; i <= sqrt(n); i++)
//    {
//        if (n % i == 0)
//        {
//            flag = 0;
//            break;
//        }
//    }
//    return flag;
//}
//
//int main() {
//    int N;
//    while (scanf("%d", &N) != EOF) {
//        int count = 0;
//        for (int i = 2; i < N; i++)
//        {
//            count += isZS(i);
//        }
//        printf("%d\n", count);
//    }
//    return 0;
//}
////HJ99 ������
//#include <stdio.h>
//int Number(int a, int b)
//{
//    for (; b > 0;)
//    {
//        if (a % 10 != b % 10)
//        {
//            return 0;
//        }
//        a /= 10;
//        b /= 10;
//    }
//    return 1;
//}
//int main() {
//    int n;
//    while (scanf("%d", &n) != EOF) {
//        int count = 0;
//        for (int i = 0; i <= n; i++)
//        {
//            int num = i * i;
//            if (i == num)
//            {
//                count += 1;
//            }
//            else
//            {
//                count += Number(num, i);
//            }
//        }
//        printf("%d\n", count);
//    }
//    return 0;
//}
//#include <stdio.h>
//#include<math.h>
//
//int Number(int n)
//{
//    int count = 0;
//    if (n < 10)
//    {
//        count = 1;
//    }
//    else if (n < 100)
//    {
//        count = 2;
//    }
//    else if (n < 1000)
//    {
//        count = 3;
//    }
//    else if (n < 10000)
//    {
//        count = 4;
//    }
//    else
//    {
//        count = 5;
//    }
//    count = pow(10, count);
//    return count;
//}
//int main() {
//    int n;
//    while (scanf("%d", &n) != EOF) {
//        int count = 0;
//        for (int i = 0; i <= n; i++)
//        {
//            int a = Number(i);
//            int b = i * i;
//            if (a == b)
//            {
//                count++;
//            }
//            else if (b % a == i)
//            {
//                count++;
//            }
//        }
//        printf("%d\n", count);
//    }
//    return 0;
//}
//#include <stdio.h>
//
//int Number(int n)
//{
//    int count = 0;
//    for (; n > 0;)
//    {
//        if (n != 0)
//        {
//            count++;
//            n = n / 10;
//        }
//    }
//    return count;
//}
//int main() {
//    int n;
//    while (scanf("%d", &n) != EOF) {
//        int count = 0;
//        for (int i = 0; i <= n; i++)
//        {
//            int a = Number(i);
//            int b = i * i;
//            if (a == b)
//            {
//                count++;
//            }
//            else if (b % (a * 10) == i )
//            {
//                count++;
//            }
//        }
//        printf("%d", count);
//    }
//    return 0;
//}
//#include <stdio.h>
//
//int Number(int n)
//{
//    int count = 0;
//    for (; n > 0;)
//    {
//        if (n != 0)
//        {
//            count++;
//            n = n / 10;
//        }
//    }
//    return count;
//}
//int main() {
//    int n;
//    while (scanf("%d", &n) != EOF) {
//        int count = 0;
//        for (int i = 0; i <= n; i++)
//        {
//            int a = Number(i);
//            int b = i * i;
//            if (b == i % (a * 10))
//            {
//                count++;
//            }
//        }
//        printf("%d", count);
//    }
//    return 0;
//}
//#include <stdio.h>
//
//
//int main() {
//    int n;
//    while (scanf("%d", &n) != EOF) {
//        int count = 0;
//        for (int i = 0; i <= n; i++)
//        {
//            int b = i * i;
//            if (b % 10 == i % 10)
//            {
//                count++;
//            }
//        }
//        printf("%d", count);
//    }
//    return 0;
//}
// //��ȷ���Ķ���N
//#define N  4
//struct TreeNode
//{
//	int val;
//	struct TreeNode* subs[N];//�������齫���ӽڵ㴢������
//};

// ���û����ȷ���Ķ�
//struct TreeNode
//{
//	int val;
//	SeqList subs; // C��˳����ڲ���struct TreeNode*
//	//vector<struct TreeNode*> subs;//C++:
//};

//struct TreeNode
//{
//	int val;
//
//	struct TreeNode* leftchild;
//	struct TreeNode* rightBrother;
//};
///**���������
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* detectCycle(struct ListNode* head) {
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (slow == fast)
//        {
//            struct ListNode* meet = slow;
//            while (head != meet)
//            {
//                head = head->next;
//                meet = meet->next;
//            }
//            return meet;
//        }
//    }
//
//    return NULL;
//
//}
///**��������
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//bool hasCycle(struct ListNode* head) {
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (slow == fast)
//        {
//            return true;
//        }
//    }
//    return false;
//
//}
///**�ϲ�������������
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//    struct ListNode* line1 = list1;
//    struct ListNode* line2 = list2;
//    struct ListNode* newhead = NULL;
//    struct ListNode* newtail = NULL;
//    while (line1 && line2)
//    {
//        if (line1->val > line2->val)
//        {
//            if (newhead == NULL)
//            {
//                newhead = line2;
//                newtail = line2;
//                line2 = line2->next;
//            }
//            else
//            {
//                newtail->next = line2;
//                newtail = line2;
//                line2 = line2->next;
//            }
//
//        }
//        else
//        {
//            if (newhead == NULL)
//            {
//                newhead = line1;
//                newtail = line1;
//                line1 = line1->next;
//            }
//            else
//            {
//                newtail->next = line1;
//                newtail = line1;
//                line1 = line1->next;
//            }
//
//        }
//    }
//    while (line1)
//    {
//        if (newhead == NULL)
//        {
//            newhead = line1;
//            newtail = line1;
//            line1 = line1->next;
//        }
//        else
//        {
//            newtail->next = line1;
//            newtail = line1;
//            line1 = line1->next;
//        }
//
//    }
//    while (line2)
//    {
//        if (newhead == NULL)
//        {
//            newhead = line2;
//            newtail = line2;
//            line2 = line2->next;
//        }
//        else
//        {
//            newtail->next = line2;
//            newtail = line2;
//            line2 = line2->next;
//        }
//    }
//    return newhead;
//}

///**�ཻ����
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//    int len1 = 0;
//    int len2 = 0;
//    struct ListNode* shortline = headA;
//    struct ListNode* longline = headB;
//    struct ListNode* line1 = headA;
//    struct ListNode* line2 = headB;
//    while (line1)
//    {
//        line1 = line1->next;
//        len1++;
//    }
//    while (line2)
//    {
//        line2 = line2->next;
//        len2++;
//    }
//    if (len1 > len2)
//    {
//        shortline = headB;
//        longline = headA;
//    }
//    int count = abs(len2 - len1);
//    while (count--)
//    {
//        longline = longline->next;
//    }
//    while (shortline && longline)
//    {
//        if (shortline == longline)
//        {
//            return shortline;
//        }
//        shortline = shortline->next;
//        longline = longline->next;
//
//    }
//    return NULL;
//
//}
///**���ص�����K���ڵ�
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//
//
//int kthToLast(struct ListNode* head, int k) {
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
//    while (k--)
//    {
//        fast = fast->next;
//    }
//
//    while (fast)
//    {
//        fast = fast->next;
//        slow = slow->next;
//    }
//    return slow->val;
//}
//��ʧ������
//int missingNumber(int* nums, int numsSize) {
//    int n = 0;
//    for (int i = 1; i <= numsSize; i++)
//    {
//        n ^= i;
//    }
//    for (int i = 0; i < numsSize; i++)
//    {
//        n ^= nums[i];
//    }
//    return n;
//}
//��ת����
//void Inverse(int* nums, int left, int right)
//{
//    while (left < right)
//    {
//        int tmp = nums[left];
//        nums[left] = nums[right];
//        nums[right] = tmp;
//        left++;
//        right--;
//    }
//
//}
//
//void rotate(int* nums, int numsSize, int k) {
//    k %= numsSize;
//
//    Inverse(nums, 0, numsSize - k - 1);
//    Inverse(nums, numsSize - k, numsSize - 1);
//    Inverse(nums, 0, numsSize - 1);
//
//}


///**�Ƴ�����Ԫ��
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* removeElements(struct ListNode* head, int val) {
//    struct ListNode* newhead = NULL;
//    struct ListNode* cur = head;
//    struct ListNode* newtail = newhead;
//
//    while (cur)
//    {
//        if (cur->val != val)
//        {
//            if (newhead == NULL)
//            {
//                newhead = newtail = cur;
//            }
//            else
//            {
//                newtail->next = cur;
//                newtail = cur;
//            }
//        }
//        cur = cur->next;
//    }
//
//    if (newhead != NULL)
//        newtail->next = NULL;
//
//    return newhead;
//}


//int main()
//{
//	int a = 8;
//	a += a-=a * a;
//	return 0;
//}

//��ת����
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* reverseList(struct ListNode* head) {
//    struct ListNode* n2 = head;
//    struct ListNode* n1 = NULL;
//    if (head == NULL)
//    {
//        return NULL;
//    }
//    while (n2)
//    {
//        struct ListNode* n3 = n2->next;
//        n2->next = n1;
//        n1 = n2;
//        n2 = n3;
//    }
//
//    return n1;
//}
//�Ƴ�Ԫ��
//int removeElement(int* nums, int numsSize, int val) {
//    int* tmp = (int*)malloc(numsSize * sizeof(int));
//    int j = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] != val)
//        {
//            tmp[j++] = nums[i];
//        }
//    }
//    memcpy(nums, tmp, j * sizeof(int));
//    return j;
//}
//�ϲ�������������
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
//    int* tmp = (int*)malloc((m + n) * sizeof(int));
//    int i = 0;
//    int j = 0;
//    int k = 0;
//    while (i < m && j < n)
//    {
//        if (nums1[i] <= nums2[j])
//        {
//            tmp[k++] = nums1[i++];
//        }
//        else
//        {
//            tmp[k++] = nums2[j++];
//        }
//    }
//    while (i < m)
//    {
//        tmp[k++] = nums1[i++];
//    }
//    while (j < n)
//    {
//        tmp[k++] = nums2[j++];
//    }
//    memcpy(nums1, tmp, (m + n) * sizeof(int));
//}
//
////��ת������
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//struct TreeNode* invertTree(struct TreeNode* root) {
//    if (NULL == root)
//        return NULL;
//
//
//    struct TreeNode* tmp = root->left;
//    root->left = root->right;
//    root->right = tmp;
//
//
//    invertTree(root->left);
//    invertTree(root->right);
//
//
//    return root;
//}
//#include <stdio.h>
//
//
//typedef char BTDataType;
//
//
//typedef struct BinaryTreeNode
//{
//    BTDataType _data;
//    struct BinaryTreeNode* _left;
//    struct BinaryTreeNode* _right;
//}BTNode;
//
//
//BTNode* BuyNode(int x)
//{
//    BTNode* node = (BTNode*)malloc(sizeof(BTNode));
//    if (node == NULL)
//    {
//        perror("malloc fail");
//        return NULL;
//    }
//
//
//    node->_data = x;
//    node->_left = NULL;
//    node->_right = NULL;
//
//
//    return node;
//}
//
//
//
//BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
//{
//    BTNode* node = NULL;
//
//
//    if (a[*pi] == '#')
//    {
//        (*pi)++;
//        return NULL;
//    }
//
//
//    node = BuyNode(a[(*pi)++]);
//
//
//    node->_left = BinaryTreeCreate(a, n, pi);
//    node->_right = BinaryTreeCreate(a, n, pi);
//
//
//    return node;
//}
//
//
//// �������������
//void BinaryTreeInOrder(BTNode* root)
//{
//    if (root == NULL)
//    {
//        return;
//    }
//
//
//    BinaryTreeInOrder(root->_left);
//    printf("%c ", root->_data);
//    BinaryTreeInOrder(root->_right);
//}
//
//
//int main()
//{
//    char arr[100];
//    scanf("%s", arr);
//    int i = 0;
//    BTNode* root = BinaryTreeCreate(arr, sizeof(arr) / sizeof(arr[0]), &i);
//    BinaryTreeInOrder(root);
//
//
//}
///**��һ����������
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//
//    if (p == NULL && q == NULL)
//        return true;
//
//    if (p == NULL || q == NULL)
//        return false;
//
//    if (p->val != q->val)
//        return false;
//
//    return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
//}
//
//bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
//    if (root == NULL)
//        return false;
//
//    if (isSameTree(root, subRoot))
//        return true;
//
//    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
//}
///**�Գƶ�����
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool IsSymmetric(struct TreeNode* rootleft, struct TreeNode* rootright)
//{
//    if (rootleft == NULL && rootright == NULL)
//        return true;
//
//    if (rootleft == NULL || rootright == NULL)
//        return false;
//
//    if (rootleft->val != rootright->val)
//        return false;
//
//    return IsSymmetric(rootleft->left, rootright->right) && IsSymmetric(rootleft->right, rootright->left);
//
//}
//
//
//bool isSymmetric(struct TreeNode* root) {
//
//    return IsSymmetric(root->left, root->right);
//
//}

///**����������Ƿ����
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//
//
//    if (p == NULL && q == NULL)
//        return true;
//
//
//    if (p == NULL || q == NULL)
//        return false;
//
//
//    if (p->val != q->val)
//        return false;
//
//    return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
//}
//
///**�������
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
//int TreeSize(struct TreeNode* root)
//{
//
//    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
//}
//
//void PostOrder(struct TreeNode* root, int* arr, int* pi)
//{
//    if (root == NULL)
//        return;
//
//    PostOrder(root->left, arr, pi);
//    PostOrder(root->right, arr, pi);
//
//    arr[(*pi)++] = root->val;
//
//}
//
//int* postorderTraversal(struct TreeNode* root, int* returnSize) {
//    *returnSize = TreeSize(root);
//    int* arr = (int*)malloc(sizeof(int) * (*returnSize));
//    int i = 0;
//    PostOrder(root, arr, &i);
//
//    return arr;
//}

///**�������
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
//int TreeSize(struct TreeNode* root)
//{
//
//    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
//}
//
//void InOrder(struct TreeNode* root, int* arr, int* pi)
//{
//    if (root == NULL)
//        return;
//
//    InOrder(root->left, arr, pi);
//
//    arr[(*pi)++] = root->val;
//
//    InOrder(root->right, arr, pi);
//
//}
//
//int* inorderTraversal(struct TreeNode* root, int* returnSize) {
//    *returnSize = TreeSize(root);
//    int* arr = (int*)malloc(sizeof(int) * (*returnSize));
//    int i = 0;
//    InOrder(root, arr, &i);
//
//    return arr;
//}


/**��������ǰ�����
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
//int TreeSize(struct TreeNode* root)
//{
//
//    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
//}
//
//void PrevOrder(struct TreeNode* root, int* arr, int* pi)
//{
//    if (root == NULL)
//        return;
//
//    arr[(*pi)++] = root->val;
//
//    PrevOrder(root->left, arr, pi);
//    PrevOrder(root->right, arr, pi);
//
//}
//
//int* preorderTraversal(struct TreeNode* root, int* returnSize) {
//    *returnSize = TreeSize(root);
//    int* arr = (int*)malloc(sizeof(int) * (*returnSize));
//    int i = 0;
//    PrevOrder(root, arr, &i);
//
//    return arr;
//
//
//}
///**��������������
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
///**��ֵ������
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
//    if ((root->right != NULL && root->val != root->right->val) && (root->left != NULL && root->val != root->left->val))
//        return false;
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
//    TreeNode* n1 = CreateNode(2);
//    TreeNode* n2 = CreateNode(2);
//    TreeNode* n3 = CreateNode(2);
//    TreeNode* n4 = CreateNode(5);
//    TreeNode* n5 = CreateNode(2);
//    n1->left = n2;
//    n2->left = n4;
//    n2->right = n5;
//    n1->right = n3;
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
//// ֧�ֶ�̬������ջ
//typedef int STDataType;
//
//typedef struct Stack
//{
//	STDataType* _a;
//	int _top;		// ջ��
//	int _capacity;  // ���� 
//}Stack;
//// ��ʼ��ջ 
//void StackInit(Stack* ps)
//{
//	ps->_a = NULL;
//	ps->_capacity = ps->_top = 0;
//}
//
//// ��ջ 
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
//// ��ջ 
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
//// ��ȡջ��Ԫ�� 
//STDataType StackTop(Stack* ps)
//{
//
//	assert(ps);
//	assert(ps->_top > 0);
//
//	return ps->_a[ps->_top - 1];
//}
//
//// ��ȡջ����ЧԪ�ظ��� 
//int StackSize(Stack* ps)
//{
//	assert(ps);
//
//	return ps->_top;
//}
//
//// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
//bool StackEmpty(Stack* ps)
//{
//	assert(ps);
//	return ps->_top == 0;
//}
//
//// ����ջ 
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
//// ֧�ֶ�̬������ջ
//typedef int STDataType;
//
//typedef struct Stack
//{
//    STDataType* _a;
//    int _top;		// ջ��
//    int _capacity;  // ���� 
//}Stack;
//
//
//// ��ʼ��ջ 
//void StackInit(Stack* ps)
//{
//    ps->_a = NULL;
//    ps->_capacity = ps->_top = 0;
//}
//
//// ��ջ 
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
//// ��ջ 
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
//// ��ȡջ��Ԫ�� 
//STDataType StackTop(Stack* ps)
//{
//
//    assert(ps);
//    assert(ps->_top > 0);
//
//    return ps->_a[ps->_top - 1];
//}
//
//// ��ȡջ����ЧԪ�ظ��� 
//int StackSize(Stack* ps)
//{
//    assert(ps);
//
//    return ps->_top;
//}
//
//// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
//bool StackEmpty(Stack* ps)
//{
//    assert(ps);
//    return ps->_top == 0;
//}
//
//// ����ջ 
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




//�ö���ʵ��ջ
//#include<stdio.h>
//#include<assert.h>
//#include<stdlib.h>
//#include"stdbool.h"
//
//typedef int QDataType;
//
//// ��ʽ�ṹ����ʾ���� 
//typedef struct QListNode
//{
//	struct QListNode* _next;
//	QDataType _data;
//}QNode;
//
//// ���еĽṹ 
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
//// ��β����� 
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
//// ��ͷ������ 
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
//// ��ȡ����ͷ��Ԫ�� 
//QDataType QueueFront(Queue* q)
//{
//	assert(q);
//	assert(q->_size);
//
//	return q->_front->_data;
//}
//
//// ��ȡ���ж�βԪ�� 
//QDataType QueueBack(Queue* q)
//{
//	assert(q);
//	assert(q->_size);
//
//	return q->_rear->_data;
//
//}
//
//// ��ȡ��������ЧԪ�ظ��� 
//int QueueSize(Queue* q)
//{
//	assert(q);
//
//	return q->_size;
//}
//
//// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
//bool QueueEmpty(Queue* q)
//{
//	assert(q);
//
//	return q->_size == 0;
//}
//
//// ���ٶ��� 
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
//����ƥ��
//#include<stdlib.h>
//#include<stdbool.h>
//#include<assert.h>
//#include<stdio.h>


//// ֧�ֶ�̬������ջ
//typedef int STDataType;
//
//typedef struct Stack
//{
//	STDataType* _a;
//	int _top;		// ջ��
//	int _capacity;  // ���� 
//}Stack;
//
//// ��ʼ��ջ 
//void StackInit(Stack* ps)
//{
//	ps->_a = NULL;
//	ps->_capacity = ps->_top = 0;
//}
//
//// ��ջ 
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
//// ��ջ 
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
//// ��ȡջ��Ԫ�� 
//STDataType StackTop(Stack* ps)
//{
//
//	assert(ps);
//	assert(ps->_top > 0);
//
//	return ps->_a[ps->_top - 1];
//}
//
//// ��ȡջ����ЧԪ�ظ��� 
//int StackSize(Stack* ps)
//{
//	assert(ps);
//
//	return ps->_top;
//}
//
//// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ���0�������Ϊ�շ��ط�����
//bool StackEmpty(Stack* ps)
//{
//	assert(ps);
//	return ps->_top;
//}
//
//// ����ջ 
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
//		//��������ջ
//		if (*s == '(' || *s == '{' || *s == '[')
//		{
//			StackPush(&p, *s);
//		}
//		else//������ȡջ�������ų���ƥ��
//		{
//			if (!StackEmpty(&p))//ջ��û��������
//			{
//				StackDestroy(&p);
//				return false;
//			}
//			char top = 0;
//			top = StackTop(&p);//��ƥ��
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
//	int ret = !StackEmpty(&p);//ջ���Ƿ��ж���������
//	StackDestroy(&p);
//	return ret;
//}

////�������ĸ���
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
///**//��������II
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

//��������
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
// //�ཻ����
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

//����Ļ��Ľṹ
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

//ʵ��һ���㷨���ҳ����������е����� k ���ڵ㡣���ظýڵ��ֵ��
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
// ///**//�ϲ�������������
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


//Լɪ�����⻷������
///**
// * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
// *
// *
// * @param n int����
// * @param m int����
// * @return int����
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
//����ָ��Ѱ���м�ڵ�
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

 //�Ƴ�����Ԫ��
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