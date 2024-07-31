#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"stdbool.h"

//
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