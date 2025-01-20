#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdlib.h>
//#include<string.h>
//#include<stdio.h>
//#include"stdbool.h"

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

//奇偶数
//class Solution {
//public:
//    bool isEvenOddTree(TreeNode* root) {
//        queue<TreeNode*> q;
//        q.push(root);
//        int level = 0;
//
//        while (!q.empty()) {
//            int size = q.size();
//            int prevVal = (level % 2 == 0) ? INT_MIN : INT_MAX; // 根据层级设置初始值
//            bool isEvenLevel = (level % 2 == 0); // 判断当前层级是否为偶数
//
//            for (int i = 0; i < size; ++i) {
//                TreeNode* node = q.front();
//                q.pop();
//
//                // 检查节点值是否符合当前层级的奇偶性要求
//                if (isEvenLevel && node->val % 2 == 0) return false; // 偶数层级应为奇数
//                if (!isEvenLevel && node->val % 2 != 0) return false; // 奇数层级应为偶数
//
//                // 检查节点值是否严格递增（偶数层级）或严格递减（奇数层级）
//                if ((isEvenLevel && node->val <= prevVal) || (!isEvenLevel && node->val >= prevVal)) {
//                    return false;
//                }
//                prevVal = node->val;
//
//                // 将子节点加入队列
//                if (node->left) q.push(node->left);
//                if (node->right) q.push(node->right);
//            }
//
//            ++level; // 移动到下一层级
//        }
//
//        return true; // 所有层级都符合偶奇树的要求
//    }
//};


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0, levelnum = 1;
        while (!q.empty()) {
            if (level % 2 == 0) {
                int tmp = INT_MIN;
                int n = levelnum;
                levelnum = 0;
                for (int i = 0; i < n; i++) {
                    if (q.front()->val % 2 == 0)
                        return false;
                    else {
                        if (tmp >= q.front()->val)
                            return false;
                        else {
                            tmp = q.front()->val;
                        }
                    }
                    if (q.front()->left) {
                        q.push(q.front()->left);
                    }
                    if (q.front()->right) {
                        q.push(q.front()->right);
                    }
                    q.pop();
                }
                levelnum = q.size();

            }
            else {
                int tmp = INT_MAX;
                int n = levelnum;
                levelnum = 0;
                for (int i = 0; i < n; i++) {
                    if (q.front()->val % 2 != 0)
                        return false;
                    else {
                        if (tmp <= q.front()->val)
                            return false;
                        else {
                            tmp = q.front()->val;
                        }
                    }
                    if (q.front()->left) {
                        q.push(q.front()->left);
                    }
                    if (q.front()->right) {
                        q.push(q.front()->right);
                    }
                    q.pop();
                }
                levelnum = q.size();
            }
            level++;
        }
        return true;
    }
};

int main() {

    TreeNode n1(5);
    TreeNode* p1 = &n1;
    TreeNode n2(4);
    TreeNode* p2 = &n2;
    TreeNode n3(2);
    TreeNode* p3 = &n3;
    TreeNode n4(3);
    TreeNode* p4 = &n4;
    TreeNode n5(3);
    TreeNode* p5 = &n5;
    TreeNode n6(7);
    TreeNode* p6 = &n6;
    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->left = p6;

    Solution().isEvenOddTree(p1);
    return 0;
}

//class Solution {
//public:
//    string sortSentence(string s) {
//        vector<string> arr(12);
//        string tmp;
//        for (auto ch : s) {
//            if (isdigit(ch)) {
//                arr[ch - '0' - 1] = tmp;
//                tmp.clear();
//            }
//            else if (ch != ' ') {
//                tmp += ch;
//            }
//        }
//        string ret;
//        for (auto ch : arr) {
//            ret += ch;
//            ret += " ";
//        }
//
//        return ret;
//    }
//};
//
//int main() {
//    string s = "is2 sentence4 This1 a3";
//
//    Solution().sortSentence(s);
//    return 0;
//}

//class Solution {
//public:
//    struct Compare{
//        void operator()(const string & a, const string & b) {
//            return a[a.size() - 1] < b[b.size() - 1];
//        }
//    };
//    string sortSentence(string s) {
//        vector<string> ret;
//        int prev = 0, pos = s.find(' ', 0);
//        while (pos != -1) {
//            string tmp = s.substr(prev, pos);
//            ret.push_back(tmp);
//            prev = pos + 1;
//            pos = s.find(' ', prev);
//        }
//        sort(ret.begin(), s.end(), Compare());
//        string s1;
//        for (int i = 0; i < ret.size(); i++) {
//            s1 += ret[i];
//        }
//        string s1;
//        for (int i = 0; i < s1.size(); i++) {
//            if (!isdigital(s1[i]))
//                s2 = s1[i] + ' ';
//        }
//        return s2;
//
//    }
//};
//class Solution {
//public:
//    int findLHS(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        int n = nums.size();
//        int ret = 0;
//        for (int left = 0, right = 0; right < n; right++)
//        {
//            while ((nums[right] - nums[left] != 1) && (left < right))
//            {
//                left++;
//            }
//
//            ret = max(ret, right - left);
//        }
//
//        return ret;
//    }
//};
//
//int main()
//{
//    vector<int> v = { 1,1,1,1 };
//    Solution().findLHS(v);
//    return 0;
//}


//
//
//struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};
//
//TreeNode* Buynode(int x)
//{
//    TreeNode* tmp = new TreeNode;
//    tmp->val = x;
//    tmp->left = nullptr;
//    tmp->right = nullptr;
//
//    return tmp;
//}
//
// 
//class Solution {
//public:
//    bool isEvenOddTree(TreeNode* root) {
//        queue<TreeNode*> q;
//        q.push(root);
//        int levelheight = 0;
//        int levelsize = q.size();
//        int flag = 0;
//        while (!q.empty())
//        {
//            TreeNode* front = q.front();
//            int com = front->val;
//            while (levelsize--)
//            {
//                front = q.front();
//                q.pop();
//                if (levelheight % 2 == 0)
//                {
//                    if (front->val % 2 == 0 || front->val < com)
//                        return false;
//                }
//                if (levelheight % 2 != 0)
//                {
//                    if (front->val % 2 != 0 || front->val > com)
//                        return false;
//                }
//
//                if (front->left)
//                {
//                    q.push(front->left);
//                }
//
//                if (front->right)
//                {
//                    q.push(front->right);
//                }
//            }
//
//            levelsize = q.size();
//            levelheight++;
//        }
//
//        return true;
//    }
//};
//
//int main()
//{
//    TreeNode* node1 = Buynode(1);
//    TreeNode* node2 = Buynode(10);
//    TreeNode* node3 = Buynode(4);
//    TreeNode* node4 = Buynode(3);
//    TreeNode* node5 = Buynode(7);
//    TreeNode* node6 = Buynode(9);
//    TreeNode* node7 = Buynode(12);
//    TreeNode* node8 = Buynode(8);
//    TreeNode* node9 = Buynode(6);
//    TreeNode* node10 = Buynode(2);
//    node1->left = node2;
//    node1->right = node2;
//    node2->left = node4;
//    node3->left = node5;
//    node3->right = node6;
//    node4->left = node7;
//    node4->right = node8;
//    node5->left = node9;
//    node6->right = node10;
//
//
//    Solution().isEvenOddTree(node1);
//    return 0;
//}

///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// * };
// */
//class Solution {
//public:
//    bool isEvenOddTree(TreeNode* root) {
//        queue q;
//        q.push(root);
//        int levelheight = 0;
//        int levelsize = 0;
//        int flag = 0;
//        while (!q.empty())
//        {
//            while (levelsize > 0)
//            {
//                TreeNode* front = q.front();
//                q.pop();
//                if (front->left)
//                {
//                    q.push(front->left);
//                }
//                if (front->right)
//                {
//                    q.push(front->right);
//                }
//            }
//        }
//    }
//};


///**题号: 1022.从根到叶的二进制数之和
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//void dfs(struct TreeNode* root, int num, int* psum) {
//    if (root == NULL) {
//        return;
//    }
//
//    num = (num << 1) + root->val;
//
//    if (root->left == NULL && root->right == NULL) {
//        *psum += num;
//        return;
//    }
//
//    dfs(root->left, num, psum);
//    dfs(root->right, num, psum);
//
//}
//
//int sumRootToLeaf(struct TreeNode* root) {
//    int sum = 0;
//    dfs(root, 0, &sum);
//    return sum;
//}


//从链表中删去总和值为零的连续节点
//struct ListNode {
//     int val;
//     struct ListNode *next;
//};
// 
//
//typedef struct ListNode ListNode;
//
//ListNode* BuyNode(int x) {
//    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
//    node->val = x;
//    node->next = NULL;
//
//    return node;
//}
//
//typedef struct ListNode ListNode;
//
//struct ListNode* removeZeroSumSublists(struct ListNode* head) {
//    ListNode* prev = (ListNode*)malloc(sizeof(ListNode));
//    prev->next = head;
//    ListNode* pcur = prev;
//    ListNode* cur = pcur->next;
//    int sum = 0;
//    while (pcur != NULL) {
//        cur = pcur->next;
//        if (pcur->val == 3) {
//            int i = 0;
//        }
//        sum = 0;
//        while (cur != NULL)
//        {
//            sum += cur->val;
//            if (sum == 0) {
//                ListNode* del = pcur->next;
//                pcur->next = cur->next;
//                cur = cur->next;
//                while (del != cur) {
//                    ListNode* tmp = del;
//                    del = del->next;
//                    free(tmp);
//                }
//            }
//            else {
//                cur = cur->next;
//            }
//        }
//        pcur = pcur->next;
//    }
//
//    return prev->next;
//}
//
//int main() {
//    ListNode* node1 = BuyNode(1);
//    ListNode* node2 = BuyNode(2);
//    ListNode* node3 = BuyNode(3);
//    ListNode* node4 = BuyNode(-3);
//    ListNode* node5 = BuyNode(4);
//    node1->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//    node4->next = node5;
//    removeZeroSumSublists(node1);
//
//    return 0;
//}

////LeetCode 题号 : 1614. 括号的最大嵌套深度
//int maxDepth(char* s) {
//    int premax = 0;
//    int nownum = 0;
//    char* cur = s;
//    while (*cur != '\0')
//    {
//        if (nownum > premax)
//        {
//            premax = nownum;
//        }
//        if (*cur == '(')
//        {
//            nownum++;
//        }
//        else if (*cur == ')') {
//            nownum--;
//        }
//        cur++;
//    }
//
//    return premax;
//}
//
//int main() {
//
//    maxDepth("(1+(2*3)+((8)/4))+1");
//
//    return 0;
//}


//int main() {
//    int n;
//    while (scanf("%d", &n) != EOF) {
//        int count = 0;
//        for (int i = 7; i < n; i++)
//        {
//            int m = i;
//            while (m)
//            {
//                if (i % 10 == 7 || i % 7 == 0)
//                {
//                    count++;
//                    break;
//                }
//                m /= 10;
//            }
//        }
//        printf("%d", count);
//    }
//    return 0;
//}

////面试题 08.05.递归乘法
//int multiply(int A, int B) {
//    int num = A;
//    for (int i = 1; i < B; i++)
//    {
//        A += num;
//    }
//    return A;
//}

////面试题 01.03.URL化
//char* replaceSpaces(char* S, int length) {
//    char* str1 = S;
//    char* str2 = (char*)malloc(10000000);
//    char* begin = str2;
//    int count = 0;
//    while (count < length)
//    {
//        if (count < length && *str1 == ' ')
//        {
//            *str2++ = '%';
//            *str2++ = '2';
//            *str2++ = '0';
//            str1++;
//            count++;
//        }
//        while (count < length && *str1 != ' ')
//        {
//            *str2++ = *str1++;
//            count++;
//        }
//    }
//
//    *str2 = '\0';
//    return begin;
//}
//char* replaceSpaces(char* S, int length) {
//    char* str1 = S;
//    char* str2 = (char*)malloc(10000000);
//    char* begin = str2;
//    int count = 0;
//    while (count < length)
//    {
//        if (*str1 == ' ')
//        {
//            *str2++ = '%';
//            *str2++ = '2';
//            *str2++ = '0';
//            str1++;
//            count++;
//        }
//        while (*str1 != ' ')
//        {
//            *str2++ = *str1++;
//            count++;
//        }
//    }
//
//    *str2 = '\0';
//    return begin;
//}
//
//int main()
//{
//    char S[100] = { "LqyuIZCuyRyvllekBuYNUZDrCzHCXeeUmZAfgIvHxzFgLCkLLzDBdfJh" };
//
//    replaceSpaces(S, 56);
//    return 0;
//}
////OR135 单词缩写
//#include <stdio.h>
//#include<string.h>
//
//int main() {
//    int n;
//    while (scanf("%d", &n) != EOF) {
//        char str[100];
//        while (scanf("%s", str) != EOF)
//        {
//            int len = strlen(str);
//            if (len < 10)
//            {
//                printf("%s", str);
//            }
//            else
//            {
//                printf("%c", str[0]);
//                printf("%d", len - 2);
//                printf("%c", str[len - 1]);
//            }
//            printf("%c", '\n');
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//#include<string.h>
//
//int main() {
//    int n;
//    while (scanf("%d", &n) != EOF) {
//        char str[100];
//        while (scanf("%s", str) != EOF)
//        {
//            int len = strlen(str);
//            if (len < 10)
//            {
//                printf("%s", str);
//            }
//            else
//            {
//                printf("%c", str[0]);
//                printf("%d", len - 2);
//                printf("%d", str[len - 1]);
//            }
//            printf("%c", '\n');
//        }
//    }
//    return 0;
//}
////面试题 01.04. 回文排列
//bool canPermutePalindrome(char* s) {
//    int len = strlen(s);
//    int flag = 0;
//    int* S = calloc(128, sizeof(int));
//    for (int i = 0; i < len; i++)
//    {
//        S[s[i] - 0]++;
//    }
//    for (int i = 0; i < 128; i++)
//    {
//        if (S[i] % 2 != 0)
//        {
//            flag++;
//        }
//    }
//    if (flag > 1)
//    {
//        return false;
//    }
//    return true;
//}
//面试题 01.02.判定是否互为字符重排
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
//    for (int i = 0; i < 26; i++)
//    {
//        if (S1[i] != S2[i])
//        {
//            return false;
//        }
//    }
//    return true;
//}
//
//bool canPermutePalindrome(char* s) {
//    int a = 0;
//    for (int i = 0; i < strlen(s); i++)
//    {
//        a ^= s[i];
//    }
//    if (a == 0)
//    {
//        return true;
//    }
//    for (int i = 0; i < strlen(s); i++)
//    {
//        if (a == s[i])
//        {
//            return true;
//        }
//    }
//    return false;
//}
//
//int main()
//{
//    char s[20];
//    scanf("%s",s);
//
//    canPermutePalindrome(s);
//    return 0;
//}