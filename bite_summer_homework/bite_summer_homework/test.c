#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"stdbool.h"



struct ListNode {
     int val;
     struct ListNode *next;
};
 

typedef struct ListNode ListNode;

ListNode* BuyNode(int x) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = x;
    node->next = NULL;

    return node;
}

typedef struct ListNode ListNode;

struct ListNode* removeZeroSumSublists(struct ListNode* head) {
    ListNode* prev = (ListNode*)malloc(sizeof(ListNode));
    prev->next = head;
    ListNode* pcur = prev;
    ListNode* cur = pcur->next;
    int sum = 0;
    while (pcur != NULL) {
        cur = pcur->next;
        while (cur != NULL)
        {
            sum += cur->val;
            if (sum == 0) {
                ListNode* del = prev->next;
                prev->next = cur->next;
                cur = cur->next;
                while (del != cur) {
                    ListNode* tmp = del;
                    del = del->next;
                    free(tmp);
                }
            }
            else {
                cur = cur->next;
            }
        }
        pcur = pcur->next;
    }

    return prev->next;
}

int main() {
    ListNode* node1 = BuyNode(1);
    ListNode* node2 = BuyNode(2);
    ListNode* node3 = BuyNode(-3);
    ListNode* node4 = BuyNode(3);
    ListNode* node5 = BuyNode(1);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    removeZeroSumSublists(node1);


}

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