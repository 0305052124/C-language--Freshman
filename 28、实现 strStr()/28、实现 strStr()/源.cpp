#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int strStr(char* haystack, char* needle)
{
    int n = strlen(haystack);
    int m = strlen(needle);
    for (int i = 0; i + m <= n; i++)
    {
        int flag = true;
        for (int j = 0; j < m; j++)
        {
            if (haystack[i + j] != needle[j])
            {
                flag = false;
                break;
            }
        }
        if (flag) return i;
    }
    return -1;
}
int main()
{
    char haystack[] = "hello";
    char needle[] = "ll";
    if (strStr(haystack, needle) == -1)
        printf("ÕÒ²»µ½\n");
    else
        printf("%d", strStr(haystack, needle));
    return 0;
}