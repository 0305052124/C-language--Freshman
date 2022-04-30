#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define true 1
#define false 0
#define num 3

int count = 0;
int  isPowerOfThree(int n)
{
    if (n == 1) return true;
    else if (n == 0 || n / num * num != n) return false;
    else
    {
        count++;
        return isPowerOfThree(n / num);
    }
}

int main()
{
    int x = 0;
    scanf_s("%d", &x);
    if (isPowerOfThree(x))
        printf("整数%d是%d的%d次方\n", x, num, count);
    else printf("整数%d不是%d的幂次方\n", x, num);
}