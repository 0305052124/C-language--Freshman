#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#define ture 1
#define false 0
int isPalindrome(int x)
{
    int s;
    long y = 0;
    s = x;
    while (s > 0)//yͨ��ѭ���洢���ǵ����x
    {
        y = y * 10 + s % 10;
        s = s / 10;
    }
    if (y == x)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{  
    int x = 0;
    scanf_s("%d", &x);
    if (isPalindrome(x))
        printf("%d�ǻ�����\n", x);
    else
        printf("%d���ǻ�����\n", x);
     return 0;
}
