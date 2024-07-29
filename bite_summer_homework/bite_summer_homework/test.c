#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"stdbool.h"


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