#define _CRT_SECURE_NO_WARNINGS 1

#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<stdio.h>
#include<string.h>



///**21. 合并两个有序链表
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
////206. 反转链表
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
////876. 链表的中间结点
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
////88. 合并两个有序数组
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
////27. 移除元素
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
////面试题 01.02.判定是否互为字符重排
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
////面试题 01.01.判定字符是否唯一
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
////NC31 第一个只出现一次的字符
///**
// * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
// *
// *
// * @param str string字符串
// * @return int整型
// */
// //计数排序
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
////OR86 返回小于 N 的质数个数
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
////HJ99 自守数
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
// //明确树的度是N
//#define N  4
//struct TreeNode
//{
//	int val;
//	struct TreeNode* subs[N];//开辟数组将孩子节点储存起来
//};

// 如果没有明确树的度
//struct TreeNode
//{
//	int val;
//	SeqList subs; // C：顺序表内部存struct TreeNode*
//	//vector<struct TreeNode*> subs;//C++:
//};

//struct TreeNode
//{
//	int val;
//
//	struct TreeNode* leftchild;
//	struct TreeNode* rightBrother;
//};
///**环形链表二
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
///**环形链表
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
///**合并两个有序链表
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

///**相交链表
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
///**返回倒数第K个节点
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
//消失的数字
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
//轮转数组
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


///**移除链表元素
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

//反转链表
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
//移除元素
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
//合并两个有序数组
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
////翻转二叉树
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
//// 二叉树中序遍历
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
///**另一个数的子树
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
///**对称二叉树
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

///**检查两棵树是否相等
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
///**后序遍历
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

///**中序遍历
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


/**二叉数的前序遍历
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